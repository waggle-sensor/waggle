//[*]--------------------------------------------------------------------------------------------------[*]
//
//  ODROID Board : ODROID FAN driver
//
//[*]--------------------------------------------------------------------------------------------------[*]
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/sysfs.h>
#include <linux/input.h>
#include <linux/gpio.h>
#include <linux/pwm.h>
#include <linux/delay.h>


#include <mach/gpio.h>
#include <mach/regs-gpio.h>
#include <plat/gpio-cfg.h>

//[*]--------------------------------------------------------------------------------------------------[*]
#define	DEBUG_PM_MSG
#include <linux/platform_data/odroidu2_fan.h>

extern unsigned long exynos_thermal_get_value(void);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/*
 * driver private data
 */
struct odroid_fan {
	struct odroid_fan_platform_data *pdata;
	struct pwm_device *pwm;
	struct delayed_work work;
	struct workqueue_struct *wq;

	unsigned int		pwm_status;
	struct mutex mutex;
	bool auto_mode;

	int period;
	int duty;
	int start_temp;
	int start_duty;
	int pwm_id;
};

//[*]------------------------------------------------------------------------------------------------------------------
//
// driver sysfs attribute define
//
//[*]------------------------------------------------------------------------------------------------------------------
static	ssize_t set_pwm_enable	(struct device *dev, struct device_attribute *attr, const char *buf, size_t count);
static	ssize_t show_pwm_status	(struct device *dev, struct device_attribute *attr, char *buf);
static	DEVICE_ATTR(pwm_enable, S_IRWXUGO, show_pwm_status, set_pwm_enable);

static	ssize_t set_pwm_duty	(struct device *dev, struct device_attribute *attr, const char *buf, size_t count);
static	ssize_t show_pwm_duty	(struct device *dev, struct device_attribute *attr, char *buf);
static	DEVICE_ATTR(pwm_duty, S_IRWXUGO, show_pwm_duty, set_pwm_duty);

static	ssize_t set_start_temp	(struct device *dev, struct device_attribute *attr, const char *buf, size_t count);
static	ssize_t show_start_temp	(struct device *dev, struct device_attribute *attr, char *buf);
static	DEVICE_ATTR(start_temp, S_IRWXUGO, show_start_temp, set_start_temp);

static	ssize_t set_start_duty	(struct device *dev, struct device_attribute *attr, const char *buf, size_t count);
static	ssize_t show_start_duty	(struct device *dev, struct device_attribute *attr, char *buf);
static	DEVICE_ATTR(start_duty, S_IRWXUGO, show_start_duty, set_start_duty);

static	ssize_t set_fan_mode	(struct device *dev, struct device_attribute *attr, const char *buf, size_t count);
static	ssize_t show_fan_mode	(struct device *dev, struct device_attribute *attr, char *buf);
static	DEVICE_ATTR(fan_mode, S_IRWXUGO, show_fan_mode, set_fan_mode);


static struct attribute *odroid_fan_sysfs_entries[] = {
	&dev_attr_pwm_enable.attr,
	&dev_attr_pwm_duty.attr,
	&dev_attr_start_temp.attr,
	&dev_attr_start_duty.attr,
	&dev_attr_fan_mode.attr,
	NULL
};

static struct attribute_group odroid_fan_attr_group = {
	.name   = NULL,
	.attrs  = odroid_fan_sysfs_entries,
};

//[*]------------------------------------------------------------------------------------------------------------------
//[*]------------------------------------------------------------------------------------------------------------------
static	ssize_t set_fan_mode (struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct odroid_fan *fan = dev_get_drvdata(dev);
	char str_mode[6];
	
	if(!(sscanf(buf, "%6s", str_mode)))
		return -EINVAL;
	
	if(!strcmp(str_mode, "auto"))
		fan->auto_mode = true;
	else
		fan->auto_mode = false;
	
	mutex_lock(&fan->mutex);

	fan->pwm_status = 1;
	pwm_disable(fan->pwm);
	pwm_config(fan->pwm, fan->duty * fan->period / 255, fan->period);
	pwm_enable(fan->pwm);

	mutex_unlock(&fan->mutex);
	
	if(fan->auto_mode)
		queue_delayed_work_on(0, fan->wq, &fan->work, usecs_to_jiffies(1000 * 1000));
	
	return count;
}

static	ssize_t show_fan_mode	(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct odroid_fan *fan = dev_get_drvdata(dev);
	if(fan->auto_mode)
		return sprintf(buf, "mode: auto\n");
	else
		return sprintf(buf, "mode: manual\n");

}

