#include <iostream>
#include <vector>


// 返回临时大对象（右值）
std::vector<int> createBigVector() {
    return std::vector<int>(10000, 1); // 含10000个元素的临时vector
}

int main() {
    int a = 10;
    int &ref_a = a; // 声明ref_a为a的引用（别名）

    // 特性1：操作引用 = 操作原变量
    std::cout << "初始：a=" << a << ", ref_a=" << ref_a << std::endl; // 均为10
    ref_a += 5; // 修改引用
    std::cout << "修改后：a=" << a << std::endl; // 输出15（原变量同步变化）

    // 特性2：引用与原变量地址相同（无独立内存）
    std::cout << "a的地址：" << &a << ", ref_a的地址：" << &ref_a << std::endl; // 地址完全一致

    // 错误示范：引用必须初始化 + 指向不可改
    // int &ref_empty; // 编译报错：引用未初始化
    // int b = 20;
    // ref_a = b; // 错误：并非更改指向，而是将b的值赋给a（ref_a仍绑定a）

    /*右值引用*/
    int&& ref = 10 + 20; // 绑定右值（30，临时结果）
    ref += 5; // 可修改临时值，其生命周期被延长
    std::cout << ref; // 输出35（临时值未销毁）

    // 右值引用绑定临时vector，直接接管其内存（无拷贝）
    std::vector<int>&& bigVec = createBigVector(); 
    // 直接使用，无需拷贝开销

    return 0;
}