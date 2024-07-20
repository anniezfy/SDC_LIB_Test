## 1. Run the following code to install a SDC
1.Configure the  project

```shell
mkdir build

cd build

cmake ..

make
```

2. Install the library

 ```shell
cmake --install .
 ```
## 2. Build the external project
When building a project using SDC Library, `find_package()` command is provided in CMakeList.txt, and an explicit installation path of SDC library is provided 

```shell
mkdir build && cd build

cmake .. -DSDC_Lib="path_to/SDC_Lib/build/install/lib/cmakeSDC_LIB"

make
```

   