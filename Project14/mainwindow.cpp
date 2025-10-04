// mainwindow.cpp：主窗口实现
#include "mainwindow.h"
#include "ui_mainwindow.h" // 包含界面设计生成的代码,由Qt生成，从.ui文件转换而来

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this); // 初始化界面（加载.ui文件中设计的控件）
    // 手动添加一个标签，显示"Hello GUI!"
    ui->label->setText("Hello GUI!"); // 假设.ui中已拖入一个QLabel，命名为label
}

MainWindow::~MainWindow() {
    delete ui; // 释放界面资源（对象树会自动处理子控件）
}