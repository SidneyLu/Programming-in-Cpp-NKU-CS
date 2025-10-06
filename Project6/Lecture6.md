# 南开大学 高级语言程序设计 Lecture 6

## 一、继承：实现代码复用的核心机制  
### 1. 为什么需要继承？  
现实世界中，事物常存在“一般与特殊”的关系（如“人”是一般类，“学生”“老师”是特殊类）。  
- **重复问题**：“学生”和“老师”都有“姓名、年龄”等属性，也有“吃饭、睡觉”等行为，若分别定义两个类，会产生大量重复代码。  
- **继承解决**：将“人”作为**父类（基类）** ，“学生”“老师”作为**子类（派生类）** ，子类自动继承父类的成员（属性+行为），仅需补充自身特有的成员，实现代码复用。  


### 2. 继承的基本语法  
```cpp
// 父类（基类）
class 父类名 {
    访问控制符:
        成员变量;
        成员函数;
};

// 子类（派生类）：class 子类名 : 继承方式 父类名
class 子类名 : 继承方式 父类名 {
    访问控制符:
        子类特有成员变量;  // 仅子类有，父类无
        子类特有成员函数;  // 仅子类有，父类无
};
```  


### 3. 关键概念：继承方式与访问权限  
C++有3种继承方式，决定**父类成员在子类中的访问权限**（核心考点）：  

| 继承方式       | 父类public成员 | 父类protected成员 | 父类private成员 | 核心场景               |  
|----------------|----------------|-------------------|-----------------|------------------------|  
| `public`（公有继承） | 子类public     | 子类protected     | 子类不可访问    | 最常用，体现“is-a”关系（如学生is-a人） |  
| `protected`（保护继承） | 子类protected | 子类protected     | 子类不可访问    | 仅用于多层继承，隐藏父类接口         |  
| `private`（私有继承） | 子类private    | 子类private       | 子类不可访问    | 极少用，等价于“子类包含父类对象”     |  

**注意**：父类的`private`成员无论哪种继承方式，子类都无法直接访问（需通过父类的`public`/`protected`接口访问）。  


### 4. 子类的构造与析构顺序  
子类对象创建/销毁时，会自动调用父类的构造/析构函数，顺序固定：  
- **构造**：先调用父类构造函数 → 再调用子类构造函数（“先有父，再有子”）；  
- **析构**：先调用子类析构函数 → 再调用父类析构函数（“先析子，再析父”）。  

**示例：继承中的构造与析构**  
```cpp
#include <iostream>
#include <string>
using namespace std;

// 父类：人
class Person {
public:
    // 父类构造函数
    Person(string n, int a) : name(n), age(a) {
        cout << "Person构造函数调用\n";
    }
    // 父类析构函数
    ~Person() {
        cout << "Person析构函数调用\n";
    }
protected:  // 保护成员：子类可访问
    string name;
    int age;
};

// 子类：学生（公有继承Person）
class Student : public Person {
public:
    // 子类构造函数：必须先初始化父类
    Student(string n, int a, int id) : Person(n, a), studentId(id) {
        cout << "Student构造函数调用\n";
    }
    // 子类析构函数
    ~Student() {
        cout << "Student析构函数调用\n";
    }
    // 子类特有行为：打印学生信息
    void printInfo() {
        cout << "姓名：" << name << "，年龄：" << age << "，学号：" << studentId << "\n";
    }
private:  // 子类特有属性
    int studentId;
};

// 使用
int main() {
    Student stu("张三", 18, 2024001);  // 创建子类对象
    stu.printInfo();  // 输出：姓名：张三，年龄：18，学号：2024001
    return 0;
}
```  
**运行结果**：  
```
Person构造函数调用
Student构造函数调用
姓名：张三，年龄：18，学号：2024001
Student析构函数调用
Person析构函数调用
```  


### 5. 继承的特殊场景  
- **多层继承**：子类作为父类，再派生子类（如`Person → Student → Graduate`），构造顺序从最顶层父类到最底层子类；  
- **多重继承**：子类同时继承多个父类（如`class Teacher : public Person, public Employee`），需注意“菱形继承”问题（多个父类继承自同一顶层父类，导致成员重复），可通过**虚继承（virtual）** 解决（后续进阶内容）。  


## 二、多态：同一接口，不同行为  
### 1. 什么是多态？  
多态是指“**同一操作（接口）作用于不同对象，产生不同结果**”。  
例如：“动物叫”是同一接口（`speak()`），但“猫叫”（喵喵）、“狗叫”（汪汪）是不同行为——这就是多态的现实体现。  


### 2. 多态的实现条件（核心！）  
C++多态需满足3个条件，缺一不可：  
1. **继承**：子类继承父类；  
2. **重写**：子类重写父类的**虚函数**（父类函数用`virtual`修饰，子类函数与父类函数名、参数列表、返回值完全一致）；  
3. **动态绑定**：用**父类指针或引用**指向子类对象，调用虚函数。  


