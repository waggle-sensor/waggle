<!--
waggle_topic=/plugins_and_code
-->

# Image Detector Plugin
The plugin detects cars and pedestrians in a scene using Deep network architecture. The plugin runs every 5 minutes and sends detected object counts to Beehive. The name of the plugin is `image_car_ped_detector`. [OpenCV dnn](https://docs.opencv.org/3.4.1/d2/d58/tutorial_table_of_content_dnn.html) is actively used in the plugin when inferencing an image.

SSD mobilenet is used as backbone network and [COCO dataset](http://cocodataset.org/#home) was used when trained. Pre-trained graph was obtained from [OpenCV wiki](https://github.com/opencv/opencv/wiki/TensorFlow-Object-Detection-API). The model is able to detect various objects such as mouse, keyboard, horse, etc, but only `car` and `person` count on the plugin.

There are adjustable parameters when desired,
* `detection_interval` to control detection interval in second
* `sampling_interval` to control sampling interval (a sample means an image with detection result)
* `detection_confidence` to adjust confidence level (i.e., threshold) of detection

There are also adjustable parameters for pre-processing input image, when re-training or newly training model,
* `input_scale` to scale of input image
* `input_size` to define input size for network input
* `input_channel_order` to define channel order of input image
* `input_mean_subtraction` to adjust input image as a step of pre-processing

The parameters including above are defined in the plugin as,
```
def get_default_configuration():
    """ ssd_mobilenet_coco default set is in
        https://github.com/opencv/opencv/tree/master/samples/dnn
    """
    conf = {
        'source': 'bottom',
        'model': 'models/ssd_mobilenet_coco.pb',
        'model_desc': 'models/ssd_mobilenet_coco.pbtxt',
        'classes': 'models/ssd_mobilenet_coco.classes',
        'input_scale': 0.00784,
        'input_size': (300, 300),
        'input_mean_subtraction': (127.5, 127.5, 127.5),
        'input_channel_order': 'RGB',
        'detection_interval': 300,  # every 5 mins
        'sampling_interval': -1,  # None, by default
        'detection_confidence': 0.3,  # least detection confidence
    }
    return conf
```

### Sensor values
The values are count of each class (pedestrian and car), so it will look like this:
```
data time, node id, controlling device, sensor name, parameter name, raw data, human readable (converted) data
2019/06/12 00:14:55,001e06117b41,image,image_detector,car_total,NA,9
2019/06/12 00:14:55,001e06117b41,image,image_detector,person_total,NA,0
```

## How to train:
When you train the tensorflow model to add new classes or reinforce model, please refer [training](https://github.com/waggle-sensor/plugin_manager/blob/master/plugins/image_detector/training/README.md).

