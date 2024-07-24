#include <iostream>
#include <cassert> // 包含标准的断言宏 assert

struct FibonacciCache {
    unsigned long long cache[16] = {0, 1}; // 初始斐波那契数列的前两个数
    int cached = 1; // 初始缓存的数的个数
};

// 实现缓存优化斐波那契计算
static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    // 如果需要计算的数超过当前缓存的范围，则继续计算
    for (; i >= cache.cached; ++cache.cached) {
        cache.cache[cache.cached] = cache.cache[cache.cached - 1] + cache.cache[cache.cached - 2];
    }
    return cache.cache[i];
}

int main(int argc, char **argv) {
    FibonacciCache fib;
    fib.cached = 2; // 初始已缓存的数为 2，即斐波那契数列的前两个数已经计算
    
    assert(fibonacci(fib, 10) == 55 && "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    
    return 0;
}