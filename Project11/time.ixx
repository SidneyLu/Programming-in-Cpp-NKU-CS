//�ڱ��ļ������ǳ��Խ������Ϥ����ģ�黯
//�������������

export module time;

import <string>;

export namespace time {

	class Time {
	private:
		int m_hour{0};
		int m_minute{0};
		int m_second{0};

	public:
		explicit Time(int hour = 0, int minute = 0, int second = 0);
		std::string toString() const;
	};

}
