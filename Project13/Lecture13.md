# 南开大学 高级语言程序设计 Lecture 13  

**https://cmake.org/**

## 一、核心定位：CMake 是什么？不是什么？  
CMake 是 **跨平台构建系统生成器**，而非编译器或构建工具——它的核心作用是：  
1. 你编写统一的配置文件（`CMakeLists.txt`），定义工程结构、编译选项、依赖关系；  
2. CMake 根据配置，自动“翻译”成对应平台的原生构建文件（如 Linux 的 `Makefile`、Windows 的 Visual Studio 工程、macOS 的 Xcode 工程）；  
3. 最终由平台原生工具（Make、VS 编译器、Xcode）完成编译链接。  

**关键区别**：  
- 不是编译器（不直接编译代码，依赖 GCC/Clang/VS 编译器）；  
- 不是构建工具（不直接执行构建，依赖 Make/msbuild 等）；  
- 是“中间协调者”，解决“一套代码多平台手动写不同构建脚本”的痛点。


## 二、核心价值：为什么CMake好用？  
相比直接写 `Makefile`、VS 工程，CMake 对中大型项目是刚需，核心价值体现在三个维度：  

| 痛点场景 | 传统方式（直接写 Makefile/VS 工程） | CMake 解决方案 |
|----------|-----------------------------------|---------------|
| 跨平台适配 | 为 Linux 写 Makefile、Windows 写 VS 工程、mac 写 Xcode，多套脚本维护成本高 | 一份 `CMakeLists.txt`，自动生成对应平台构建文件，一套配置走天下 |
| 工程规模扩大 | 手动写 Makefile 时，文件依赖、库链接、编译选项越写越乱，易出错 | 用 `TARGET_LINK_LIBRARIES` 等指令抽象依赖，逻辑清晰，可维护性大幅提升 |
| 第三方库集成 | 手动找库路径、写链接命令（如 `-L/usr/lib -lopencv`），平台差异大 | 用 `FIND_PACKAGE` 自动查找第三方库（OpenCV/Boost/Qt），统一接口屏蔽差异 |
| 多构建类型切换 | 手动改 Makefile 的 `CFLAGS`（Debug/Release），切换繁琐 | 配置时加 `-DCMAKE_BUILD_TYPE=Debug`，一键切换，编译选项自动适配 |


## 三、核心组件：CMake 工作的三大基础  
CMake 的运行依赖「配置文件+命令行工具+缓存文件」，理解这些组件是入门关键。


### 3.1 核心配置文件：`CMakeLists.txt`  
所有构建规则都定义在此文件中，是 CMake 的“指令源”。  
#### 基础语法规范：  
- **指令全大写**（如 `PROJECT`、`ADD_EXECUTABLE`），区分大小写（`project` 不规范）；  
- **变量区分大小写**：自定义变量用「大写+下划线」（如 `ENABLE_LOG`），CMake 内置变量遵循官方命名（如 `CMAKE_CXX_STANDARD`）；  
- **参数分隔**：指令参数用空格分隔，含空格的参数用双引号包裹（如 `SET(PROJECT_NAME "My App")`）；  
- **注释**：单行注释用 `#`，复杂逻辑可加块注释（`#[[ 注释内容 ]]`，C++11 风格）。  

#### 核心指令（基础必学）：  
| 指令 | 功能描述 | 示例 |
|------|----------|------|
| `CMAKE_MINIMUM_REQUIRED(VERSION x.y)` | 指定 CMake 最低版本（避免语法不兼容） | `CMAKE_MINIMUM_REQUIRED(VERSION 3.10)` |
| `PROJECT(NAME [LANGUAGES ...])` | 定义工程名与支持的语言（C/CXX） | `PROJECT(MyApp LANGUAGES CXX)` |
| `SET(VAR VALUE)` | 定义或修改变量 | `SET(CMAKE_CXX_STANDARD 11)` |
| `ADD_EXECUTABLE(TARGET src1 src2 ...)` | 生成可执行目标（TARGET 为目标名） | `ADD_EXECUTABLE(MyApp src/main.cpp)` |
| `ADD_LIBRARY(TARGET TYPE src1 ...)` | 生成库目标（TYPE：STATIC 静态库/SHARED 动态库） | `ADD_LIBRARY(MathLib STATIC src/math.cpp)` |
| `TARGET_LINK_LIBRARIES(TARGET DEP ...)` | 为目标链接依赖库（DEP 为库名） | `TARGET_LINK_LIBRARIES(MyApp MathLib)` |


