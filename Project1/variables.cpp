#include <iostream> 
#include <string> //引入string类
using namespace std;

int main() {
    //整型
    int age = 20;//赋值初始化
    int student_id{ 2500000 };//括号初始化 C++11引入的新特性

    //双精度浮点型
    double math_score = 89.5;
    double height{ 1.75 };

    //字符型
    char gender = 'M';//单引号，默认使用ASCII
    char grade_char{ 'A' };

    //布尔型
    bool is_pass = (math_score >= 60);

    //字符串型
    string name = "张三";
    string major{ "计算机科学与技术" };

    //枚举型
    //第一个未手动赋值的取0，后续依次递增1
	//若有多个手动赋值的元素，后续未赋值的从最近一个手动赋的值开始递增
    enum Weekday {
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    };
    Weekday today = Wednesday;

    //强制类型转换
	int truncated_height = static_cast<int>(height); //将double转换为int，截断小数部分

    cout << "=== 算术运算示例 ===" << endl;
    //加减乘除。%是整除取余数
    double total_score = math_score + 92.0;
    int year_diff = 2024 - 2004;
    int remainder = 10 % 3;
    double average_score = total_score / 2;

    cout << name << "的总分：" << total_score << endl;
    cout << name << "的年龄（计算值）：" << year_diff << endl;
    cout << "10 % 3 = " << remainder << endl;
    cout << name << "的平均成绩：" << average_score << endl;
	//string类重载了+运算符，可以连接字符串
	string title = name + "同学";

    cout << "\n=== 自增自减运算示例 ===" << endl;
    //前缀加减完直接用，后缀用完再加减
    //如果一个语句内除了增减无其他调用，二者无差别
    int count = 5;
    cout << "前置++count（先+1再输出）：" << ++count << endl;
    cout << "自增后count的值：" << count << endl;

    int lesson_num = 2;
    cout << "后置lesson_num++（先输出再+1）：" << lesson_num++ << endl;
    cout << "自增后lesson_num的值：" << lesson_num << endl;

    int remaining = 4;
    cout << "前置--remaining（先-1再输出）：" << --remaining << endl;
    cout << "后置remaining--（先输出再-1）：" << remaining-- << endl;
    cout << "最终remaining的值：" << remaining << endl;


    cout << "\n=== 关系运算示例 ===" << endl;
	//关系运算结果为布尔值true或false
    //大于、小于、等于、不等于……
	//注意：C++中比较字符串不能用==，要用string类的成员函数compare()
    //“是”就返回1，否则返回0
    bool is_excellent = (math_score >= 90);
    bool is_same_grade = (grade_char == 'A');
    bool is_taller = (height > 1.70);

	//三元运算符 ? :
	//结构（条件）？（条件为真时的值）：（条件为假时的值）
    cout << name << "数学是否优秀：" << (is_excellent ? "是" : "否") << endl;
    cout << name << "成绩等级是否为A：" << (is_same_grade ? "是" : "否") << endl;
    cout << name << "身高是否超过1.70米：" << (is_taller ? "是" : "否") << endl;


    cout << "\n=== 逻辑运算示例 ===" << endl;
	//逻辑与&&、或||、非!
    //说成and or not应该更好理解
    bool is_good_student = (is_pass && is_taller);
    bool has_advantage = (math_score > 90);
    bool is_not_fail = !is_pass;

    cout << name << "是否为「及格且身高>1.70」：" << (is_good_student ? "是" : "否") << endl;
    cout << name << "是否有「数学>90」的优势：" << (has_advantage ? "是" : "否") << endl;
    cout << name << "是否不及格：" << (is_not_fail ? "是" : "否") << endl;


    cout << "\n=== 赋值运算示例 ===" << endl;
    int num = 5;
    num += 3;
    cout << "num += 3 后：" << num << endl;

    double weight = 65.0;
    weight -= 2.5;
    cout << name << "减重后的体重：" << weight << "公斤" << endl;


    cout << "\n=== 枚举类型示例 ===" << endl;
    cout << "今天是星期" << today + 1 << "（枚举值转整数：Wednesday为2，+1后显示3）" << endl;


    return 0;
}