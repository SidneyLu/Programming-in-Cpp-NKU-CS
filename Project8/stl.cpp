#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <numeric>
#include <iterator>

// �Զ���º��������ż��
struct IsEven { bool operator()(int n) const { return n % 2 == 0; } };

// ͨ�ô�ӡ�������򻯰棩
template <typename Container>
void print(const std::string& label, const Container& c) {
    std::cout << label << ": ";
    for (const auto& x : c) std::cout << x << " ";
    std::cout << "\n";
}

// ��ӡ��ֵ������
template <typename Map>
void printMap(const std::string& label, const Map& m) {
    std::cout << label << ": ";
    for (const auto& [k, v] : m) std::cout << "[" << k << ":" << v << "] ";
    std::cout << "\n";
}

int main() {
    // 1. ����������vector����ö�̬���飩
    std::vector<int> vec = { 3, 1, 4, 1, 5 };
    vec.push_back(9);
    std::sort(vec.begin(), vec.end());  // �����㷨
    print("vector�������", vec);

    // 2. ����������set������ȥ�أ�
    std::set<int> s = { 5, 2, 5, 1 };
    s.insert(3);
    print("set", s);

    // 3. ��ֵ��������map��������unordered_map�������ϣ��
    std::map<std::string, int> scoreMap = { {"Alice", 90}, {"Bob", 85} };
    scoreMap["Charlie"] = 95;
    printMap("map", scoreMap);

    std::unordered_map<int, std::string> numMap = { {1, "one"}, {2, "two"} };
    printMap("unordered_map", numMap);

    // 4. ������������stack��ջ��
    std::stack<int> stk;
    stk.push(10); stk.push(20);
    std::cout << "stack top: " << stk.top() << "\n";

    // 5. �㷨ʾ��
    std::vector<int> algoVec = { 1, 2, 3, 4, 5, 6 };

    // ����
    auto found = std::find(algoVec.begin(), algoVec.end(), 4);
    std::cout << "find 4 at index: " << std::distance(algoVec.begin(), found) << "\n";

    // �������÷º�����
    int evenCount = std::count_if(algoVec.begin(), algoVec.end(), IsEven());
    std::cout << "ż������: " << evenCount << "\n";

    // ת������lambda��
    std::vector<int> squared;
    std::transform(algoVec.begin(), algoVec.end(),
        std::back_inserter(squared),
        [](int x) { return x * x; });
    print("ƽ�����", squared);

    // 6. ���������
    std::cout << "�������vector: ";
    for (auto it = vec.rbegin(); it != vec.rend(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    return 0;
}