### 3.2 核心命令行工具  
安装 CMake 后，通过终端/命令行调用的核心工具，是日常开发的“高频操作”：  

| 命令 | 功能描述 | 关键参数示例 |
|------|----------|--------------|
| `cmake` | 配置命令：读取 `CMakeLists.txt`，生成构建文件 | `-S <源码目录>`：指定 `CMakeLists.txt` 所在目录<br>`-B <构建目录>`：指定生成构建文件的目录<br>`-DCMAKE_BUILD_TYPE=Debug`：指定构建类型<br>`-D<变量名>=<值>`：设置自定义变量（如 `-DENABLE_LOG=OFF`） |
| `cmake --build` | 构建命令：调用原生工具执行编译 | `--build <构建目录>`：指定构建目录<br>`-j4`：4 线程并行编译（加速）<br>`--target install`：构建后执行安装 |
| `ctest` | 测试工具：执行 `CMakeLists.txt` 定义的测试用例 | 需先通过 `ENABLE_TESTING()` 和 `ADD_TEST()` 定义测试 |
| `cpack` | 打包工具：将产物打包成安装包（.deb/.rpm/.exe） | 需先通过 `INSTALL()` 定义安装规则 |


### 3.3 辅助缓存文件：`CMakeCache.txt`  
执行 `cmake -S .. -B build` 后，构建目录（`build`）会生成 `CMakeCache.txt`，存储配置过程中的变量（如第三方库路径、编译选项）。  
- **作用**：第二次配置时，优先读取缓存，避免重复检测（如重复查找 OpenCV），加速配置；  
- **注意**：修改 `CMakeLists.txt` 后，需删除 `CMakeCache.txt` 或整个构建目录，否则缓存会导致配置不生效。


## 四、关键工作流程：从配置到构建的 5 步实战  
以 **单文件 C++ 项目** 为例，完整演示 CMake 工作流，所有代码遵循规范风格。


### 4.1 项目结构（基础版）  
```
MyProject/          # 源码根目录
├── src/            # 源码目录
│   └── main.cpp    # 主程序（含 int main()）
└── CMakeLists.txt  # CMake 配置文件（核心）
```


### 4.2 步骤 1：编写 `CMakeLists.txt`  
```cmake
# 1. 最低版本要求（必须有，避免语法不兼容）
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

# 2. 工程定义：名称+支持语言（CXX 表示 C++）
PROJECT(MyApp LANGUAGES CXX)

# 3. 配置 C++ 标准（强制指定，避免编译器用旧标准）
SET(CMAKE_CXX_STANDARD 11)          # 指定 C++11
SET(CMAKE_CXX_STANDARD_REQUIRED ON) # 强制启用标准

# 4. 生成可执行目标：目标名=MyApp，依赖源码=src/main.cpp
ADD_EXECUTABLE(MyApp src/main.cpp)

# 5. （可选）安装规则：指定产物安装路径
# 执行 `cmake --build build --target install` 时，将 MyApp 安装到 ${CMAKE_INSTALL_PREFIX}/bin
INSTALL(TARGETS MyApp DESTINATION bin)
```


### 4.3 步骤 2：执行“配置”（生成构建文件）  
推荐 **Out-of-Source 构建**（构建目录与源码分离，避免污染源码），终端执行：  
```bash
# 1. 进入源码根目录
cd MyProject

# 2. 创建并进入构建目录（命名为 build，约定俗成）
mkdir build && cd build

# 3. 执行配置：-S 指定源码目录（.. 表示上一级），-B 指定构建目录（. 表示当前）
cmake -S .. -B . -DCMAKE_BUILD_TYPE=Debug
```  
执行后，`build` 目录会生成对应平台的构建文件：  
- Linux/macOS：生成 `Makefile`；  
- Windows（安装 VS 后）：生成 `MyApp.sln`（VS 工程）；  
- macOS（需 Xcode）：加 `-G Xcode` 参数，生成 Xcode 工程。


### 4.4 步骤 3：执行“构建”（编译生成产物）  
在 `build` 目录下，执行构建命令：  
```bash
# 调用原生工具编译（-j4 表示 4 线程并行，加速）
cmake --build . -j4
```  
构建完成后，`build` 目录会生成可执行文件：  
- Linux：`MyApp`（直接运行 `./MyApp`）；  
- Windows：`Debug/MyApp.exe`（或 `Release/MyApp.exe`，取决于构建类型）；  
- macOS：`MyApp`（直接运行 `./MyApp`）。