//[*]------------------------------------------------------------------------------------------------------------------
//[*]------------------------------------------------------------------------------------------------------------------
static	ssize_t set_pwm_enable	(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct odroid_fan *fan = dev_get_drvdata(dev);
	unsigned int	val;

    if(!(sscanf(buf, "%u\n", &val)))	
		return	-EINVAL;
	
	printk("PWM_0 : %s [%d] \n",__FUNCTION__,val);

	mutex_lock(&fan->mutex);
	
	if(val) {
    	fan->pwm_status = 1;
		pwm_disable(fan->pwm);
		pwm_config(fan->pwm, fan->duty * fan->period / 255, fan->period);
    	pwm_enable(fan->pwm);
    } else {
    	pwm_disable(fan->pwm);
		pwm_config(fan->pwm, 1, fan->period);
    	fan->pwm_status = 0;
    }
    
    mutex_unlock(&fan->mutex);
	
	return count;
}

static	ssize_t show_pwm_status	(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct odroid_fan *fan = dev_get_drvdata(dev);

	if(fan->pwm_status)	
		return	sprintf(buf, "PWM_0 : %s\n", "on");
	else					
		return	sprintf(buf, "PWM_0 : %s\n", "off");
}

//[*]------------------------------------------------------------------------------------------------------------------
//[*]------------------------------------------------------------------------------------------------------------------
static	ssize_t set_pwm_duty	(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct odroid_fan *fan = dev_get_drvdata(dev);
	unsigned int	val;

    if(!(sscanf(buf, "%u\n", &val)))	
		return	-EINVAL;

	if((val > 256)||(val < 0)){
		printk("PWM_0 : Invalid param. Duty cycle range is 0 to 255 \n");
		return count;
	}
	
	if(val == 0) val = 1;	
	
	fan->duty = val;

	mutex_lock(&fan->mutex);

    if(fan->pwm_status){
		pwm_disable(fan->pwm);
		pwm_config(fan->pwm, fan->duty * fan->period / 255, fan->period);
    	pwm_enable(fan->pwm);
    } else {
		pwm_disable(fan->pwm);
		pwm_config(fan->pwm, 1, fan->period);
    }

	mutex_unlock(&fan->mutex);
	
	return count;
}

static	ssize_t show_pwm_duty	(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct odroid_fan *fan = dev_get_drvdata(dev);

	return	sprintf(buf, "PWM_0 : Duty cycle -> %d (%d) \n", fan->duty, fan->duty * 100 / 255);
}


//[*]------------------------------------------------------------------------------------------------------------------
//[*]------------------------------------------------------------------------------------------------------------------
static	ssize_t set_start_temp	(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct odroid_fan *fan = dev_get_drvdata(dev);
	unsigned int	val;

	if(!(sscanf(buf, "%u\n", &val)))
		return	-EINVAL;

	if((val >= FAN_TEMP_THROTTLE)||(val < 0)){
		printk("PWM_0 : Invalid param. Start fan temperature range is 0 to %u \n", FAN_TEMP_THROTTLE - 1);
		return count;
	}

	if(val == 0) val = 1;
	fan->start_temp = val;
	return count;
}

static	ssize_t show_start_temp	(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct odroid_fan *fan = dev_get_drvdata(dev);

	return	sprintf(buf, "PWM_0 : Fan starting temperature -> %d \n", fan->start_temp);
}


//[*]------------------------------------------------------------------------------------------------------------------
//[*]------------------------------------------------------------------------------------------------------------------
static	ssize_t set_start_duty	(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct odroid_fan *fan = dev_get_drvdata(dev);
	unsigned int	val;

	if(!(sscanf(buf, "%u\n", &val)))
		return	-EINVAL;
	
	if((val > 256)||(val < 0)){
		printk("PWM_0 : Invalid param. Starting duty range is 0 to 255 \n");
		return count;
	}

	fan->start_duty = val;
	return count;
}

static	ssize_t show_start_duty	(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct odroid_fan *fan = dev_get_drvdata(dev);

	return	sprintf(buf, "PWM_0 : Fan starting duty -> %d \n", fan->start_duty);
}


//[*]--------------------------------------------------------------------------------------------------[*]
//[*]--------------------------------------------------------------------------------------------------[*]
static int	odroid_fan_resume(struct platform_device *dev)
{
	#if	defined(DEBUG_PM_MSG)
		printk("%s\n", __FUNCTION__);
	#endif

    return  0;
}

//[*]--------------------------------------------------------------------------------------------------[*]
static int	odroid_fan_suspend(struct platform_device *dev, pm_message_t state)
{
	return 0;
}

