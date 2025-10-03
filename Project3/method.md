# 一、std::array 成员函数表格
| 成员函数       | 功能描述                                   
|----------------|-----------------------------------------|
| begin()        | 返回指向第一个元素的迭代器                 | 
| end()          | 返回指向最后一个元素之后位置的迭代器        | 
| rbegin()       | 返回反向迭代器（指向最后一个元素）          | 
| size()         | 返回容器中元素的数量（固定为模板参数N）     | 
| max_size()     | 返回容器可容纳元素的最大数量（等于size()）  |
| empty()        | 判断容器是否为空（size()==0时返回true）    | 
| at(n)          | 返回索引n处元素的引用，进行边界检查         | 
| operator[]     | 返回索引n处元素的引用，不进行边界检查       | 
| front()        | 返回第一个元素的引用                       |
| data()         | 返回指向底层数组的指针                     | 
| fill(val)      | 将所有元素设置为val                       | 
| swap(arr)      | 交换两个array的内容（需同类型同大小）       | 


# 二、std::vector 成员函数表格
| 成员函数       | 功能描述                                   | 
|----------------|------------------------------------------ |
| begin()        | 返回指向第一个元素的迭代器                  | 
| end()          | 返回指向最后一个元素之后位置的迭代器         | 
| rbegin()       | 返回反向迭代器（指向最后一个元素）           | 
| size()         | 返回当前元素数量                           | 
| capacity()     | 返回已分配的内存容量                       | 
| empty()        | 判断容器是否为空                           | 
| at(n)          | 返回索引n处元素的引用，进行边界检查          | 
| operator[]     | 返回索引n处元素的引用，不进行边界检查        | 
| front()        | 返回第一个元素的引用                        |  
| back()         | 返回最后一个元素的引用                      | 
| data()         | 返回指向底层数组的指针（C++11起）           |
| push_back(val) | 在末尾添加元素                             | 
| emplace_back(args) | 在末尾直接构造元素（避免临时对象）       |
| pop_back()     | 删除末尾元素                               | 
| insert(pos, val) | 在指定位置插入元素                       | 
| erase(pos)     | 删除指定位置的元素                         | 
| clear()        | 清空所有元素（容量不变）                    | 
| resize(n)      | 调整大小为n，超出部分用默认值填充            | 
| reserve(n)     | 预留至少n个元素的存储空间                   | 
| shrink_to_fit() | 请求减少容量以适应大小（不保证）            | 

# 三、std::string 成员函数表格

| 成员函数 | 功能描述 |
|----------|----------|
| string() | 默认构造，创建空字符串 |
| string(const char* s) | 从C风格字符串（如"hello"）构造string |
| string(const string& s) | 拷贝构造，创建另一个string的副本 |
| operator=(const string& s) | 赋值运算符，将另一个string的内容赋给当前字符串 |
| operator[](size_t pos) | 返回索引pos处的字符引用，不做边界检查（快速访问） |
| at(size_t pos) | 返回索引pos处的字符引用，做边界检查（越界抛out_of_range异常） |
| front() | 返回字符串第一个字符的引用 |
| back() | 返回字符串最后一个字符的引用 |
| c_str() | 返回指向以'\0'结尾的底层C风格字符串指针（兼容printf等C接口） |
| size() / length() | 两者功能一致，返回字符串的字符个数（不含末尾的'\0'） |
| empty() | 判断字符串是否为空（size() == 0时返回true） |
| reserve(size_t n) | 预分配至少n个字符的存储空间，避免频繁扩容 |
| resize(size_t n) | 调整字符串长度为n：n大于当前长度则用'\0'填充，n小于则截断尾部 |
| operator+=(const string& s) | 在当前字符串末尾追加另一个string（简洁常用） |
| push_back(char c) | 在字符串末尾添加单个字符（高效） |
| append(const string& s) | 在当前字符串末尾追加另一个string（支持多类型参数重载） |
| erase(size_t pos = 0, size_t len = npos) | 从pos开始删除len个字符；默认从开头删除所有字符（npos为默认最大值） |
| clear() | 清空字符串（size()变为0，容量不变） |
| replace(size_t pos, size_t len, const string& s) | 从pos开始删除len个字符，并插入s（快速替换子串） |
| operator== / != | 按字典序判断两个字符串是否相等/不相等 |
| find(const string& s, size_t pos = 0) | 从pos开始查找s第一次出现的位置，找到返回索引，未找到返回npos |
| substr(size_t pos = 0, size_t len = npos) | 返回从pos开始、长度为len的子串；默认从开头取到末尾 |
| swap(string& s) | 交换当前字符串与另一个string的内容（无内存拷贝，效率高） |