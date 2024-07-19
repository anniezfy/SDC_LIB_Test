cmake_minimum_required(VERSION 3.10)
# 设置C++标准为C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# 设置项目名称和版本
project(SDC_LIB VERSION 1.0)

# 设置库的输出路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 添加库头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 添加子目录
add_subdirectory(main)

# 设置库的安装路径
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)

# 添加库目标
add_library(SDC_LIB INTERFACE)

# 由于是模板类，将头文件作为库的一部分安装
include(GNUInstallDirs)
target_include_directories(SDC_LIB INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# 安装头文件
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# 安装库目标
install(TARGETS SDC_LIB EXPORT SDC_LIBTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

# 安装导出目标
install(EXPORT SDC_LIBTargets
        FILE SDC_LIBTargets.cmake
        NAMESPACE SDC::
        DESTINATION lib/cmake/SDC_LIB
)

# 配置文件生成
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/SDC_LIBConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
)

# 配置安装
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/SDC_LIBConfig.cmake.in
        "${CMAKE_CURRENT_BINARY_DIR}/SDC_LIBConfig.cmake"
        @ONLY
)

# 安装配置文件
install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/SDC_LIBConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/SDC_LIBConfigVersion.cmake"
        DESTINATION lib/cmake/SDC_LIB
)