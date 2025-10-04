# 南开大学 高级语言程序设计 Lecture 14  

## 一、“黑框框”的终结——图形用户界面（GUI）  

### 1. 从命令行到图形界面：交互方式的革命  
- **命令行界面（CLI）的局限**：  
  前面我们写的程序均通过“黑框框”（终端/控制台）交互，需用户输入指令、程序输出文本，这与我们日常使用的应用程序存在很大出入，大家一定很难按捺对常用应用程序如何编写的好奇心，甚至不免开始怀疑自己选择计科专业的初衷（笑）。本讲我们就开始一探究竟。

- **图形用户界面（GUI）的优势**：  
  以窗口、按钮、图标、菜单等可视化元素为核心，通过鼠标点击、拖拽等直观操作完成交互，降低用户门槛（如“点击按钮”替代“输入命令”），支持图像、动画、布局等复杂表现形式，是现代软件（浏览器、办公软件、游戏等）的标配。  

- **GUI的核心组成**：  
  任何GUI程序都包含三大要素：  
  - **窗口（Window）**：程序与用户交互的“容器”，可移动、缩放、关闭；  
  - **控件（Widget）**：窗口内的交互元素（按钮、文本框、滑块等）；  
  - **事件（Event）**：用户操作（点击、输入、移动鼠标等）触发的程序响应逻辑。  
 


## 二、Qt“一点点”——核心概念与入门实践  

### 1. Qt的“基石”：核心术语与理念  
- **QObject**：Qt所有类的“老祖宗”，提供内存管理（对象树）、事件处理、元对象支持等核心功能。  
  - **对象树**：Qt中父对象会自动管理子对象的生命周期（如窗口关闭时，自动销毁其内部所有按钮），无需手动释放内存，解决C++动态内存管理的痛点。  

- **信号与槽（Signals & Slots）**：Qt最独特的通信机制，替代传统回调函数，实现控件间“松耦合”交互。  
  - **信号（Signal）**：控件状态变化时发出的“通知”（如按钮被点击时发出`clicked()`信号）；  
  - **槽（Slot）**：接收信号并执行相应逻辑的函数（如按钮点击后触发“打开文件”操作）；  
  - **连接（Connect）**：通过`QObject::connect()`将信号与槽绑定，形成“点击按钮→执行函数”的响应链。  

- **控件（Widgets）**：可视化交互元素的总称，Qt提供数百种预制控件，常用基础控件包括：  
  - `QPushButton`：按钮（触发操作）；  
  - `QLineEdit`：单行文本框（输入账号/密码）；  
  - `QTextEdit`：多行文本框（编辑文档）；  
  - `QLabel`：标签（显示文字/图片）；  
  - `QComboBox`：下拉列表（选择选项）。  


### 2. 第一步：Qt开发环境搭建  
- **工具选择**：Qt官方提供**Qt Creator**（集成IDE），包含代码编辑器、界面设计器、编译器，一键安装即可开始开发。  **使用CLion+CMake的配置参考第13章**
- **安装要点**：  
  1. 下载Qt Online Installer，选择对应系统版本（Windows/macOS/Linux）；  
  2. 安装时勾选“Qt 6.x”（最新稳定版）、“Desktop 组件”（桌面开发）、“Qt Creator”；  
  3. 无需单独配置编译器（Qt会自动关联系统中的MSVC/GCC）。  


### 3. 第一个Qt程序：“Hello GUI”  
#### （1）创建项目  
在Qt Creator中选择“Qt Widgets Application”，填写项目名（如`HelloGUI`），选择保存路径，默认使用`QMainWindow`（主窗口类）作为基类。  

#### （2）核心代码解析  
项目自动生成`main.cpp`和`mainwindow.cpp`（Qt Creator、CLion都会帮你办好）  

#### （3）界面设计：可视化与代码的结合  
Qt支持两种界面开发方式：  
- **可视化设计**：通过Qt Designer（集成在Qt Creator中）拖拽控件到窗口，设置属性（如文字、大小），自动生成`.ui`文件（XML格式），编译时转换为C++代码；  
- **纯代码设计**：直接在`MainWindow`构造函数中用代码创建控件（如`QPushButton *btn = new QPushButton("点击我", this);`），更灵活但效率低。  


### 4. 核心机制：信号与槽的“第一次握手”  
以“点击按钮，修改标签文字”为例，演示信号与槽的使用：  
1. 在界面中拖入一个`QPushButton`（命名为`pushButton`）和一个`QLabel`（命名为`label`）；  
2. 在`MainWindow`类中添加槽函数声明（`private slots`区域）：  
   ```cpp
   private slots:
       void onButtonClicked(); // 按钮点击后执行的函数
   ```  
3. 实现槽函数：  
   ```cpp
   void MainWindow::onButtonClicked() {
       ui->label->setText("按钮被点击了！"); // 修改标签文字
   }
   ```  
4. 在构造函数中连接信号与槽：  
   ```cpp
   MainWindow::MainWindow(QWidget *parent)
       : QMainWindow(parent)
       , ui(new Ui::MainWindow) {
       ui->setupUi(this);
       // 连接按钮的clicked信号与自定义槽函数
       connect(ui->pushButton, &QPushButton::clicked, 
               this, &MainWindow::onButtonClicked);
   }
   ```  
运行程序后，点击按钮，标签文字会实时更新——这就是Qt“事件驱动”的核心逻辑。  

## 这里所涉及的Qt只是一点皮毛，开发细节请参考Qt官方文档 https://doc.qt.io
## Qt下载安装出现问题请尝试切换国内镜像源 https://mirrors.tuna.tsinghua.edu.cn/help/qt
## 随着开发的推进，你会发现构建GUI应用程序的工程量还是挺大的，就数据可视化而言，其实我们有不少其他工具，在日常学习研究中得到广泛使用且备受好评