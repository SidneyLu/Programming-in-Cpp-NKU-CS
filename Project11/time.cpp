//这里是类的具体实现
module time;//相当于#include "time.h"

import <string>;
import <stdexcept>;

using namespace time;//这可能是你第一次见到使用std以外的命名空间

Time::Time(int hour, int minute, int second) {
	if (hour < 0 || hour >= 24 || minute < 0 || minute >= 60 || second < 0 || second >= 60) {
		throw std::invalid_argument("Invalid time");
	}
	m_hour   = hour;
	m_minute = minute;
	m_second = second;
}

std::string Time::toString() const {
	return std::to_string(m_hour) + ":" + std::to_string(m_minute) + ":" + std::to_string(m_second);
}