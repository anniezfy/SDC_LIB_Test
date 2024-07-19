# 添加可执行文件
add_executable(main main.cpp)

# 链接 PEA_Vector 库
target_link_libraries(main PRIVATE SDC_LIB)