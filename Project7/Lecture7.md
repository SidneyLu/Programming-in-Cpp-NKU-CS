# 南开大学 高级语言程序设计 Lecture 7

## 一、什么是模板？  
模板（Template）是C++泛型编程的基础，它允许我们**定义与类型无关的通用代码**，通过“参数化类型”实现一份代码处理多种数据类型（如`int`、`double`、自定义类等），避免重复编写相似逻辑。  

例如：  
- 无需为`int`、`double`、`string`分别编写`swap`（交换）函数，用模板可定义一个通用的`swap`模板，自动适配所有类型；  
- STL中的`vector`、`list`等容器能存储任意类型，正是通过类模板实现的。  


## 二、函数模板：通用函数的定义  
函数模板是“参数化类型”的函数，可作用于多种数据类型，语法如下：  

### 1. 基本语法  
```cpp
// 模板声明：typename（或class）表示类型参数，T是占位符（可自定义名称）
template <typename T>  
// 通用函数定义：用T代替具体类型
T 函数名(参数列表) {  
    // 函数逻辑（与类型无关）
}
```  

### 2. 示例：通用交换函数  
```cpp
#include <iostream>

// 函数模板：交换任意类型的两个变量
template <typename T>  // 声明模板，T为类型参数
void swap(T& a, T& b) {  // 用T作为参数类型
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    // 1. 用于int类型
    int x = 10, y = 20;
    swap(x, y);  // 自动实例化int版本：swap<int>(x, y)
    std::cout << "x=" << x << ", y=" << y << "\n";  // 输出：x=20, y=10

    // 2. 用于double类型
    double a = 3.14, b = 6.28;
    swap(a, b);  // 自动实例化double版本：swap<double>(a, b)
    std::cout << "a=" << a << ", b=" << b << "\n";  // 输出：a=6.28, b=3.14

    // 3. 用于自定义类型（如之前的Point类）
    class Point {
    public:
        int x, y;
        Point(int x=0, int y=0) : x(x), y(y) {}
    };
    Point p1(1,2), p2(3,4);
    swap(p1, p2);  // 自动实例化Point版本
    std::cout << "p1=(" << p1.x << "," << p1.y << ")\n";  // 输出：p1=(3,4)

    return 0;
}
```  


### 3. 模板实例化  
编译器会根据传入的参数类型，**自动生成对应类型的函数版本**，这个过程称为“模板实例化”：  
- 隐式实例化：如`swap(x, y)`，编译器根据`x`和`y`的类型（`int`）自动生成`swap<int>`；  
- 显式实例化：可手动指定类型，如`swap<int>(x, y)`（通常无需手动，编译器会自动推断）。  


## 三、类模板：通用类的定义  
类模板是“参数化类型”的类，可定义存储或处理任意类型数据的类（如容器类），语法如下：  

### 1. 基本语法  
```cpp
// 模板声明
template <typename T>  
class 类名 {  
private:  
    T 成员变量;  // 用T作为成员类型
public:  
    类名(参数列表);  // 构造函数
    T 成员函数(参数列表);  // 成员函数返回类型为T
};

// 类外定义成员函数（需重复模板声明）
template <typename T>  
类名<T>::类名(参数列表) {  
    // 构造逻辑
}

template <typename T>  
T 类名<T>::成员函数(参数列表) {  
    // 函数逻辑
}
```  



### 2. 类模板的使用要点  
- 定义对象时**必须显式指定类型**（如`DynamicArray<int> arr`），编译器无法像函数模板一样自动推断；  
- 成员函数在类外定义时，必须重复`template <typename T>`声明，并在类名后加`<T>`（如`DynamicArray<T>::~DynamicArray()`）；  
- 可包含多个类型参数（如`template <typename T1, typename T2>`），用于需要多种类型的场景（如键值对`pair<T1, T2>`）。  


## 四、模板特化：特殊类型的定制实现  
模板允许为**特定类型**提供定制化实现（特化），当需要对某类数据进行特殊处理时使用。  


### 1. 函数模板特化  
```cpp
#include <iostream>
#include <string>

// 通用模板：比较两个值是否相等
template <typename T>
bool isEqual(const T& a, const T& b) {
    return a == b;  // 适用于大多数类型
}

// 特化版本：处理const char*（字符串比较）
template <>  // 特化声明
bool isEqual<const char*>(const char* const& a, const char* const& b) {
    // 字符串需用strcmp比较，不能直接用==（否则比较的是地址）
    return std::strcmp(a, b) == 0;
}

int main() {
    int x = 5, y = 5;
    std::cout << isEqual(x, y) << "\n";  // 调用通用模板：输出1（true）

    const char* str1 = "hello";
    const char* str2 = "hello";
    std::cout << isEqual(str1, str2) << "\n";  // 调用特化版本：输出1（true）

    return 0;
}
```  


### 2. 类模板特化  
```cpp
#include <iostream>

// 通用模板：打印类型信息
template <typename T>
class TypePrinter {
public:
    void print() const {
        std::cout << "通用类型\n";
    }
};

// 特化版本：处理int类型
template <>
class TypePrinter<int> {
public:
    void print() const {
        std::cout << "这是int类型\n";
    }
};

// 特化版本：处理double类型
template <>
class TypePrinter<double> {
public:
    void print() const {
        std::cout << "这是double类型\n";
    }
};

int main() {
    TypePrinter<char> cPrinter;
    cPrinter.print();  // 调用通用模板：输出"通用类型"

    TypePrinter<int> iPrinter;
    iPrinter.print();  // 调用int特化：输出"这是int类型"

    return 0;
}
```  


## 五、非类型模板参数  
模板参数不仅可以是类型（`typename T`），还可以是**常量值**（如整数、指针、引用），称为“非类型模板参数”。  

### 示例：固定大小的数组模板  
```cpp
#include <iostream>

// 非类型参数N：数组大小（编译期常量）
template <typename T, int N>  // T是类型参数，N是非类型参数
class FixedArray {
private:
    T data[N];  // 大小为N的数组
public:
    // 赋值函数
    void set(int index, const T& value) {
        if (index < N) data[index] = value;
    }

    // 获取元素
    T get(int index) const {
        return (index < N) ? data[index] : T();
    }

    // 获取数组大小（编译期确定）
    int size() const { return N; }
};

int main() {
    // 定义大小为5的int数组
    FixedArray<int, 5> arr;
    for (int i = 0; i < arr.size(); i++) {
        arr.set(i, i * 10);
    }

    std::cout << "数组元素：";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr.get(i) << " ";  // 输出：0 10 20 30 40
    }

    return 0;
}
```  

**特点**：非类型参数必须是**编译期常量**（如`5`、`sizeof(int)`），不能是运行时变量。  

## 六、总结  
- 模板是C++泛型编程的核心，通过“参数化类型”实现通用代码；  
- 函数模板用于定义通用函数（如`swap`），类模板用于定义通用类（如`vector`）；  
- 模板特化允许为特定类型定制实现，非类型参数支持编译期常量；  
- 结合继承和多态，可实现灵活的泛型设计（如示例中的图形处理器）；  
- 理解模板是掌握STL的前提，STL的容器、算法几乎都是模板的典型应用。  

