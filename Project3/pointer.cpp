#include <iostream>

int main() {
    // 示例1：指针基础（声明、指向、解引用）
    std::cout << "示例1：指针基础操作" << std::endl;
    int a = 25;                  // 栈上的局部变量
    int* p;                      // 声明int型指针（未初始化时为野指针，危险）
    p = &a;                      // 指针p指向变量a的地址（&是取地址符）
    
    std::cout << "变量a的值：" << a << std::endl;
    std::cout << "变量a的地址：" << &a << std::endl;
    std::cout << "指针p存储的地址：" << p << std::endl;  // p保存a的地址，与&a相同
    std::cout << "指针p指向的值（*p）：" << *p << std::endl;  // *解引用，访问p指向的内容
    std::cout << "指针p自身的地址（&p）：" << &p << std::endl;  // p自己在栈上的地址
    std::cout << std::endl;


    // 示例2：指针与数组（指针运算、数组名的本质）
    std::cout << "示例2：指针与数组" << std::endl;
    int arr[4] = {5, 10, 15, 20};  // 栈上的数组
    int* p_arr = arr;              // 数组名是首元素地址，等价于p_arr = &arr[0]
    
    std::cout << "数组首元素值：" << arr[0] << "，指针访问：" << *p_arr << std::endl;
    p_arr++;  // 指针递增：地址偏移int类型大小（4字节），指向arr[1]
    std::cout << "指针p_arr++后指向的值：" << *p_arr << "（即arr[1]）" << std::endl;
    std::cout << "p_arr+1指向的值：" << *(p_arr + 1) << "（即arr[2]）" << std::endl;
    std::cout << "通过指针访问arr[3]：" << *(arr + 3) << std::endl;  // 数组名是常量指针
    std::cout << std::endl;


    // 示例3：动态内存分配（堆内存的申请与释放）
    std::cout << "示例3：动态内存操作" << std::endl;
    // 1. 动态分配单个int（堆上）
    int* p_dyn = new int(100);  // new在堆上分配内存，返回地址给p_dyn（p_dyn在栈上）
    std::cout << "堆上的动态变量值：" << *p_dyn << std::endl;

    // 2. 动态分配数组（堆上）
    int* arr_dyn = new int[3];  // 分配3个int的数组
    arr_dyn[0] = 10;
    arr_dyn[1] = 20;
    arr_dyn[2] = 30;
    std::cout << "堆上的动态数组：" << arr_dyn[0] << "," << arr_dyn[1] << "," << arr_dyn[2] << std::endl;

    // 3. 释放动态内存（必须手动执行，否则内存泄漏）
    delete p_dyn;       // 释放单个动态变量
    delete[] arr_dyn;   // 释放动态数组（必须用delete[]，与new[]配对）
    p_dyn = nullptr;    // 释放后置空，避免悬垂指针
    arr_dyn = nullptr;
    std::cout << std::endl;


    // 示例4：通过指针修改变量（模拟"传地址"效果）
    std::cout << "示例4：用指针修改变量" << std::endl;
    int num = 50;
    int* p_num = &num;  // 指针指向num
    *p_num = 500;       // 通过指针修改num的值
    std::cout << "修改后num的值：" << num << std::endl;  // 输出500
    std::cout << std::endl;


    // 示例5：错误示范1（野指针访问）
    std::cout << "示例5：错误示范（野指针）" << std::endl;
    int* wild_ptr;  // 未初始化的指针（野指针）
    // 注意：下面一行访问野指针是错误的，可能导致程序崩溃或输出随机值
    // std::cout << "野指针指向的值（危险）：" << *wild_ptr << std::endl;
    std::cout << "提示：未初始化的指针是野指针，禁止访问！" << std::endl;
    std::cout << std::endl;


    // 示例6：错误示范2（悬垂指针）
    std::cout << "示例6：错误示范（悬垂指针）" << std::endl;
    int* dangling_ptr = new int(200);  // 动态分配内存
    delete dangling_ptr;               // 释放内存
    // 此时dangling_ptr仍保存旧地址，但指向的内存已无效（悬垂指针）
    // 注意：下面一行访问悬垂指针是错误的，结果未定义
    // std::cout << "悬垂指针指向的值（危险）：" << *dangling_ptr << std::endl;
    dangling_ptr = nullptr;  // 释放后应置空，避免误用
    std::cout << "提示：释放内存后，指针需置为nullptr，避免悬垂指针！" << std::endl;


    return 0;
}