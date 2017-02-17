#ifndef EX_DATE_H
#define EX_DATE_H

#include <iostream>
#include <vector>

class Date {
	friend std::ostream& operator<<(std::ostream &os, const Date &d);
	friend std::istream& operator>>(std::istream &is, Date &d);
	friend bool operator==(const Date &lhs, const Date &rhs);
	friend bool operator!=(const Date &lhs, const Date &rhs);
	friend bool operator<(const Date &lhs, const Date &rhs);
	friend bool operator<=(const Date &lhs, const Date &rhs);
	friend bool operator>(const Date &lhs, const Date &rhs);
	friend bool operator>=(const Date &lhs, const Date &rhs);

public:
	Date(unsigned d, unsigned m, unsigned y) :
		day(d), month(m), year(y) {}
	Date() = default;
	Date& operator=(const Date& d);
	explicit operator bool() const;
	bool isLeapYear() const;

private:
	unsigned day;
	unsigned month;
	unsigned year;
};

std::ostream& operator<<(std::ostream &os, const Date &d) {
	os << d.day << "." << d.month << "." << d.year;
	return os;
}

std::istream& operator>>(std::istream &is, Date &d) {
	is >> d.day >> d.month >> d.year;
	if (!is)
		d = Date();
	return is;
}

bool operator==(const Date &lhs, const Date &rhs) {
	return (lhs.day == rhs.day &&
		lhs.month == rhs.month && lhs.year == rhs.year);
}

bool operator!=(const Date &lhs, const Date &rhs) {
	return !(lhs == rhs);
}

bool operator<(const Date &lhs, const Date &rhs) {
	return (lhs.year < rhs.year) ||
		(lhs.year == rhs.year && lhs.month < rhs.month) ||
		(lhs.year == rhs.year && lhs.month == rhs.month && lhs.day < rhs.day);
}

bool operator<=(const Date &lhs, const Date &rhs) {
	return (lhs < rhs) || (lhs == rhs);
}

bool operator>(const Date &lhs, const Date &rhs) {
	return !(lhs <= rhs);
}

bool operator>=(const Date &lhs, const Date &rhs) {
	return !(lhs < rhs);
}

Date& Date::operator=(const Date& d) {
	day = d.day;
	month = d.month;
	year = d.year;
	return *this;
}

Date::operator bool() const {
	std::vector<std::vector<int>> days_per_month = {
		{ 31,28,31,30,31,30,31,31,30,31,30,31 },
		{ 31,29,31,30,31,30,31,31,30,31,30,31 }
	};

	return 1 <= month && month <= 12 && 1 <= day && day <=
		days_per_month[isLeapYear() ? 1 : 0][month - 1];
}

bool Date::isLeapYear() const {
	return (year % 4 == 0 && year % 100 != 0) ||
		(year % 400 == 0);
}

#endif