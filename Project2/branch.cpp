//分支结构

#include <iostream>

using namespace std;

int main() {
    // 1. if-else语句：处理二选一逻辑
    int score = 85;
    if (score >= 60) {
        cout << "成绩合格" << endl;  // 条件成立时执行
    }
    else {
        cout << "成绩不合格" << endl;  // 条件不成立时执行
	}
    //注意区分比较运算符==和赋值运算符=

    // 2. if-else if-else语句：处理多条件分支
    char grade;
    if (score >= 90) {
        grade = 'A';
    }
    else if (score >= 80) {
        grade = 'B';
    }
    else if (score >= 60) {
        grade = 'C';
    }
    else {
        grade = 'D';  // 所有条件不成立时的默认情况
    }
    //C++并不像Python以缩进区分代码块，缩进是为了代码的可读性，代码块以大括号划分
	//不用代码块的形式，控制语句只能控制与其相邻的后一条语句
    //注意if-else的匹配
    cout << "等级评定：" << grade << endl;

    // 3. switch语句：处理离散值匹配（适合枚举、整数、字符等）
    int menuChoice;
    cout << "\n请选择操作（1-3）：";
    cin >> menuChoice;

    switch (menuChoice) {
    case 1:  // 当menuChoice为1时执行
        cout << "执行添加操作" << endl;
        break;  // 跳出switch，避免继续执行后续case
    case 2:  // 当menuChoice为2时执行
        cout << "执行删除操作" << endl;
        break;
    case 3:  // 当menuChoice为3时执行
        cout << "执行查询操作" << endl;
        break;
    default:  // 所有case不匹配时的默认操作
        cout << "无效选择" << endl;
	}
    //从第一个匹配项开始往下执行，直到遇到break或switch结束
	//在很多时候忘记break会导致逻辑错误，因为你可能只想多选一。许多编译器遇见这种情况都会事先抛出警告。
	//如果你确实需要直通下一个case，C++17引入了[[fallthrough]]属性，显式标记允许贯穿行为，提升代码可读性和安全性。
    //用[[fallthrough]];替换break;


    /*
		C++17引入了条件分支语句的初始化语法，允许在if或switch语句中声明并初始化变量，
		这样的变量作用域仅限于该语句块内，提升了代码的可读性。
        也解决了某些表达式无法直接作为左值（放在等号左边）参与比较的麻烦。
    */

    return 0;
}