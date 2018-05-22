<!--
waggle_topic=/data_analysis/datasets,"Sensor Datasets"
-->

### 1. Sensor Datasets:

The data aggregated by the Waggle based sensor nodes (AoT nodes, uglyboxes) are 
publicly available for download and use. The sensor datasets are updated and made 
available everday at midnight CST. A sensor dataset is provide as a tarball, with the 
following naming convention, 

```
<projectID>.latest.tar
```

The links for downloading the datasets are provided in the next section. 

Untaring the archive produces a folder - 

```    
<projectID>.YYYY-MM-DD
```

Here, YYYY-MM-DD is the UTC date when the tar archive was produced. 
Inside the folder a `gz` archive of sensor data and the following 
other meta-info are provided - 

```
data.csv.gz
nodes.csv  
README.md  
sensors.csv
provenance.csv
```

The sensor data uncompresses into [CSV form](https://en.wikipedia.org/wiki/Comma-separated_values), roughly about 10 times the 
size of the `gz` archive. 


### 2. Available Datasets: 

#### 2.1 AoT Chicago Public:
http://www.mcs.anl.gov/research/projects/waggle/downloads/datasets/AoT_Chicago.public.latest.tar
<br />
#### 2.2 AoT Chicago Complete:
http://www.mcs.anl.gov/research/projects/waggle/downloads/datasets/AoT_Chicago.complete.latest.tar
<br />
#### 2.3 GASP Complete:
http://www.mcs.anl.gov/research/projects/waggle/downloads/datasets/GASP.complete.latest.tar
<br />
#### 2.4 NUCWR-MUGS Complete: 
http://www.mcs.anl.gov/research/projects/waggle/downloads/datasets/NUCWR-MUGS.complete.latest.tar
<br />


### 3. Usage Example: 

1. Download the archive - 
```
$ wget http://www.mcs.anl.gov/research/projects/waggle/downloads/datasets/AoT_Chicago.complete.latest.tar
```

2. Untar the archive - 
```
$ tar -xf AoT_Chicago.complete.latest.tar
```

3. It should produce a directory - 
```
$ ls 
AoT_Chicago.complete.2018-05-22
AoT_Chicago.complete.latest.tar

```

4. Explore the README and other meta information - 
```
$ cd AoT_Chicago.complete.2018-05-22
$ ls 
data.csv.gz nodes.csv  provenance.csv   README.md  sensors.csv 
```

5. When ready, unpack the data archive. The archive decompressess to a 
CSV text file about 10 times its size -  

```
$ gzip -d --keep data.csv.gz
$ ls 
data.csv data.csv.gz nodes.csv  provenance.csv   README.md  sensors.csv 
```

This process can take several minutes and can be sped up by using 
parallel gzip (https://zlib.net/pigz/) -

```
$ pigz -d --keep data.csv.gz
$ ls 
data.csv data.csv.gz nodes.csv  provenance.csv   README.md  sensors.csv 
```
