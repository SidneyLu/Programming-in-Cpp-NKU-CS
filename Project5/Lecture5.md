# 南开大学 高级语言程序设计 Lecture 5

## 一、什么是类与对象？  
**类（Class）** 是对现实世界中某类事物的**抽象描述**，包含这类事物的**属性**（数据）和**行为**（操作）。  
**对象（Object）** 是类的**具体实例**，是可操作的实体。  

例如：  
- “汽车”是一个类，描述了汽车的属性（颜色、排量）和行为（启动、刹车）；  
- 你家的“黑色特斯拉Model 3”是“汽车”类的一个对象。  


## 二、类的定义：封装属性与行为  
类通过**成员变量**（属性）和**成员函数**（行为）封装一类事物的特征，语法格式：  

```cpp
class 类名 {
    访问控制符:
        成员变量;  // 属性
        成员函数;  // 行为
};
```  

### 1. 访问控制符：控制成员的访问权限  
C++通过三种访问控制符实现**封装**（隐藏内部细节，仅暴露必要接口）：  

| 控制符       | 访问权限                                   |  
|--------------|--------------------------------------------|  
| `public`     | 类内、类外、派生类均可访问（对外接口）     |  
| `private`    | 仅类内可访问（内部实现，隐藏细节）         |  
| `protected`  | 类内和派生类可访问（用于继承）             |  


### 2. 成员变量与成员函数  
- **成员变量**：描述类的属性（如学生的姓名、年龄）；  
- **成员函数**：描述类的行为（如学生的选课、考试）。  

**示例：定义一个`Student`类**  
```cpp
class Student {
private:  // 私有成员（仅类内访问）
    std::string name;  // 姓名（属性）
    int age;           // 年龄（属性）
    float score;       // 成绩（属性）

public:   // 公有成员（类外可访问，对外接口）
    // 设置学生信息（行为）
    void setInfo(std::string n, int a, float s) {
        name = n;
        age = a;
        score = s;
    }

    // 打印学生信息（行为）
    void printInfo() {
        std::cout << "姓名：" << name 
                  << "，年龄：" << age 
                  << "，成绩：" << score << "\n";
    }
};
```  


## 三、对象的创建与使用  
对象是类的实例化，通过对象可以访问类的公有成员（变量或函数）。  


### 1. 创建对象  
```cpp
int main() {
    // 方式1：栈上创建对象（自动销毁）
    Student stu1;  // 调用默认构造函数

    // 方式2：堆上创建对象（需手动销毁）
    Student* stu2 = new Student();  // 用new创建，返回指针

    return 0;
}
```  


### 2. 访问对象成员  
- 栈对象：通过`.`访问成员；  
- 堆对象（指针）：通过`->`访问成员。  

```cpp
int main() {
    Student stu1;
    stu1.setInfo("张三", 18, 90.5);  // 栈对象：. 访问
    stu1.printInfo();                // 输出：姓名：张三，年龄：18，成绩：90.5

    Student* stu2 = new Student();
    stu2->setInfo("李四", 19, 88.0); // 堆对象：-> 访问
    stu2->printInfo();               // 输出：姓名：李四，年龄：19，成绩：88.0

    delete stu2;  // 释放堆对象内存
    return 0;
}
```  


## 四、特殊成员函数  

### 1. 构造函数：初始化对象  
- **作用**：对象创建时自动调用，用于初始化成员变量；  
- **特点**：与类名同名，无返回值，可重载（多个版本）；  
- **默认构造函数**：若未定义，编译器自动生成（无参）。  

**示例：自定义构造函数**  
```cpp
class Student {
private:
    std::string name;
    int age;
    float score;

public:
    // 无参构造函数（默认构造函数）
    Student() {
        name = "未知";
        age = 0;
        score = 0.0;
    }

    // 带参构造函数（重载）
    Student(std::string n, int a, float s) {
        name = n;
        age = a;
        score = s;
    }

    void printInfo() {
        std::cout << "姓名：" << name << "，年龄：" << age << "，成绩：" << score << "\n";
    }
};

// 使用：
int main() {
    Student stu1;                  // 调用无参构造函数
    Student stu2("王五", 20, 95.0); // 调用带参构造函数
    stu1.printInfo();  // 输出：姓名：未知，年龄：0，成绩：0
    stu2.printInfo();  // 输出：姓名：王五，年龄：20，成绩：95
    return 0;
}
```  


### 2. 析构函数：清理对象资源  
- **作用**：对象销毁时自动调用，用于释放资源（如堆内存、文件句柄）；  
- **特点**：类名前加`~`，无参数，无返回值，不可重载。  

