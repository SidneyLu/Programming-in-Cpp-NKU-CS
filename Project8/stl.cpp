#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <numeric>
#include <iterator>

// 自定义仿函数：检查偶数
struct IsEven { bool operator()(int n) const { return n % 2 == 0; } };

// 通用打印函数（简化版）
template <typename Container>
void print(const std::string& label, const Container& c) {
    std::cout << label << ": ";
    for (const auto& x : c) std::cout << x << " ";
    std::cout << "\n";
}

// 打印键值对容器
template <typename Map>
void printMap(const std::string& label, const Map& m) {
    std::cout << label << ": ";
    for (const auto& [k, v] : m) std::cout << "[" << k << ":" << v << "] ";
    std::cout << "\n";
}

int main() {
    // 1. 序列容器：vector（最常用动态数组）
    std::vector<int> vec = { 3, 1, 4, 1, 5 };
    vec.push_back(9);
    std::sort(vec.begin(), vec.end());  // 排序算法
    print("vector（排序后）", vec);

    // 2. 关联容器：set（有序去重）
    std::set<int> s = { 5, 2, 5, 1 };
    s.insert(3);
    print("set", s);

    // 3. 键值对容器：map（有序）与unordered_map（无序哈希）
    std::map<std::string, int> scoreMap = { {"Alice", 90}, {"Bob", 85} };
    scoreMap["Charlie"] = 95;
    printMap("map", scoreMap);

    std::unordered_map<int, std::string> numMap = { {1, "one"}, {2, "two"} };
    printMap("unordered_map", numMap);

    // 4. 容器适配器：stack（栈）
    std::stack<int> stk;
    stk.push(10); stk.push(20);
    std::cout << "stack top: " << stk.top() << "\n";

    // 5. 算法示例
    std::vector<int> algoVec = { 1, 2, 3, 4, 5, 6 };

    // 查找
    auto found = std::find(algoVec.begin(), algoVec.end(), 4);
    std::cout << "find 4 at index: " << std::distance(algoVec.begin(), found) << "\n";

    // 计数（用仿函数）
    int evenCount = std::count_if(algoVec.begin(), algoVec.end(), IsEven());
    std::cout << "偶数个数: " << evenCount << "\n";

    // 转换（用lambda）
    std::vector<int> squared;
    std::transform(algoVec.begin(), algoVec.end(),
        std::back_inserter(squared),
        [](int x) { return x * x; });
    print("平方结果", squared);

    // 6. 反向迭代器
    std::cout << "反向遍历vector: ";
    for (auto it = vec.rbegin(); it != vec.rend(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    return 0;
}
