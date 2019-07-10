### Features

Waggle features
- SA: Stand-alone device
- HB: Heatbeat to Wagman (via Serial)
- RO: Read-only root filesystem
- RSSH: Reverse SSH connection to Nodecontroller
- RCY: Waggle disk recovery to alternative media
- PIPE: Waggle data pipeline

Edge features
- TF: Tensorflow
- PyTorch: PyTorch
- CV: OpenCV
- Keras: Keras

Hardware features
- V: Voltage
- A: Ampere
- Power: Power consumption in Watt

__Acronyms :__

__C__: CPU, __G__: GPU, __T__: TPU, __V__: VPU

| Platform | SA | HB | RO | RSSH | RCY | PIPE | TF | PyTorch | CV | Keras | V | A | Power (W) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Odroid XU4 | O | O | O | O | O | O | __C__ | __C__ | __CG__ | __C__ | 5 | 4 | [10 - 20](https://magazine.odroid.com/wp-content/uploads/odroid-xu4-user-manual.pdf) |
| Nvidia TX2  | O | O | O | O | O  | O | __CG__ | __CG__ | __CG__ | __CG__ | 12 | 0.7 | [7.5 - 13](https://devblogs.nvidia.com/jetson-tx2-delivers-twice-intelligence-edge/) |
| Nvidia Nano  | O | O | Not tested | O | X | O | __CG__ | __CG__ | __CG__ | __CG__ | 5 | 1.5 |[5 - 10](https://developer.download.nvidia.com/assets/embedded/secure/jetson/Nano/docs/NVIDIA_Jetson_Nano_Developer_Kit_User_Guide.pdf?vCf9m7nnlrnNDDU1wA0o0TN-kxNAnVRjKoykuuLvVmZcqDHeem9Bv3g4XBkWl1t1ZGTLMNl2awUstCw6oGAvlcm1OBoW7Itt2qVHVRj8ic41DGxePEt7xDAya0_X_j2Yh7xfcqHw0sXMqOIuo_yUH0407lofjnEoW9-Mk1ZiPC1g-vgMXkjcvvna7yT5CF2SCTfrA4M1) |
| Coral ETPU  | O | O | Not tested | O | Not tested | O | __CGT__ | __CGT__ | __CGT__ | __CGT__ | 5 | 2.5 | [10 - 15](https://coral.withgoogle.com/docs/dev-board/datasheet/#system-power) |
| Intel Stick with XU4  | - | O | O | O | O | O | __CV__ | __C__ | __CGV__ | __CV__ | 5 | 3 | 10 - 20 |
