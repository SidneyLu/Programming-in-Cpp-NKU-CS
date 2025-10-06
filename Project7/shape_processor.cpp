#include <iostream>

// 抽象基类：图形（来自之前的多态示例）
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

// 圆形（继承Shape）
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14 * radius * radius; }
};

// 矩形（继承Shape）
class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
};

// 模板类：图形处理器（处理任意类型的Shape子类）
template <typename ShapeType>  // ShapeType必须是Shape的子类
class ShapeProcessor {
private:
    ShapeType shape;  // 存储具体图形
public:
    // 构造函数：接收图形参数
    ShapeProcessor(double p1, double p2 = 0) : shape(p1, p2) {}

    // 计算面积并打印
    void printArea() const {
        std::cout << "面积：" << shape.area() << "\n";
    }
};

int main() {
    // 处理圆形（参数：半径）
    ShapeProcessor<Circle> circleProc(2);  // 圆形半径=2
    circleProc.printArea();  // 输出：面积：12.56

    // 处理矩形（参数：宽、高）
    ShapeProcessor<Rectangle> rectProc(3, 4);  // 宽=3，高=4
    rectProc.printArea();  // 输出：面积：12

    return 0;
}

