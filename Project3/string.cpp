#include <iostream>
#include <string>
#include <algorithm> // 用于转换大小写等扩展操作

int main() {
    // 1. 字符串初始化（常用方式）
    std::string s1;                  // 空字符串
    std::string s2 = "hello";        // 从C风格字符串初始化
    std::string s3(3, 'a');          // 3个'a'组成的字符串（"aaa"）
    std::string s4 = s2;             // 拷贝构造（s4 = "hello"）
    std::cout << "初始化示例：s1=\"" << s1 << "\", s2=\"" << s2 << "\", s3=\"" << s3 << "\"\n\n";

    // 2. 元素访问
    std::cout << "s2[1] = " << s2[1] << "（不检查越界）\n";       // 用[]访问（高效，无边界检查）
    std::cout << "s2.at(2) = " << s2.at(2) << "（检查越界）\n";  // 用at()访问（越界抛异常）
    std::cout << "首字符：" << s2.front() << "，尾字符：" << s2.back() << "\n\n";  // C++11起支持

    // 3. 长度与判空
    std::cout << "s2长度：" << s2.size() << "（与length()等价）\n";  // size()和length()功能完全一致
    std::cout << "s1是否为空：" << (s1.empty() ? "是" : "否") << "\n\n";

    // 4. 字符串修改（拼接、插入、删除等）
    s2 += " world";  // 拼接字符串（最常用）
    std::cout << "拼接后s2：" << s2 << "\n";

    s2.append("!");  // 追加字符（与+=类似，支持更多参数重载）
    std::cout << "append后s2：" << s2 << "\n";

    s2.push_back('?');  // 追加单个字符（比append更高效）
    std::cout << "push_back后s2：" << s2 << "\n";

    s2.insert(5, " dear");  // 在索引5处插入字符串
    std::cout << "insert后s2：" << s2 << "\n";

    s2.erase(5, 5);  // 从索引5开始删除5个字符
    std::cout << "erase后s2：" << s2 << "\n";

    s2.replace(11, 1, "!!");  // 从索引11开始，替换1个字符为"!!"
    std::cout << "replace后s2：" << s2 << "\n\n";

    // 5. 查找与子串
    size_t pos = s2.find("world");  // 查找子串"world"的位置
    if (pos != std::string::npos) {  // npos表示未找到
        std::cout << "\"world\"的位置：" << pos << "\n";
        std::cout << "从pos开始的子串：" << s2.substr(pos, 5) << "\n";  // 从pos取5个字符
    }

    size_t last_pos = s2.rfind("l");  // 反向查找最后一个'l'的位置
    std::cout << "最后一个'l'的位置：" << last_pos << "\n\n";

    // 6. 字符串比较（字典序）
    std::string s5 = "hello world!";
    if (s2 == s5) {
        std::cout << "s2与s5相等\n";
    } else {
        std::cout << "s2与s5不相等（s2=\"" << s2 << "\", s5=\"" << s5 << "\"）\n";
    }

    // 7. 转换为C风格字符串（兼容C接口）
    const char* c_str = s2.c_str();
    std::cout << "\nC风格字符串：" << c_str << "（用于printf等C函数）\n";

    // 8. 扩展：转换大小写（需#include <algorithm>）
    std::string s6 = "Hello World";
    std::transform(s6.begin(), s6.end(), s6.begin(), ::toupper);  // 转大写
    std::cout << "\n转大写后：" << s6 << "\n";

    return 0;
}