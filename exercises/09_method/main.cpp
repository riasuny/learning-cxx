#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128]={0,1};
    int cached=1;

    // TODO: 实现正确的缓存优化斐波那契计算
    unsigned long long get(int i) {
        Fibonacci c;
        for (; c.cached<=i; ++c.cached) {
            c.cache[c.cached] = c.cache[c.cached - 1] + c.cache[c.cached - 2];
        }
        return c.cache[i];
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib;
    fib.cached=2;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
