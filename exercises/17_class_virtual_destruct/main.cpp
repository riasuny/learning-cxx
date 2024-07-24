#include<iostream>
#include <cassert> // 引入 assert 头文件
#define ASSERT(condition, message) assert(condition && message)
// 前向声明
struct A;
struct B;

// 结构定义
struct A {
    static int num_a;

    A() {
        ++num_a;
    }
    virtual ~A() {
        --num_a;
    }

    virtual char name() const {
        return 'A';
    }
};

struct B : public A {
    static int num_b;

    B() {
        ++num_b;
    }
    ~B() {
        --num_b;
    }

    char name() const override {
        return 'B';
    }
};

// 静态成员变量初始化
int A::num_a = 0;
int B::num_b = 0;

// 主函数
int main() {
    A* a = new A;
    B* b = new B;

    assert(A::num_a == 1 && "Incorrect value for A::num_a");
    assert(B::num_b == 1 && "Incorrect value for B::num_b");
    assert(a->name() == 'A' && "Incorrect value for a->name()");
    assert(b->name() == 'B' && "Incorrect value for b->name()");

    delete a;
    delete b;

    assert(A::num_a == 0 && "Not all A objects were destroyed");
    assert(B::num_b == 0 && "Not all B objects were destroyed");

    A* ab = new B; // 可以将派生类指针转换为基类指针

    assert(A::num_a == 1 && "Incorrect value for A::num_a");
    assert(B::num_b == 1 && "Incorrect value for B::num_b");
    assert(ab->name() == 'B' && "Incorrect value for ab->name()");

    // 使用 dynamic_cast 进行基类指针到派生类引用的转换
    B* bb = dynamic_cast<B*>(ab);
    assert(bb != nullptr && "Failed to cast ab to B*");
    assert(bb->name() == 'B' && "Incorrect value for bb->name()");

    delete ab;

    assert(A::num_a == 0 && "Not all A objects were destroyed");
    assert(B::num_b == 0 && "Not all B objects were destroyed");

    std::cout << "All assertions passed successfully." << std::endl;

    return 0;
}

