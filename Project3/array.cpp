//数组

#include <iostream>
#include <array> // 使用array
#include <vector> // 使用vector
#include <algorithm> // 使用sort和reverse

int main() {
	// 内置数组
	// 中括号加索引访问元素
	// 一维
	int arr1[5] = { 1, 2, 3, 4, 5 };// C++11引入的初始化器，有的书翻译叫作“大括号初始化”
	double arr2[3] = { 1.1, 2.2, 3.3 };
	char arr3[5] = { 'a', 'b', 'c', 'd', 'e' };

	std::cout << "arr1: ";
	for (int i = 0; i < 5; ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << "\narr2: ";
	for (int i = 0; i < 3; ++i) {
		std::cout << arr2[i] << " ";
	}//用for循环遍历数组元素，索引从0开始

	std::cout << "\narr3: ";
	std::cout << arr3 << std::endl; // char数组可以直接输出为字符串

	//二维
	int arr4[2][2] = { {1, 2}, {3, 4} };//二维数组
	//相当于一个一维数组，且每个元素都是一个一维数组
	//更高维以此类推，像积木一样搭起来——一个元素为n-1维数组的数组

	//用嵌套for循环遍历

	/*	
		如果你之前只学过Python，那么难受的来了：C++内置数组不支持动态调整大小
		声明时必须用常量指明大小,例如说int[n][n],n不能是变量,所以cin>>n是不行的
		动态内存分配，一种解决方案是使用指针，另一种请见下文
	*/

	// vector是C++STL中最常用的动态容器之一，名字叫向量然而并不原生支持向量运算
    std::cout << "\n\n===== std::vector 示例 =====" << std::endl;

    // 1. 初始化：动态大小，支持多种灵活初始化
    std::vector<int> vec1;                     // 空vector
    std::vector<int> vec2(3, 10);              // 3个元素，均为10
    std::vector<int> vec3{ 1, 2, 3, 4 };         // 列表初始化
    std::vector<int> vec4(vec3.begin(), vec3.end());  // 用迭代器范围初始化
    std::vector<int> vec5 = std::move(vec4);   // 移动构造（避免拷贝）

    // 2. 元素访问
    std::cout << "\n元素访问：" << std::endl;
    std::cout << "vec3[1] = " << vec3[1] << std::endl;
    std::cout << "vec3.at(2) = " << vec3.at(2) << std::endl;
    std::cout << "vec3.front() = " << vec3.front() << std::endl;
    std::cout << "vec3.back() = " << vec3.back() << std::endl;

    // 3. 动态添加元素：尾部添加（高效）
    std::cout << "\n添加元素：" << std::endl;
    vec1.push_back(20);              // 添加已有元素（可能产生拷贝）
    vec1.emplace_back(30);           // 直接构造元素（更高效，C++11起）
    vec1.push_back(10);
    std::cout << "添加后vec1大小：" << vec1.size() << std::endl;

    // 4. 容量管理：size（实际元素数）与capacity（已分配空间）
    std::cout << "\n容量管理：" << std::endl;
    std::cout << "vec1大小：" << vec1.size() << ", 容量：" << vec1.capacity() << std::endl;
    vec1.reserve(10);  // 预分配容量（避免频繁扩容）
    std::cout << "reserve后容量：" << vec1.capacity() << std::endl;
    vec1.shrink_to_fit();  // 收缩容量以匹配大小（C++11起）
    std::cout << "shrink后容量：" << vec1.capacity() << std::endl;

    // 5. 元素修改：插入、删除、清空
    std::cout << "\n修改操作：" << std::endl;
    vec3.insert(vec3.begin() + 2, 99);  // 在索引2处插入99
    vec3.erase(vec3.end() - 1);         // 删除最后一个元素
    std::cout << "插入删除后vec3大小：" << vec3.size() << std::endl;

    vec5.clear();  // 清空所有元素（size变为0，capacity不变）
    std::cout << "clear后vec5大小：" << vec5.size() << ", 容量：" << vec5.capacity() << std::endl;

    // 6. 排序与反转：配合<algorithm>库算法
    std::cout << "\n排序与反转：" << std::endl;
    std::sort(vec1.begin(), vec1.end());  // 升序排序
    std::reverse(vec1.begin(), vec1.end());// 反转元素
    std::cout << "排序反转后vec1：";
    for (int num : vec1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 7. 动态调整大小
    std::cout << "\n调整大小：" << std::endl;
    vec2.resize(5);  // 扩大到5个元素（新增元素为0）
    vec2.resize(2);  // 缩小到2个元素（删除后面的元素）
    std::cout << "resize后vec2大小：" << vec2.size() << std::endl;


    // 现代C++中，也经常使用array替代内置数组
    std::cout << "===== std::array 示例 =====" << std::endl;

    // 1. 初始化：必须指定大小，支持多种初始化方式
    std::array<int, 5> arr5;                  // 默认初始化（元素值不确定）
    std::array<int, 5> arr6 = { 1, 2, 3 };      // 部分初始化（剩余元素为0）
    std::array<int, 5> arr7{ 4, 5, 6, 7, 8 };   // 列表初始化（C++11起）
    const std::array<int, 3> arr8{ 10, 20, 30 };// 常量array（元素不可修改）

    // 2. 元素访问：4种方式（带边界检查和不带检查）
    std::cout << "\n元素访问：" << std::endl;
    std::cout << "arr7[0] = " << arr7[0] << std::endl;          // 无边界检查（快速）
    std::cout << "arr7.at(1) = " << arr7.at(1) << std::endl;    // 有边界检查（安全，越界抛异常）
    std::cout << "arr7.front() = " << arr7.front() << std::endl;// 第一个元素
    std::cout << "arr7.back() = " << arr7.back() << std::endl;  // 最后一个元素

    // 3. 容量相关：size固定，与max_size相等
    std::cout << "\n容量信息：" << std::endl;
    std::cout << "大小：" << arr7.size() << ", 最大容量：" << arr7.max_size() << std::endl;
    std::cout << "是否为空：" << (arr7.empty() ? "是" : "否") << std::endl;

    // 4. 元素修改：直接赋值或批量填充
    std::cout << "\n修改元素：" << std::endl;
    arr5.fill(9);  // 所有元素填充为9
    arr7[2] = 99;  // 修改单个元素
    std::cout << "修改后arr7[2] = " << arr7[2] << std::endl;

    // 5. 交换两个array（必须同类型同大小）
    std::array<int, 5> arr9{ 100, 200, 300, 400, 500 };
    std::cout << "\n交换前arr6[0] = " << arr6[0] << ", arr9[0] = " << arr9[0] << std::endl;
    arr6.swap(arr9);
    std::cout << "交换后arr6[0] = " << arr6[0] << ", arr9[0] = " << arr9[0] << std::endl;

    // 6. 底层数组访问：通过data()获取指针（兼容C风格接口）
    int* arr_ptr = arr7.data();
    std::cout << "通过指针访问arr7[3] = " << arr_ptr[3] << std::endl;

	return 0;
}