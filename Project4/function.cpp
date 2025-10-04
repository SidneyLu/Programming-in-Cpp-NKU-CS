#include <iostream>

// 1. 函数声明（提前告诉编译器函数结构）
int add(int a, int b); 

// 2. 函数定义（实现求和逻辑）
int add(int a, int b) {
    int sum = a + b;
    return sum; // 返回值类型与声明的int匹配
}

// 声明：无返回值（void）
void printEven(int num); 

// 定义：判断并打印奇偶性
void printEven(int num) {
    if (num % 2 == 0) {
        std::cout << num << "是偶数\n";
    } else {
        std::cout << num << "是奇数\n";
    }
    // 无return语句（void类型可省略）
}

// 声明：无参数，返回int
int getFixedValue(); 

// 定义：无参数，直接返回固定值
int getFixedValue() {
    return 100;
}  

/*默认参数*/
// 声明：b的默认值为10（左参数a无默认，右参数b有默认）
int addDefault(int a, int b = 10); 

int addDefault(int a, int b) {
    return a + b;
}

/*函数重载*/
// 重载1：三个int参数（个数不同）
int add(int a, int b, int c) { return a + b + c; }

// 重载2：两个double参数（类型不同）
double add(double a, double b) { return a + b; }


/*传入数组*/
// 形参写int arr[] 或 int* arr 均可（数组名本质是指针常量）
void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

/*传入引用*/
// 引用参数：x是外部变量的别名
void addOne(int &x) {
    x += 1;
}//传值只会创建一个副本，不会改变原变量

/*传入指针*/
// 指针实现（需解引用，稍复杂）
void addTwo(int *x) {
    *x += 2;
}


/*函数指针*/
// 定义四则运算函数
// int add(int a, int b) { return a + b; } Add之前已经定义过
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int main() {
    int (*calc_ptr)(int, int); // 函数指针：指向运算函数
    int a = 10, b = 2, choice, result;

    // 输入选择运算类型
    std::cout << "请选择运算（1-加，2-减，3-乘，4-除）：";
    std::cin >> choice;

    // 根据选择切换函数指针指向
    switch (choice) {
        case 1: calc_ptr = add; break;
        case 2: calc_ptr = subtract; break;
        case 3: calc_ptr = multiply; break;
        case 4: calc_ptr = divide; break;
        default: std::cout << "选择错误！"; return 1;
    }

    // 统一调用函数指针，实现动态运算
    result = calc_ptr(a, b);
    std::cout << "结果：" << result << std::endl;

    return 0;
}