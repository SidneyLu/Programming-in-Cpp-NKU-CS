//ѭ���ṹ

#include <iostream>

using namespace std;

int main() {
    // 1. forѭ�����ʺ���֪ѭ�������ĳ�������ʼ��+����+��������
    cout << "=== forѭ�������1-5������ ===" << endl;
    for (int i = 1; i <= 5; i++) {  // ��ʼ��i=1����i<=5ʱѭ����ÿ��ѭ����i+1
        cout << i << " ";
    }
    cout << endl;

    // 2. whileѭ�����ʺ�δ֪ѭ����������ͨ���������Ƶĳ���
    cout << "=== whileѭ��������1-10���ۼӺ� ===" << endl;
    int sum = 0;
    int num = 1;
    while (num <= 10) {  // ��num<=10ʱ����ѭ��
        sum += num;      // �ۼӵ�ǰ����
        num++;           // �ֶ�����ѭ��������������ѭ����
    }
    cout << "�ۼӺͣ�" << sum << endl;

    // 3. do-whileѭ�����ʺ�������Ҫִ��һ�εĳ�������ִ�к��жϣ�
    cout << "=== do-whileѭ�����û�������֤ ===" << endl;
    int password;
    do {  // ��ִ��һ���������
        cout << "���������루123456����";
        cin >> password;
    } while (password != 123456);  // ���벻��ȷ���ظ�����
    cout << "������ȷ����¼�ɹ���" << endl;

	//���ڷ�Χ��forѭ��C++11���룬���Ǻ�C++20��Rangesһ����� 
    return 0;
}
