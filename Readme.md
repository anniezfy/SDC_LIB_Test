## 1. Install the SDC Library

1. **Configure the project**

    ```shell
    mkdir build

    cd build

    cmake ..

    make
    ```

2. **Install the library**

    ```shell
    cmake --install .
    ```

## 2. Build the External Project

When building a project that uses the SDC Library, include the `find_package()` command in your `CMakeLists.txt` and provide the explicit installation path of the SDC library:

    ```shell
    mkdir build && cd build

    cmake .. -DSDC_LIB_DIR="path_to/SDC_Lib/build/install/lib/cmake/SDC_LIB"

    make
    ```

### Revised Instructions

1. **Install the SDC Library**:
    - First, configure the project and generate build files:
      ```shell
      mkdir build
      cd build
      cmake ..
      make
      ```
    - Then, install the library:
      ```shell
      cmake --install .
      ```

2. **Build the External Project**:
    - In the `CMakeLists.txt` of the project that uses the SDC Library, include the `find_package(SDC_LIB REQUIRED)` command, and during the build process, provide the installation path of the SDC library:
      ```shell
      mkdir build && cd build
      cmake .. -DSDC_LIB_DIR="path_to/SDC_Lib/build/install/lib/cmake/SDC_LIB"
      make
      ```