### 3. 关键：虚函数（virtual function）  
#### （1）虚函数的语法  
- 父类中，函数声明前加`virtual`关键字，标记为虚函数；  
- 子类中，重写虚函数时，`virtual`可省略（但建议保留，增强可读性）；  
- 虚函数的核心是“**运行时确定调用哪个函数**”（动态绑定），而非编译时确定（静态绑定）。  

#### （2）多态示例：动物叫  
```cpp
#include <iostream>
#include <string>
using namespace std;

// 父类：动物（抽象概念）
class Animal {
public:
    // 虚函数：动物叫（接口）
    virtual void speak() {
        cout << "动物发出叫声\n";
    }
    // 虚析构函数：解决父类指针析构子类对象的内存泄漏
    virtual ~Animal() {}
};

// 子类：猫
class Cat : public Animal {
public:
    // 重写虚函数：猫叫
    void speak() override {  // override关键字：显式标记重写（C++11+，建议用）
        cout << "猫喵喵叫\n";
    }
};

// 子类：狗
class Dog : public Animal {
public:
    // 重写虚函数：狗叫
    void speak() override {
        cout << "狗汪汪叫\n";
    }
};

// 统一接口：接收父类引用，调用speak()
void makeSound(Animal& animal) {
    animal.speak();  // 多态体现：调用哪个speak()，取决于传入的对象类型
}

// 使用
int main() {
    Cat cat;
    Dog dog;
    
    makeSound(cat);  // 输出：猫喵喵叫（调用Cat::speak()）
    makeSound(dog);  // 输出：狗汪汪叫（调用Dog::speak()）
    
    // 父类指针指向子类对象（动态绑定）
    Animal* pCat = new Cat();
    Animal* pDog = new Dog();
    pCat->speak();  // 输出：猫喵喵叫
    pDog->speak();  // 输出：狗汪汪叫
    
    delete pCat;  // 调用Cat析构 → Animal析构（虚析构的作用）
    delete pDog;  // 调用Dog析构 → Animal析构
    return 0;
}
```  


### 4. 虚析构函数的必要性  
若父类析构函数不是虚函数，当用**父类指针指向子类对象**并`delete`时，只会调用父类析构函数，导致子类特有的成员（如堆内存）无法释放，造成内存泄漏。  
- 解决：将父类析构函数声明为`virtual`（虚析构），此时`delete`父类指针会先调用子类析构，再调用父类析构。  


### 5. 纯虚函数与抽象类  
#### （1）纯虚函数  
若父类的虚函数仅作为“接口”，无需实现（如`Animal::speak()`，动物本身没有具体叫声），可声明为**纯虚函数**：  
```cpp
class Animal {
public:
    // 纯虚函数：=0表示无实现，仅作为接口
    virtual void speak() = 0;
    virtual ~Animal() {}
};
```  

#### （2）抽象类  
- 含有纯虚函数的类称为**抽象类**；  
- 抽象类**不能实例化对象**（如`Animal a;` 错误），只能作为父类被继承；  
- 子类必须**重写所有纯虚函数**，才能实例化对象（否则子类仍是抽象类）。  

**示例：抽象类的使用**  
```cpp
// 抽象类：Shape（形状）
class Shape {
public:
    // 纯虚函数：计算面积（接口）
    virtual double calculateArea() = 0;
    virtual ~Shape() {}
};

// 子类：Circle（圆形）- 重写纯虚函数
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    // 重写纯虚函数：计算圆面积
    double calculateArea() override {
        return 3.14 * radius * radius;
    }
};

// 子类：Rectangle（矩形）- 重写纯虚函数
class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    // 重写纯虚函数：计算矩形面积
    double calculateArea() override {
        return width * height;
    }
};

// 统一接口：计算并打印面积
void printArea(Shape& shape) {
    cout << "面积：" << shape.calculateArea() << "\n";
}

// 使用
int main() {
    Circle circle(5);
    Rectangle rect(3, 4);
    printArea(circle);  // 输出：面积：78.5
    printArea(rect);    // 输出：面积：12
    return 0;
}
```  


### 6. 重写、重载、隐藏的区别（易混淆点）  
| 概念       | 发生场景               | 核心要求                                                                 |
|------------|------------------------|--------------------------------------------------------------------------|
| 重写（Override） | 子类与父类之间         | 父类虚函数，子类函数名、参数列表、返回值完全一致（协变除外）             |
| 重载（Overload） | 同一类内部             | 函数名相同，参数列表（个数/类型/顺序）不同，与返回值无关                 |
| 隐藏（Hide）     | 子类与父类之间         | 子类函数名与父类非虚函数相同，隐藏父类函数（调用时优先子类）             |  


## 三、继承与多态的关系（小结）  
1. **继承是多态的基础**：没有继承，无法实现“子类重写父类接口”；  
2. **多态是继承的延伸**：继承解决“代码复用”，多态解决“接口统一，行为多样”；  
3. **核心逻辑**：通过“父类指针/引用指向子类对象”+“虚函数”，实现“运行时动态绑定”，让代码更灵活、可扩展（如新增`Bird`子类，无需修改`makeSound`接口，直接调用即可）。  