**示例：析构函数释放堆内存**  
```cpp
class Array {
private:
    int* data;  // 堆内存指针
    int size;

public:
    // 构造函数：分配堆内存
    Array(int s) : size(s) {
        data = new int[size];  // 申请堆内存
        std::cout << "构造函数：分配了" << size << "个int的内存\n";
    }

    // 析构函数：释放堆内存
    ~Array() {
        delete[] data;  // 释放堆内存
        std::cout << "析构函数：释放了内存\n";
    }
};

// 使用：
int main() {
    {
        Array arr(10);  // 创建对象，调用构造函数
    }  // 离开作用域，对象销毁，自动调用析构函数
    return 0;
}
```  


### 3. const成员函数：保证不修改成员变量  
- **声明**：函数参数列表后加`const`；  
- **作用**：确保函数不会修改成员变量，可被`const`对象调用。  

```cpp
class Student {
private:
    std::string name;
    int age;

public:
    Student(std::string n, int a) : name(n), age(a) {}

    // const成员函数：不能修改成员变量
    void printInfo() const {
        std::cout << "姓名：" << name << "，年龄：" << age << "\n";
        // age = 20;  // 错误：const函数不能修改成员变量
    }
};

// 使用：
int main() {
    const Student stu("赵六", 21);  // const对象
    stu.printInfo();  // 正确：const对象可调用const成员函数
    return 0;
}
```  


## 五、静态成员：属于类的成员  
静态成员（变量/函数）**不属于某个对象，而属于整个类**，所有对象共享同一份静态成员。  


### 1. 静态成员变量  
- **声明**：成员变量前加`static`；  
- **初始化**：必须在类外初始化（类内仅声明）；  
- **访问**：通过`类名::变量名`或`对象.变量名`访问。  

**示例：用静态变量统计对象数量**  
```cpp
class Student {
private:
    static int count;  // 静态成员变量：统计对象总数

public:
    Student() { count++; }  // 构造函数：创建对象时计数+1
    ~Student() { count--; } // 析构函数：销毁对象时计数-1

    // 静态成员函数：返回对象数量
    static int getCount() {
        return count;
    }
};

// 静态成员变量类外初始化
int Student::count = 0;

// 使用：
int main() {
    Student stu1, stu2;
    std::cout << "当前对象数：" << Student::getCount() << "\n";  // 输出：2
    {
        Student stu3;
        std::cout << "当前对象数：" << Student::getCount() << "\n";  // 输出：3
    }
    std::cout << "当前对象数：" << Student::getCount() << "\n";  // 输出：2
    return 0;
}
```  


### 2. 静态成员函数  
- **声明**：成员函数前加`static`；  
- **特点**：无`this`指针，只能访问静态成员变量/函数，不能访问非静态成员。  


## 六、友元：打破封装的特殊机制  
友元允许外部函数或类访问当前类的私有成员（谨慎使用，避免破坏封装）。  


### 1. 友元函数  
```cpp
class Point {
private:
    int x, y;
public:
    Point(int x=0, int y=0) : x(x), y(y) {}
    
    // 声明友元函数：允许其访问私有成员
    friend void printPoint(const Point& p);
};

// 友元函数：可直接访问Point的私有成员x、y
void printPoint(const Point& p) {
    std::cout << "(" << p.x << "," << p.y << ")\n";  // 正确：友元可访问私有成员
}
```  


### 2. 友元类  
```cpp
class A {
private:
    int secret;
    friend class B;  // 声明B为友元类，B可访问A的私有成员
public:
    A() : secret(100) {}
};

class B {
public:
    void getSecret(A& a) {
        std::cout << "A的私有成员：" << a.secret << "\n";  // 正确：友元类可访问
    }
};
```  


## 七、面向对象三大特性（小结）  
1. **封装**：通过类将数据（成员变量）和操作（成员函数）捆绑，用访问控制符隐藏内部细节（`private`），暴露接口（`public`）；  
2. **继承**：一个类（子类）可继承另一个类（父类）的成员，实现代码复用（后续章节详解）；  
3. **多态**：同一接口（如函数名）可表现出不同行为，通过虚函数实现（后续章节详解）。  


## 八、总结  
- 类是对象的模板，对象是类的实例；  
- 类通过成员变量和成员函数封装属性与行为，通过访问控制符实现封装；  
- 构造函数初始化对象，析构函数清理资源；  
- 静态成员属于类，被所有对象共享；  
- 友元用于特殊场景，允许外部访问私有成员（需谨慎使用）。  