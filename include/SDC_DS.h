//
// Created by anniezfy on 2024/7/19.
//

#ifndef SDC_LIB_TEST_SDC_DS_H
#define SDC_LIB_TEST_SDC_DS_H
namespace PEA {
    template <typename T>
    class Vector {
    public:
        // 构造函数，接受一个整数参数用于初始化向量的大小
        Vector(size_t num) : data(num) {}

        // 成员变量，使用 std::vector 存储数据
        std::vector<T> data;
    };


}

#endif //SDC_LIB_TEST_SDC_DS_H