//[*]--------------------------------------------------------------------------------------------------[*]
void odroid_work(struct work_struct *work)
{
	struct odroid_fan *fan = container_of(work, struct odroid_fan, work.work);
	unsigned long temperature;
	
	/* check if its in auto-mode */
	if(!fan->auto_mode)
		return;
	
	temperature = exynos_thermal_get_value();
	
	mutex_lock(&fan->mutex);
	
	if(temperature < fan->start_temp) {
		pwm_disable(fan->pwm);
		pwm_config(fan->pwm, 1, fan->period);
		pwm_enable(fan->pwm);
		/* Set duty to zero.
		 * Otherwise it will stay at the last set entry.
		 */
		fan->duty = 0;
		mutex_unlock(&fan->mutex);
		queue_delayed_work_on(0, fan->wq, &fan->work, usecs_to_jiffies(1500 * 1000));
		return;
	}
	
	/* 83C is the first throttle.. 
	 * Lets not reach it
	 */
	fan->duty = 255 * (temperature - fan->start_temp) / (FAN_TEMP_THROTTLE - fan->start_temp);
	
	/* Check if duty is lower than start_duty.
	 * If yes, set it to start_duty.
	 * Lets the user set an at least value for duty.
	 */
	if(fan->duty < fan->start_duty) {
		fan->duty = fan->start_duty;
	}

	if(fan->pwm_status) {
		pwm_disable(fan->pwm);
		pwm_config(fan->pwm, fan->duty * fan->period / 255, fan->period);
		pwm_enable(fan->pwm);
	}
	
	mutex_unlock(&fan->mutex);
	
	/* poll each 1.5sec */
	queue_delayed_work_on(0, fan->wq, &fan->work, usecs_to_jiffies(1500 * 1000));
}

//[*]--------------------------------------------------------------------------------------------------[*]
static	int		odroid_fan_probe		(struct platform_device *pdev)	
{
	struct odroid_fan *fan;
	struct device 	*dev = &pdev->dev;
	int ret=0;

	if (!pdev->dev.platform_data) {
		dev_err(&pdev->dev, "pdata is not available\n");
		return -EINVAL;
	}

	fan = kzalloc (sizeof (struct odroid_fan), GFP_KERNEL);
	if (!fan)
		return -ENOMEM;
	fan->pdata = pdev->dev.platform_data;


	//pwm port pin_func init
	if (gpio_is_valid(fan->pdata->pwm_gpio)) {
		WARN_ON(gpio_request(fan->pdata->pwm_gpio, "pwm_gpio"));

		fan->pwm = pwm_request(fan->pdata->pwm_id, pdev->name);
		
		fan->period = fan->pdata->pwm_periode_ns;
		fan->duty = fan->pdata->pwm_duty;
		fan->start_temp = fan->pdata->pwm_start_temp;
		pwm_config(fan->pwm, fan->duty * fan->period / 255, fan->period);
		pwm_enable(fan->pwm);

		s3c_gpio_cfgpin(fan->pdata->pwm_gpio, fan->pdata->pwm_func);
		s5p_gpio_set_drvstr(fan->pdata->pwm_gpio, S5P_GPIO_DRVSTR_LV4);
		gpio_free(fan->pdata->pwm_gpio);
    }
	
	fan->pwm_status = 1;
	fan->auto_mode = true;
	
	mutex_init(&fan->mutex);

	fan->wq = create_freezable_workqueue("odroidu_fan_work");
	INIT_DELAYED_WORK(&fan->work, odroid_work);
	
	/*
	 * queue on cpu 0, always.. don't need to keep other cpu's alive because of this
	 */
	queue_delayed_work_on(0, fan->wq, &fan->work, usecs_to_jiffies(1000 * 1000));  
	
	dev_set_drvdata(dev, fan);


	ret = sysfs_create_group(&dev->kobj, &odroid_fan_attr_group);
	if(ret < 0)	{
		dev_err(&pdev->dev, "failed to create sysfs group !!\n");
	}

	return 0;
}

//[*]--------------------------------------------------------------------------------------------------[*]
static	int		odroid_fan_remove		(struct platform_device *pdev)	
{
    return	0;
}

//[*]--------------------------------------------------------------------------------------------------[*]
static struct platform_driver odroid_fan_driver = {
	.driver = {
		.name = "odroidu2-fan",
		.owner = THIS_MODULE,
	},
	.probe 		= odroid_fan_probe,
	.remove 	= odroid_fan_remove,
	.suspend	= odroid_fan_suspend,
	.resume		= odroid_fan_resume,
};

//[*]--------------------------------------------------------------------------------------------------[*]
static int __init odroid_fan_init(void)
{
    return platform_driver_register(&odroid_fan_driver);
}

//[*]--------------------------------------------------------------------------------------------------[*]
static void __exit odroid_fan_exit(void)
{
    platform_driver_unregister(&odroid_fan_driver);
}

//[*]--------------------------------------------------------------------------------------------------[*]
module_init(odroid_fan_init);
module_exit(odroid_fan_exit);

//[*]--------------------------------------------------------------------------------------------------[*]
MODULE_DESCRIPTION("FAN driver for odroid-Dev board");
MODULE_AUTHOR("Hard-Kernel");
MODULE_LICENSE("GPL");

//[*]--------------------------------------------------------------------------------------------------[*]
//[*]--------------------------------------------------------------------------------------------------[*]
