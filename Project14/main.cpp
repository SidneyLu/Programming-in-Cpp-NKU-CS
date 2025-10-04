// main.cpp：程序入口
#include "mainwindow.h"
#include <QApplication> // 应用程序类，管理整个程序的生命周期

int main(int argc, char *argv[]) {
    QApplication a(argc, argv); // 初始化应用程序，处理命令行参数
    MainWindow w; // 创建主窗口对象（继承自QMainWindow）
    w.show(); // 显示窗口（默认隐藏，需手动调用）
    return a.exec(); // 进入事件循环（等待用户操作，如点击、输入）
}