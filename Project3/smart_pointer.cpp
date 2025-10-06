#include <iostream>
#include <memory>  // 包含智能指针头文件

int main() {
    // 示例1：智能指针基础（unique_ptr的基本操作）
    std::cout << "示例1：智能指针基础操作" << std::endl;
    int a = 25;                  // 栈上的局部变量
    std::unique_ptr<int> p;      // 声明int型智能指针（默认初始化为nullptr）
    
    // 智能指针不能直接指向栈变量，这里演示如何获取原始指针
    int* raw_ptr = &a;
    std::cout << "变量a的值：" << a << std::endl;
    std::cout << "变量a的地址：" << &a << std::endl;
    std::cout << "原始指针存储的地址：" << raw_ptr << std::endl;
    std::cout << "原始指针指向的值：" << *raw_ptr << std::endl;
    
    // 创建管理动态内存的智能指针
    p = std::make_unique<int>(a);  // 用a的值初始化堆上的int
    std::cout << "智能指针管理的值：" << *p << std::endl;
    std::cout << "智能指针存储的地址：" << p.get() << std::endl;  // get()获取原始指针
    std::cout << std::endl;


    // 示例2：智能指针与数组（unique_ptr管理数组）
    std::cout << "示例2：智能指针与数组" << std::endl;
    int arr[4] = {5, 10, 15, 20};  // 栈上的数组
    
    // 智能指针管理动态数组（注意指定数组类型）
    std::unique_ptr<int[]> arr_dyn = std::make_unique<int[]>(4);
    arr_dyn[0] = 5;
    arr_dyn[1] = 10;
    arr_dyn[2] = 15;
    arr_dyn[3] = 20;
    
    std::cout << "栈数组首元素：" << arr[0] << std::endl;
    std::cout << "智能指针管理的动态数组首元素：" << arr_dyn[0] << std::endl;
    std::cout << "通过指针访问arr_dyn[2]：" << *(arr_dyn.get() + 2) << std::endl;
    std::cout << std::endl;


    // 示例3：动态内存管理（智能指针自动释放）
    std::cout << "示例3：智能指针动态内存管理" << std::endl;
    // 1. 用unique_ptr管理单个int（堆上）
    auto p_dyn = std::make_unique<int>(100);  // make_unique安全创建智能指针
    std::cout << "堆上的动态变量值：" << *p_dyn << std::endl;

    // 2. 用shared_ptr共享所有权
    std::shared_ptr<int> sp1 = std::make_shared<int>(200);
    std::shared_ptr<int> sp2 = sp1;  // 共享所有权，引用计数变为2
    std::cout << "sp1管理的值：" << *sp1 << "，引用计数：" << sp1.use_count() << std::endl;
    std::cout << "sp2管理的值：" << *sp2 << std::endl;
    
    // 3. 转移unique_ptr的所有权
    auto p_dyn2 = std::move(p_dyn);  // p_dyn变为nullptr，p_dyn2获得所有权
    if (p_dyn == nullptr) {
        std::cout << "p_dyn已失去所有权" << std::endl;
    }
    std::cout << "p_dyn2管理的值：" << *p_dyn2 << std::endl;
    
    // 注意：智能指针无需手动释放，超出作用域会自动释放内存
    std::cout << std::endl;


    // 示例4：通过智能指针修改变量
    std::cout << "示例4：用智能指针修改变量" << std::endl;
    auto num_ptr = std::make_unique<int>(50);
    std::cout << "初始值：" << *num_ptr << std::endl;
    
    *num_ptr = 500;  // 通过智能指针修改值
    std::cout << "修改后的值：" << *num_ptr << std::endl;
    std::cout << std::endl;


    // 示例5：智能指针避免野指针问题
    std::cout << "示例5：智能指针避免野指针" << std::endl;
    std::unique_ptr<int> safe_ptr;  // 智能指针默认初始化为nullptr，不是野指针
    
    if (safe_ptr == nullptr) {
        std::cout << "safe_ptr初始状态为nullptr，不是野指针" << std::endl;
    }
    
    safe_ptr = std::make_unique<int>(10);  // 正确初始化
    std::cout << "初始化后的值：" << *safe_ptr << std::endl;
    std::cout << std::endl;


    // 示例6：智能指针避免悬垂指针
    std::cout << "示例6：智能指针避免悬垂指针" << std::endl;
    {
        auto temp_ptr = std::make_unique<int>(200);  // 作用域内的智能指针
        std::cout << "作用域内的值：" << *temp_ptr << std::endl;
    }  // temp_ptr超出作用域，自动释放内存，无需手动操作
    
    std::cout << "离开作用域后，内存已自动释放，不会产生悬垂指针" << std::endl;


    return 0;  // 所有智能指针超出作用域，自动释放管理的内存
}
