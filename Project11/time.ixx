//在本文件中我们尝试将大家熟悉的类模块化
//这里是类的声明

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
