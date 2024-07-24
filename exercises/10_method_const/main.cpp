#include "../exercise.h"
#include<iostream>
#include<cassert>
struct Fibonacci {
    int numbers[11];
    // TODO: 修改方法签名和实现，使测试通过
    Fibonacci(const int(&arr)[11]){
    for(int i=0;i<11;++i)
    {
        numbers[i]=arr[i];
    }
    }
    int get(int i) const{
        return numbers[i];
    }
};

int main(int argc, char **argv) {
    Fibonacci constexpr FIB{{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55}};
    assert(FIB.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << FIB.get(10) << std::endl;
    return 0;
}
