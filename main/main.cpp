#include <iostream>
#include "../include/SDC_DS.h"
#include <complex>

int main() {
    // 使用模板类创建一个存储 float 类型的向量
    PEA::Vector<float> floatVector(5);
    floatVector.data = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};

    // 使用模板类创建一个存储 std::complex<float> 类型的向量
    PEA::Vector<std::complex<float>> complexVector(3);
    complexVector.data = {std::complex<float>(1.0, 1.0), std::complex<float>(2.0, 2.0), std::complex<float>(3.0, 3.0)};

    // 打印 floatVector 中的数据
    std::cout << "floatVector data:" << std::endl;
    for (const auto& val : floatVector.data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 打印 complexVector 中的数据
    std::cout << "complexVector data:" << std::endl;
    for (const auto& val : complexVector.data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}