//一个简单的module入门示例
export module welcome;

//以头单元形式导入标准库模块，并不是所有头文件都可以这样做，但常用的目前都已支持
//谨慎将#include头文件的代码和import模块的代码合并
import <iostream>;
import <string>;
import <vector>;


//目前已模块化的标准库（实验性）
//项目->属性->配置属性->C/C++->语言->启用实验性的C++标准库模块
import std.core;      //核心语言支持
import std.filesystem;//文件系统支持
import std.memory;    //智能指针等内存管理支持
import std.regex;     //正则表达式支持
import std.threading;    //多线程支持

//Clang编译器请用 import std; 来导入整个标准库模块


/*
	在较早期标准的C++中，也有可能见到export关键字，但那时的export用于模板，用于导出模板定义以便能拆成多个文件。
	但因编译器实现复杂，实际中几乎没被广泛支持。
*/

/*
	你无法访问模块中未export的内容，而头文件中的一切可以在#include之后访问（别忘了头文件中定义的类本身的封装）。
	同时import模块无需像#include头文件那样在意顺序和重复定义，例如说#pragma once。
*/

export std::string greetingsO(){
	return "Hello, welcome to C++20 modules!\nExport a single function.";
}

export {
	std::string greetingsI() {
		return "Hello, welcome to C++20 modules!\nExport multiple functions inside an export block.";
	}
}


/*
	现在你应该明白为什么在大型现代C++工程项目中不建议使用using namespace std;了吧!
	因为它会把std命名空间中的所有符号都引入到当前作用域，导致命名冲突和代码可读性降低。
	例如STL中的vector是个可以当动态数组用的容器，某些矩阵运算库中的vector是个数学向量类，
	命名冲突就会出大乱子。
*/

export namespace test1 {
	std::string greetingsN() {
		return "Hello, welcome to C++20 modules!\nCall a function inside an exported namespace.";
	}
}

namespace test2 {
	export std::string greetingsM() {
		return "Hello, welcome to C++20 modules!\nExport a function inside an unexported namespace.";
	}//如果这个namespace中还有未导出的其他成员，那么他们不可访问。
}

