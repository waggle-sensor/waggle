
<!--
waggle_topic=/plugins_and_code
-->

## Sound Pressure Level Calculation Plugin

The sound pressure level calcuation plugin reports surrounding noise level every 65 second *(1 minute interval, 5 seconds sampling)*. It samples audio data for 5 seconds from a microphone connected on edge-processor and calculates noise level in dBm. 

The sampled data (raw audio data collected through a microphone) can be recored (the argument ``'recording'`` in the configuration; ``True`` - Yes recording or ``False`` - No recording), but default is ``False`` -- not recording. When the audio sample is recorded, the format is pyaudio.paInt16, the number of channel is 1, sampling rate is 44100, each chunk length is 1024.

The sound pressure level estimation is based on Fourier Transformation. The data collected by the microphone is translated into frequency-intensity domain through Fourier Transformation. Among the frequency-intensity domain, frequency from 22 Hz to 22 kHz are seletected to calculate average dBm with given octave band. The full code is abailable from [here](https://github.com/waggle-sensor/plugin_manager/blob/master/plugins/audio_spl/spl.py).

There are adjustable parameters when desired,
* `sampling_period` to control length of sampling in second, default is 5 seconds
* `interval` to control calculation interval in second, default is 60 seconds
* `octave_band` to control octave band, default is 1/1 octave
* `recording` to control if the sample need to be saved or not, default is `false`

### Octave band

Octave band can be adjusted before the plugin is loaded on nodes by modifying configuration file (the argument ``'octave_band'`` in the configuration of the plugin; if octave_band = 1, then it is 1/1 octave, if octave_band = 3, then it is 1/3 octave, and so on). However the default is 1/1 octave. The plugin follows **Standard frequencies for acoustic measurements according to EN ISO 266** for 1/1 octave band and 1/3 octave band as showing in table at bottom. The plugin also supports other octave bands (such as 1/12 or 1/24).

### Result values

The frequency-intensity data are averaged for each octave band bins with accordance of configuration, and the average intesnity of each bin is translated into sound pressure level in dBm. Because default configuration of the plugin is 1/1 octave, it sends 10 values for each bin.

### References
To calculate average dBm for each bin and total sound pressure level, resources of [Adding acoustic levels of sound sources](http://www.sengpielaudio.com/calculator-spl.htm), [Combining Decibels − up to 30 s](http://www.sengpielaudio.com/calculator-spl30.htm), and [Adding decibels of one-third octave bands
to level of one octave band and vice versa](http://www.sengpielaudio.com/calculator-octave.htm) are used mostly. In addition, upper frequency for octave cycle is refered [here](https://courses.physics.illinois.edu/phys406/sp2017/Lab_Handouts/Octave_Bands.pdf).

### Sensor values
The values are packed into a string, so it will look like this:
```
data time, node id, controlling device, sensor name, parameter name, raw data, human readable (converted) data
2019/06/11 16:49:45,001e06117b41,nc,audio,spl,NA,"46.24, 35.12, 35.25, 35.26, 36.46, 47.57, 35.35, 45.37, 46.74, 35.45"
```

#### Center, lower, and upper frequencies for standard set of octave and 1/3 octave bands covering the audible frequency range.
<table>
  <tr>
    <th colspan="3">Octave Band</th>
    <th colspan="3">1/3 Octave Band</th>
  </tr>
  <tr>
    <td>Lower Frequency f1 (Hz)</td>
    <td>Center Frequency f0 (Hz)</td>
    <td>Upper Frequency f2 (Hz)</td>
    <td>Lower Frequency f1 (Hz)s</td>
    <td>Center Frequency f0 (Hz)</td>
    <td>Upper Frequency f2 (Hz)</td>
  </tr>
  <tr>
    <th rowspan="3"><span style="font-weight:normal">22</span></th>
    <th rowspan="3"><span style="font-weight:normal">31.5</span></th>
    <th rowspan="3"><span style="font-weight:normal">44</span></th>
    <td>22.4</td>
    <td>25</td>
    <td>28.2</td>
  </tr>
  <tr>
    <td>28.2</td>
    <td>31.5</td>
    <td>35.5</td>
  </tr>
  <tr>
    <td>35.5</td>
    <td>40</td>
    <td>44.7</td>
  </tr>
  
  <tr>
    <th rowspan="3"><span style="font-weight:normal">44</span></th>
    <th rowspan="3"><span style="font-weight:normal">63</span></th>
    <th rowspan="3"><span style="font-weight:normal">88</span></th>
    <td>44.7</td>
    <td>50</td>
    <td>56.2</td>
  </tr>
  <tr>
    <td>56.2</td>
    <td>63</td>
    <td>70.8</td>
  </tr>
  <tr>
    <td>70.8</td>
    <td>80</td>
    <td>89.1</td>
  </tr>
  
  <tr>
    <th rowspan="3"><span style="font-weight:normal">88</span></th>
    <th rowspan="3"><span style="font-weight:normal">125</span></th>
    <th rowspan="3"><span style="font-weight:normal">177</span></th>
    <td>89.1</td>
    <td>100</td>
    <td>112</td>
  </tr>
  <tr>
    <td>112</td>
    <td>125</td>
    <td>141</td>
  </tr>
  <tr>
    <td>141</td>
    <td>160</td>
    <td>178</td>
  </tr>
  
  <tr>
    <th rowspan="3"><span style="font-weight:normal">177</span></th>
    <th rowspan="3"><span style="font-weight:normal">250</span></th>
    <th rowspan="3"><span style="font-weight:normal">355</span></th>
    <td>178</td>
    <td>200</td>
    <td>224</td>
  </tr>
  <tr>
    <td>224</td>
    <td>250</td>
    <td>282</td>
  </tr>
  <tr>
    <td>282</td>
    <td>315</td>
    <td>355</td>
  </tr>
  
  <tr>
    <th rowspan="3"><span style="font-weight:normal">355</span></th>
    <th rowspan="3"><span style="font-weight:normal">500</span></th>
    <th rowspan="3"><span style="font-weight:normal">710</span></th>
    <td>355</td>
    <td>400</td>
    <td>447</td>
  </tr>
  <tr>
    <td>447</td>
    <td>500</td>
    <td>562</td>
  </tr>
  <tr>
    <td>562</td>
    <td>630</td>
    <td>708</td>
  </tr>
  
  <tr>
    <th rowspan="3"><span style="font-weight:normal">710</span></th>
    <th rowspan="3"><span style="font-weight:normal">1,000</span></th>
    <th rowspan="3"><span style="font-weight:normal">1,420</span></th>
    <td>708</td>
    <td>800</td>
    <td>891</td>
  </tr>
  <tr>
    <td>891</td>
    <td>1,000</td>
    <td>1,122</td>
  </tr>
  <tr>
    <td>1,122</td>
    <td>1,250</td>
    <td>1,413</td>
  </tr>
  
  <tr>
    <th rowspan="3"><span style="font-weight:normal">1,420</span></th>
    <th rowspan="3"><span style="font-weight:normal">2,000</span></th>
    <th rowspan="3"><span style="font-weight:normal">2,840</span></th>
    <td>1,413</td>
    <td>1,600</td>
    <td>1,778</td>
  </tr>
  <tr>
    <td>1,778</td>
    <td>2,000</td>
    <td>2,239</td>
  </tr>
  <tr>
    <td>2,239</td>
    <td>2,500</td>
    <td>2,818</td>
  </tr>
  
  <tr>
    <th rowspan="3"><span style="font-weight:normal">2,840</span></th>
    <th rowspan="3"><span style="font-weight:normal">4,000</span></th>
    <th rowspan="3"><span style="font-weight:normal">5,680</span></th>
    <td>2,818</td>
    <td>3,150</td>
    <td>3,548</td>
  </tr>
  <tr>
    <td>3,548</td>
    <td>4,000</td>
    <td>4,467</td>
  </tr>
  <tr>
    <td>4,467</td>
    <td>5,000</td>
    <td>5,623</td>
  </tr>
  
  <tr>
    <th rowspan="3"><span style="font-weight:normal">5,680</span></th>
    <th rowspan="3"><span style="font-weight:normal">8,000</span></th>
    <th rowspan="3"><span style="font-weight:normal">11,360</span></th>
    <td>5,623</td>
    <td>6,300</td>
    <td>7,079</td>
  </tr>
  <tr>
    <td>7,079</td>
    <td>8,000</td>
    <td>8,913</td>
  </tr>
  <tr>
    <td>8,913</td>
    <td>10,000</td>
    <td>11,220</td>
  </tr>
  
  <tr>
    <th rowspan="3"><span style="font-weight:normal">11,360</span></th>
    <th rowspan="3"><span style="font-weight:normal">16,000</span></th>
    <th rowspan="3"><span style="font-weight:normal">22,720</span></th>
    <td>11,220</td>
    <td>12,500</td>
    <td>14,130</td>
  </tr>
  <tr>
    <td>14,130</td>
    <td>16,000</td>
    <td>17,780</td>
  </tr>
  <tr>
    <td>17,780</td>
    <td>20,000</td>
    <td>22,390</td>
  </tr>
</table>

