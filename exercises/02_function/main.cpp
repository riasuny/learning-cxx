#include <iostream>
#include <string>
int add(int a, int b);
// TODO: 在这里声明函数
void ASSERT(bool condition, const std::string& message)
{
    if (!condition) 
    {
        std::cout << message << std::endl;
        exit(1);
    }
}
    int main(int argc, char** argv) {
        ASSERT(add(123, 456) == 123 + 456, "add(123, 456) should be 123 + 456");

        auto x = 1, y = 2;
        std::cout << x << " + " << y << " = " << add(x, y) << std::endl;
        return 0;
    }

    int add(int a, int b) {
        // TODO: 补全函数定义，但不要移动代码行
        return a + b;
    }
