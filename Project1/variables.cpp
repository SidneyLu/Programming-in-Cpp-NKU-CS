#include <iostream> 
#include <string> //����string��
using namespace std;

int main() {
    //����
    int age = 20;//��ֵ��ʼ��
    int student_id{ 2500000 };//���ų�ʼ�� C++11�����������

    //˫���ȸ�����
    double math_score = 89.5;
    double height{ 1.75 };

    //�ַ���
    char gender = 'M';//�����ţ�Ĭ��ʹ��ASCII
    char grade_char{ 'A' };

    //������
    bool is_pass = (math_score >= 60);

    //�ַ�����
    string name = "����";
    string major{ "�������ѧ�뼼��" };

    //ö����
    //��һ��δ�ֶ���ֵ��ȡ0���������ε���1
	//���ж���ֶ���ֵ��Ԫ�أ�����δ��ֵ�Ĵ����һ���ֶ�����ֵ��ʼ����
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

    //ǿ������ת��
	int truncated_height = static_cast<int>(height); //��doubleת��Ϊint���ض�С������

    cout << "=== ��������ʾ�� ===" << endl;
    //�Ӽ��˳���%������ȡ����
    double total_score = math_score + 92.0;
    int year_diff = 2024 - 2004;
    int remainder = 10 % 3;
    double average_score = total_score / 2;

    cout << name << "���ܷ֣�" << total_score << endl;
    cout << name << "�����䣨����ֵ����" << year_diff << endl;
    cout << "10 % 3 = " << remainder << endl;
    cout << name << "��ƽ���ɼ���" << average_score << endl;
	//string��������+����������������ַ���
	string title = name + "ͬѧ";

    cout << "\n=== �����Լ�����ʾ�� ===" << endl;
    //ǰ׺�Ӽ���ֱ���ã���׺�����ټӼ�
    //���һ������ڳ����������������ã������޲��
    int count = 5;
    cout << "ǰ��++count����+1���������" << ++count << endl;
    cout << "������count��ֵ��" << count << endl;

    int lesson_num = 2;
    cout << "����lesson_num++���������+1����" << lesson_num++ << endl;
    cout << "������lesson_num��ֵ��" << lesson_num << endl;

    int remaining = 4;
    cout << "ǰ��--remaining����-1���������" << --remaining << endl;
    cout << "����remaining--���������-1����" << remaining-- << endl;
    cout << "����remaining��ֵ��" << remaining << endl;


    cout << "\n=== ��ϵ����ʾ�� ===" << endl;
	//��ϵ������Ϊ����ֵtrue��false
    //���ڡ�С�ڡ����ڡ������ڡ���
	//ע�⣺C++�бȽ��ַ���������==��Ҫ��string��ĳ�Ա����compare()
    //���ǡ��ͷ���1�����򷵻�0
    bool is_excellent = (math_score >= 90);
    bool is_same_grade = (grade_char == 'A');
    bool is_taller = (height > 1.70);

	//��Ԫ����� ? :
	//�ṹ����������������Ϊ��ʱ��ֵ����������Ϊ��ʱ��ֵ��
    cout << name << "��ѧ�Ƿ����㣺" << (is_excellent ? "��" : "��") << endl;
    cout << name << "�ɼ��ȼ��Ƿ�ΪA��" << (is_same_grade ? "��" : "��") << endl;
    cout << name << "����Ƿ񳬹�1.70�ף�" << (is_taller ? "��" : "��") << endl;


    cout << "\n=== �߼�����ʾ�� ===" << endl;
	//�߼���&&����||����!
    //˵��and or notӦ�ø������
    bool is_good_student = (is_pass && is_taller);
    bool has_advantage = (math_score > 90);
    bool is_not_fail = !is_pass;

    cout << name << "�Ƿ�Ϊ�����������>1.70����" << (is_good_student ? "��" : "��") << endl;
    cout << name << "�Ƿ��С���ѧ>90�������ƣ�" << (has_advantage ? "��" : "��") << endl;
    cout << name << "�Ƿ񲻼���" << (is_not_fail ? "��" : "��") << endl;


    cout << "\n=== ��ֵ����ʾ�� ===" << endl;
    int num = 5;
    num += 3;
    cout << "num += 3 ��" << num << endl;

    double weight = 65.0;
    weight -= 2.5;
    cout << name << "���غ�����أ�" << weight << "����" << endl;


    cout << "\n=== ö������ʾ�� ===" << endl;
    cout << "����������" << today + 1 << "��ö��ֵת������WednesdayΪ2��+1����ʾ3��" << endl;


    return 0;
}