### 4.5 步骤 4（可选）：测试与安装  
#### （1）测试：添加测试用例  
修改 `CMakeLists.txt`，添加测试配置：  
```cmake
# 启用测试功能
ENABLE_TESTING()

# 添加测试用例：名称=TestMyApp，命令=MyApp（可加参数，如 MyApp 10 20）
ADD_TEST(NAME TestMyApp COMMAND MyApp)
```  
配置并构建后，在 `build` 目录执行测试：  
```bash
ctest  # 执行所有测试用例，输出测试结果（成功/失败）
```

#### （2）安装：执行安装命令  
在 `build` 目录下，执行安装（需先定义 `INSTALL` 规则）：  
```bash
# 安装产物到默认路径（Linux：/usr/local/bin；Windows：C:\Program Files\MyApp\bin）
cmake --build . --target install

# 自定义安装路径：配置时加 -DCMAKE_INSTALL_PREFIX=<路径>
# 示例：安装到 ~/myapp 目录
cmake -S .. -B . -DCMAKE_INSTALL_PREFIX=~/myapp
cmake --build . --target install
```


## 五、进阶特性：应对复杂工程需求  
基础流程仅适用于单文件项目，中大型项目需掌握以下进阶特性，所有示例均遵循规范风格。


### 5.1 子目录配置（模块化管理）  
当项目拆分多个模块（如“核心库”“工具模块”）时，可将每个模块单独写 `CMakeLists.txt`，用 `ADD_SUBDIRECTORY` 引入主配置，实现模块化。  

#### 项目结构（进阶版）  
```
MyProject/
├── src/
│   ├── main.cpp          # 主程序
│   └── math/             # 子模块：数学工具库
│       ├── math.cpp      # 库源码
│       ├── math.h        # 库头文件
│       └── CMakeLists.txt# 子模块配置文件
└── CMakeLists.txt        # 主配置文件
```

#### （1）子模块配置（src/math/CMakeLists.txt）  
```cmake
# 生成静态库：目标名=MathLib，类型=STATIC
ADD_LIBRARY(MathLib STATIC math.cpp math.h)

# 对外暴露头文件路径（PUBLIC：引用此库的目标自动继承头文件路径）
# ${CMAKE_CURRENT_SOURCE_DIR} 表示当前子模块目录（src/math）
TARGET_INCLUDE_DIRECTORIES(MathLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```

#### （2）主配置文件（根目录 CMakeLists.txt）  
```cmake
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(MyApp LANGUAGES CXX)
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

# 引入子模块（路径=src/math）
ADD_SUBDIRECTORY(src/math)

# 生成主程序可执行目标
ADD_EXECUTABLE(MyApp src/main.cpp)

# 链接子模块库（无需手动指定头文件，因 MathLib 用了 PUBLIC）
TARGET_LINK_LIBRARIES(MyApp PRIVATE MathLib)
```


### 5.2 库构建与链接（静态库/动态库）  
实际项目常需将代码编译成库（静态库 `.a/.lib`、动态库 `.so/.dll`），再链接到可执行目标。  

#### 示例：生成动态库并链接  
修改子模块配置（src/math/CMakeLists.txt），将 `STATIC` 改为 `SHARED`：  
```cmake
# 生成动态库（类型=SHARED）
ADD_LIBRARY(MathLib SHARED math.cpp math.h)

# 动态库需指定版本（可选，Windows 无需）
SET_TARGET_PROPERTIES(MathLib PROPERTIES
    VERSION 1.0.0        # 版本号：1.0.0
    SOVERSION 1          # API 版本：1
)

TARGET_INCLUDE_DIRECTORIES(MathLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```  
主配置文件无需修改，构建后会生成动态库（如 Linux 的 `libMathLib.so`、Windows 的 `MathLib.dll`），可执行文件会链接此动态库。


### 5.3 第三方库集成（以 OpenCV 为例）  
项目常依赖第三方库（如 OpenCV、Boost、Qt），CMake 用 `FIND_PACKAGE` 自动查找库的路径、头文件和链接库，无需手动写 `-I`/`-L`。  