## 四、常见问题与注意事项  
1. **继承方式选择**：优先用`public`继承（体现“is-a”关系），避免`private`继承（易破坏封装）；  
2. **虚函数使用**：仅需在父类声明`virtual`，子类重写时可省略，但建议加`override`显式标记（编译器会检查重写是否正确）；  
3. **抽象类设计**：当父类仅作为“接口模板”（无具体实现）时，用纯虚函数定义抽象类，强制子类实现接口；  
4. **内存泄漏**：父类指针指向子类对象时，务必将父类析构函数声明为虚析构。  

## 五、运算符重载：自定义类型的操作符扩展
运算符重载允许为自定义类型重新定义运算符行为，使代码更直观。在继承与多态场景中，运算符重载有特殊应用规则。

### 1. 运算符重载的两种形式
#### （1）成员函数重载
左操作数必须是当前类对象，隐含`this`指针指向左操作数：
```cpp
class Point {
public:
    int x, y;
    Point(int x=0, int y=0) : x(x), y(y) {}
    
    // 成员函数重载+：this指向左操作数
    Point operator+(const Point& rhs) const {
        return Point(x + rhs.x, y + rhs.y);
    }
};
```

#### （2）非成员函数重载（通常为友元）
适用于左操作数为其他类型的场景：
```cpp
// 非成员函数重载+：支持int + Point
Point operator+(int lhs, const Point& rhs) {
    return Point(lhs + rhs.x, lhs + rhs.y);
}
```


### 2. 继承中的运算符重载
子类可重载或重写父类的运算符，但需遵循多态规则：

#### （1）重载父类未定义的运算符
```cpp
// 父类：形状
class Shape {
protected:
    int area;
public:
    Shape(int a) : area(a) {}
};

// 子类：矩形
class Rectangle : public Shape {
public:
    Rectangle(int a) : Shape(a) {}
    
    // 子类新增+运算符重载：合并面积
    Rectangle operator+(const Rectangle& other) const {
        return Rectangle(area + other.area);
    }
};
```

#### （2）重写父类的虚运算符（实现多态）
```cpp
class Number {
public:
    virtual Number operator+(const Number& other) const = 0; // 纯虚运算符
    virtual void print() const = 0;
};

class IntNumber : public Number {
private:
    int val;
public:
    IntNumber(int v) : val(v) {}
    
    // 重写+运算符
    IntNumber operator+(const Number& other) const override {
        // 向下转型获取具体类型（实际开发需用dynamic_cast）
        const IntNumber& o = static_cast<const IntNumber&>(other);
        return IntNumber(val + o.val);
    }
    
    void print() const override {
        cout << val << endl;
    }
};

// 多态调用
void addAndPrint(Number& a, Number& b) {
    Number& result = a + b; // 动态绑定到具体类型的+运算符
    result.print();
}
```


### 3. 特殊运算符的继承注意事项
#### （1）赋值运算符（=）
- 编译器会为每个类生成默认赋值运算符，但**不会继承父类的赋值运算符**
- 子类重载时需显式调用父类的赋值运算符避免切片问题：
```cpp
class Base {
protected:
    int x;
public:
    Base& operator=(const Base& other) {
        if (this != &other) x = other.x;
        return *this;
    }
};

class Derived : public Base {
private:
    int y;
public:
    Derived& operator=(const Derived& other) {
        if (this != &other) {
            Base::operator=(other); // 显式调用父类赋值运算符
            y = other.y;
        }
        return *this;
    }
};
```

#### （2）流运算符（<<、>>）
- 必须作为非成员函数重载
- 如需访问子类特有成员，需在子类中重新重载或使用多态：
```cpp
class Animal {
public:
    virtual void print(ostream& os) const = 0;
    friend ostream& operator<<(ostream& os, const Animal& a) {
        a.print(os); // 多态调用
        return os;
    }
};

class Cat : public Animal {
public:
    void print(ostream& os) const override {
        os << "Cat";
    }
};
```


### 4. 运算符重载与多态的结合
通过虚函数实现运算符的多态行为，使不同子类对象通过同一运算符接口表现不同行为：
```cpp
// 几何图形基类
class Shape {
public:
    virtual Shape* operator+(const Shape& other) const = 0; // 合并图形
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

// 圆形子类
class Circle : public Shape {
public:
    Shape* operator+(const Shape& other) const override {
        // 实现圆形与其他图形的合并逻辑
        return new Circle(); // 简化示例
    }
    void draw() const override {
        cout << "Drawing Circle" << endl;
    }
};

// 矩形子类
class Rectangle : public Shape {
public:
    Shape* operator+(const Shape& other) const override {
        // 实现矩形与其他图形的合并逻辑
        return new Rectangle(); // 简化示例
    }
    void draw() const override {
        cout << "Drawing Rectangle" << endl;
    }
};
```
