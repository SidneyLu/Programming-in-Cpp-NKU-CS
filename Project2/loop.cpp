//循环结构

#include <iostream>

using namespace std;

int main() {
    // 1. for循环：适合已知循环次数的场景（初始化+条件+迭代器）
    cout << "=== for循环：输出1-5的数字 ===" << endl;
    for (int i = 1; i <= 5; i++) {  // 初始化i=1；当i<=5时循环；每次循环后i+1
        cout << i << " ";
    }
    cout << endl;

    // 2. while循环：适合未知循环次数，仅通过条件控制的场景
    cout << "=== while循环：计算1-10的累加和 ===" << endl;
    int sum = 0;
    int num = 1;
    while (num <= 10) {  // 当num<=10时持续循环
        sum += num;      // 累加当前数字
        num++;           // 手动更新循环变量（避免死循环）
    }
    cout << "累加和：" << sum << endl;

    // 3. do-while循环：适合至少需要执行一次的场景（先执行后判断）
    cout << "=== do-while循环：用户输入验证 ===" << endl;
    int password;
    do {  // 先执行一次输入操作
        cout << "请输入密码（123456）：";
        cin >> password;
    } while (password != 123456);  // 密码不正确则重复输入
    cout << "密码正确，登录成功！" << endl;

	//基于范围的for循环C++11引入，我们和C++20的Ranges一起介绍 
    return 0;
}
