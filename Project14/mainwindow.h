// mainwindow.h：主窗口类声明
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; } // 界面文件自动生成的类
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT // 启用Qt元对象系统（必须添加，否则信号槽无效）

public:
    MainWindow(QWidget *parent = nullptr); // 构造函数，parent为父对象
    ~MainWindow(); // 析构函数

private:
    Ui::MainWindow *ui; // 指向界面元素的指针（由.ui文件生成）
};
#endif // MAINWINDOW_H