#### 配置示例（根目录 CMakeLists.txt）  
```cmake
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(MyCVApp LANGUAGES CXX)
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. 查找 OpenCV 库（指定最低版本 4.0，REQUIRED 表示找不到则报错）
FIND_PACKAGE(OpenCV 4.0 REQUIRED)

# 2. 生成可执行目标（依赖 src/main_cv.cpp，需用 OpenCV）
ADD_EXECUTABLE(MyCVApp src/main_cv.cpp)

# 3. 链接 OpenCV 库：引用 FindOpenCV.cmake 定义的变量
# ${OpenCV_INCLUDE_DIRS}：OpenCV 头文件路径
# ${OpenCV_LIBRARIES}：OpenCV 链接库列表
TARGET_INCLUDE_DIRECTORIES(MyCVApp PRIVATE ${OpenCV_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(MyCVApp PRIVATE ${OpenCV_LIBRARIES})
```

#### 第三方库查找失败解决方案  
若库未安装在系统默认路径（如自定义安装到 `/opt/opencv`），需通过 `-D<库名>_DIR` 指定查找路径：  
```bash
# 配置时指定 OpenCV 的 CMake 配置目录
cmake -S .. -B . -DOpenCV_DIR=/opt/opencv/lib/cmake/opencv4
```


### 5.4 条件编译与变量控制  
通过 `IF-ELSE` 逻辑和自定义变量，实现“同一配置适配不同场景”（如 Debug/Release 选项、是否启用日志）。  

#### 配置示例（根目录 CMakeLists.txt）  
```cmake
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(MyApp LANGUAGES CXX)
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. 自定义开关变量：是否启用日志（默认开启 ON）
OPTION(ENABLE_LOG "Enable log function in project" ON)

# 2. 生成可执行目标
ADD_EXECUTABLE(MyApp src/main.cpp)

# 3. 根据构建类型设置编译选项
IF(CMAKE_BUILD_TYPE STREQUAL "Debug")
  # Debug 模式：添加调试信息、启用断言
  TARGET_COMPILE_OPTIONS(MyApp PRIVATE -g -DDEBUG)
ELSEIF(CMAKE_BUILD_TYPE STREQUAL "Release")
  # Release 模式：开启优化、禁用断言
  TARGET_COMPILE_OPTIONS(MyApp PRIVATE -O2 -DNDEBUG)
ENDIF()

# 4. 根据自定义变量启用日志
IF(ENABLE_LOG)
  # 添加宏定义 -DENABLE_LOG，源码中可通过 #ifdef ENABLE_LOG 判断
  TARGET_COMPILE_DEFINITIONS(MyApp PRIVATE ENABLE_LOG)
ENDIF()
```

#### 切换配置  
配置时通过 `-D` 修改自定义变量：  
```bash
# 禁用日志功能，构建 Release 版本
cmake -S .. -B . -DCMAKE_BUILD_TYPE=Release -DENABLE_LOG=OFF
```


## 六、实战避坑：新手常踩的 3 个关键问题  
1. **In-Source Build 导致源码污染**  
   直接在源码目录执行 `cmake .`，会生成大量构建文件（`Makefile`、`CMakeCache.txt`），污染源码。  
   **解决方案**：强制用 Out-of-Source 构建（单独创建 `build` 目录，在其中执行配置和构建）。

2. **修改配置后不生效（缓存问题）**  
   修改 `CMakeLists.txt` 后，重新配置发现逻辑未生效，原因是 `CMakeCache.txt` 缓存了旧变量。  
   **解决方案**：删除 `build` 目录下的 `CMakeCache.txt`，或直接删除整个 `build` 目录，重新执行 `cmake`。

3. **第三方库查找失败（`FIND_PACKAGE` 报错）**  
   原因：库未安装在系统默认路径，或 CMake 找不到对应的“查找模块”（如 `FindOpenCV.cmake`）。  
   **解决方案**：  
   - 用 `-D<库名>_DIR` 指定库的 CMake 配置目录（如 `-DOpenCV_DIR=/opt/opencv/lib/cmake/opencv4`）；  
   - 若没有查找模块，手动指定头文件和库路径（用 `INCLUDE_DIRECTORIES` 和 `LINK_DIRECTORIES`），但优先用 `FIND_PACKAGE`。
   - 将第三方库添加到系统的Path环境变量

## 七、集成CMake的现代IDE
- **Visual Studio** 可以构建CMake项目
- **CLion** 对CMake、Qt的支持都很棒，还可以自动生成CMakeLists，对新手非常友好

## 附件中有用于Qt+OpenCV+LibTorch配置的CMakeLists.txt，如需借用请参考本文档修改好项目名、依赖版本、路径等参数
## 参考项目 MonetGAN https://github.com/SidneyLu/MonetGAN
