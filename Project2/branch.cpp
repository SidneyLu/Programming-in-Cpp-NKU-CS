//��֧�ṹ

#include <iostream>

using namespace std;

int main() {
    // 1. if-else��䣺�����ѡһ�߼�
    int score = 85;
    if (score >= 60) {
        cout << "�ɼ��ϸ�" << endl;  // ��������ʱִ��
    }
    else {
        cout << "�ɼ����ϸ�" << endl;  // ����������ʱִ��
	}
    //ע�����ֱȽ������==�͸�ֵ�����=

    // 2. if-else if-else��䣺�����������֧
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
        grade = 'D';  // ��������������ʱ��Ĭ�����
    }
    //C++������Python���������ִ���飬������Ϊ�˴���Ŀɶ��ԣ�������Դ����Ż���
	//���ô�������ʽ���������ֻ�ܿ����������ڵĺ�һ�����
    //ע��if-else��ƥ��
    cout << "�ȼ�������" << grade << endl;

    // 3. switch��䣺������ɢֵƥ�䣨�ʺ�ö�١��������ַ��ȣ�
    int menuChoice;
    cout << "\n��ѡ�������1-3����";
    cin >> menuChoice;

    switch (menuChoice) {
    case 1:  // ��menuChoiceΪ1ʱִ��
        cout << "ִ����Ӳ���" << endl;
        break;  // ����switch���������ִ�к���case
    case 2:  // ��menuChoiceΪ2ʱִ��
        cout << "ִ��ɾ������" << endl;
        break;
    case 3:  // ��menuChoiceΪ3ʱִ��
        cout << "ִ�в�ѯ����" << endl;
        break;
    default:  // ����case��ƥ��ʱ��Ĭ�ϲ���
        cout << "��Чѡ��" << endl;
	}
    //�ӵ�һ��ƥ���ʼ����ִ�У�ֱ������break��switch����
	//�ںܶ�ʱ������break�ᵼ���߼�������Ϊ�����ֻ���ѡһ������������������������������׳����档
	//�����ȷʵ��Ҫֱͨ��һ��case��C++17������[[fallthrough]]���ԣ���ʽ�������ᴩ��Ϊ����������ɶ��ԺͰ�ȫ�ԡ�
    //��[[fallthrough]];�滻break;


    /*
		C++17������������֧���ĳ�ʼ���﷨��������if��switch�������������ʼ��������
		�����ı�������������ڸ������ڣ������˴���Ŀɶ��ԡ�
        Ҳ�����ĳЩ���ʽ�޷�ֱ����Ϊ��ֵ�����ڵȺ���ߣ�����Ƚϵ��鷳��
    */

    return 0;
}