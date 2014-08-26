/*
 * Copyright (C) 2011 Samsung Electronics Co.Ltd
 * Author: Joonyoung Shim <jy0922.shim@samsung.com>
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 */

#ifndef __PLAT_SAMSUNG_EHCI_H
#define __PLAT_SAMSUNG_EHCI_H __FILE__

struct s5p_ehci_platdata {
	int (*phy_init)(struct platform_device *pdev, int type);
	int (*phy_exit)(struct platform_device *pdev, int type);
	int (*phy_suspend)(struct platform_device *pdev, int type);
	int (*phy_resume)(struct platform_device *pdev, int type);
};

extern void s5p_ehci_set_platdata(struct s5p_ehci_platdata *pd);

#ifdef CONFIG_USB_EXYNOS_SWITCH
struct s5p_usbswitch_platdata {
	unsigned gpio_host_detect;
	unsigned gpio_device_detect;
	unsigned gpio_host_vbus;

	struct device *ehci_dev;
	struct device *ohci_dev;
	struct device *s3c_hsotg_dev;
};

extern void s5p_usbswitch_set_platdata(struct s5p_usbswitch_platdata *pd);
#endif /* CONFIG_USB_EXYNOS_SWITCH */

#endif /* __PLAT_SAMSUNG_EHCI_H */
