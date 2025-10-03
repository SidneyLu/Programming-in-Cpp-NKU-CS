//��������ľ���ʵ��
module time;//�൱��#include "time.h"

import <string>;
import <stdexcept>;

using namespace time;//����������һ�μ���ʹ��std����������ռ�

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