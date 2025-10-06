#include <iostream>
#include <cmath>  // 包含sqrt函数的声明

// 抽象基类：图形
class Shape {
public:
    virtual double area() const = 0; // 纯虚函数：面积
    virtual Shape* add(const Shape&) const = 0; // 纯虚函数：合并图形
    
    // 重载+运算符（调用add实现）
    Shape* operator+(const Shape& other) const {
        return add(other);
    }
    
    virtual ~Shape() = default;
};

// 圆形
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    
    double area() const override {
        return 3.14 * radius * radius;
    }
    
    // 实现合并：返回新圆形（面积之和对应的圆）
    Shape* add(const Shape& other) const override {
        double totalArea = area() + other.area();
        return new Circle(std::sqrt(totalArea / 3.14)); // 使用std::sqrt
    }
};

// 矩形
class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double area() const override {
        return width * height;
    }
    
    // 实现合并：返回新矩形（面积之和）
    Shape* add(const Shape& other) const override {
        double totalArea = area() + other.area();
        return new Rectangle(totalArea, 1); // 简化为宽=面积，高=1
    }
};

int main() {
    Shape* c = new Circle(2); // 面积≈12.56
    Shape* r = new Rectangle(3, 4); // 面积=12
    
    Shape* sum = *c + *r; // 多态调用+运算符
    std::cout << "合并后的面积：" << sum->area() << std::endl; // 使用std::cout和std::endl
    
    delete c; delete r; delete sum;
    return 0;
}
