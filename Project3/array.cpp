//����

#include <iostream>
#include <array> // ʹ��array
#include <vector> // ʹ��vector
#include <algorithm> // ʹ��sort��reverse

int main() {
	// ��������
	// �����ż���������Ԫ��
	// һά
	int arr1[5] = { 1, 2, 3, 4, 5 };// C++11����ĳ�ʼ�������е��鷭������������ų�ʼ����
	double arr2[3] = { 1.1, 2.2, 3.3 };
	char arr3[5] = { 'a', 'b', 'c', 'd', 'e' };

	std::cout << "arr1: ";
	for (int i = 0; i < 5; ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << "\narr2: ";
	for (int i = 0; i < 3; ++i) {
		std::cout << arr2[i] << " ";
	}//��forѭ����������Ԫ�أ�������0��ʼ

	std::cout << "\narr3: ";
	std::cout << arr3 << std::endl; // char�������ֱ�����Ϊ�ַ���

	//��ά
	int arr4[2][2] = { {1, 2}, {3, 4} };//��ά����
	//�൱��һ��һά���飬��ÿ��Ԫ�ض���һ��һά����
	//����ά�Դ����ƣ����ľһ������������һ��Ԫ��Ϊn-1ά���������

	//��Ƕ��forѭ������

	/*	
		�����֮ǰֻѧ��Python����ô���ܵ����ˣ�C++�������鲻֧�ֶ�̬������С
		����ʱ�����ó���ָ����С,����˵int[n][n],n�����Ǳ���,����cin>>n�ǲ��е�
		��̬�ڴ���䣬һ�ֽ��������ʹ��ָ�룬��һ���������
	*/

	// vector��C++STL����õĶ�̬����֮һ�����ֽ�����Ȼ������ԭ��֧����������
    std::cout << "\n\n===== std::vector ʾ�� =====" << std::endl;

    // 1. ��ʼ������̬��С��֧�ֶ�������ʼ��
    std::vector<int> vec1;                     // ��vector
    std::vector<int> vec2(3, 10);              // 3��Ԫ�أ���Ϊ10
    std::vector<int> vec3{ 1, 2, 3, 4 };         // �б��ʼ��
    std::vector<int> vec4(vec3.begin(), vec3.end());  // �õ�������Χ��ʼ��
    std::vector<int> vec5 = std::move(vec4);   // �ƶ����죨���⿽����

    // 2. Ԫ�ط���
    std::cout << "\nԪ�ط��ʣ�" << std::endl;
    std::cout << "vec3[1] = " << vec3[1] << std::endl;
    std::cout << "vec3.at(2) = " << vec3.at(2) << std::endl;
    std::cout << "vec3.front() = " << vec3.front() << std::endl;
    std::cout << "vec3.back() = " << vec3.back() << std::endl;

    // 3. ��̬���Ԫ�أ�β����ӣ���Ч��
    std::cout << "\n���Ԫ�أ�" << std::endl;
    vec1.push_back(20);              // �������Ԫ�أ����ܲ���������
    vec1.emplace_back(30);           // ֱ�ӹ���Ԫ�أ�����Ч��C++11��
    vec1.push_back(10);
    std::cout << "��Ӻ�vec1��С��" << vec1.size() << std::endl;

    // 4. ��������size��ʵ��Ԫ��������capacity���ѷ���ռ䣩
    std::cout << "\n��������" << std::endl;
    std::cout << "vec1��С��" << vec1.size() << ", ������" << vec1.capacity() << std::endl;
    vec1.reserve(10);  // Ԥ��������������Ƶ�����ݣ�
    std::cout << "reserve��������" << vec1.capacity() << std::endl;
    vec1.shrink_to_fit();  // ����������ƥ���С��C++11��
    std::cout << "shrink��������" << vec1.capacity() << std::endl;

    // 5. Ԫ���޸ģ����롢ɾ�������
    std::cout << "\n�޸Ĳ�����" << std::endl;
    vec3.insert(vec3.begin() + 2, 99);  // ������2������99
    vec3.erase(vec3.end() - 1);         // ɾ�����һ��Ԫ��
    std::cout << "����ɾ����vec3��С��" << vec3.size() << std::endl;

    vec5.clear();  // �������Ԫ�أ�size��Ϊ0��capacity���䣩
    std::cout << "clear��vec5��С��" << vec5.size() << ", ������" << vec5.capacity() << std::endl;

    // 6. �����뷴ת�����<algorithm>���㷨
    std::cout << "\n�����뷴ת��" << std::endl;
    std::sort(vec1.begin(), vec1.end());  // ��������
    std::reverse(vec1.begin(), vec1.end());// ��תԪ��
    std::cout << "����ת��vec1��";
    for (int num : vec1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 7. ��̬������С
    std::cout << "\n������С��" << std::endl;
    vec2.resize(5);  // ����5��Ԫ�أ�����Ԫ��Ϊ0��
    vec2.resize(2);  // ��С��2��Ԫ�أ�ɾ�������Ԫ�أ�
    std::cout << "resize��vec2��С��" << vec2.size() << std::endl;


    // �ִ�C++�У�Ҳ����ʹ��array�����������
    std::cout << "===== std::array ʾ�� =====" << std::endl;

    // 1. ��ʼ��������ָ����С��֧�ֶ��ֳ�ʼ����ʽ
    std::array<int, 5> arr5;                  // Ĭ�ϳ�ʼ����Ԫ��ֵ��ȷ����
    std::array<int, 5> arr6 = { 1, 2, 3 };      // ���ֳ�ʼ����ʣ��Ԫ��Ϊ0��
    std::array<int, 5> arr7{ 4, 5, 6, 7, 8 };   // �б��ʼ����C++11��
    const std::array<int, 3> arr8{ 10, 20, 30 };// ����array��Ԫ�ز����޸ģ�

    // 2. Ԫ�ط��ʣ�4�ַ�ʽ�����߽���Ͳ�����飩
    std::cout << "\nԪ�ط��ʣ�" << std::endl;
    std::cout << "arr7[0] = " << arr7[0] << std::endl;          // �ޱ߽��飨���٣�
    std::cout << "arr7.at(1) = " << arr7.at(1) << std::endl;    // �б߽��飨��ȫ��Խ�����쳣��
    std::cout << "arr7.front() = " << arr7.front() << std::endl;// ��һ��Ԫ��
    std::cout << "arr7.back() = " << arr7.back() << std::endl;  // ���һ��Ԫ��

    // 3. ������أ�size�̶�����max_size���
    std::cout << "\n������Ϣ��" << std::endl;
    std::cout << "��С��" << arr7.size() << ", ���������" << arr7.max_size() << std::endl;
    std::cout << "�Ƿ�Ϊ�գ�" << (arr7.empty() ? "��" : "��") << std::endl;

    // 4. Ԫ���޸ģ�ֱ�Ӹ�ֵ���������
    std::cout << "\n�޸�Ԫ�أ�" << std::endl;
    arr5.fill(9);  // ����Ԫ�����Ϊ9
    arr7[2] = 99;  // �޸ĵ���Ԫ��
    std::cout << "�޸ĺ�arr7[2] = " << arr7[2] << std::endl;

    // 5. ��������array������ͬ����ͬ��С��
    std::array<int, 5> arr9{ 100, 200, 300, 400, 500 };
    std::cout << "\n����ǰarr6[0] = " << arr6[0] << ", arr9[0] = " << arr9[0] << std::endl;
    arr6.swap(arr9);
    std::cout << "������arr6[0] = " << arr6[0] << ", arr9[0] = " << arr9[0] << std::endl;

    // 6. �ײ�������ʣ�ͨ��data()��ȡָ�루����C���ӿڣ�
    int* arr_ptr = arr7.data();
    std::cout << "ͨ��ָ�����arr7[3] = " << arr_ptr[3] << std::endl;

	return 0;
}