// 一个C++14风格的Hello World
// 注意Visual Studio一个项目只能有一个main函数，所以如果要运行这个文件，请把其他文件中的main函数注释掉。
// 单行注释
/*
	* 多行注释
*/

#include <iostream> //引入头文件

using namespace std; //命名空间

int main() { //主函数
	cout << "Hello, World!" << endl;
	//cout是标准输出流，endl表示换行
	//''单引号表示字符，""双引号表示字符串
	return 0;//返回0表示程序正常结束，编译器版本较新可以省略
}