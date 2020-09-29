#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <exception>

const int MAX_DAYS_IN_MONTH[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date;
class TimeDifference;

class Time_Moment {
protected:
	int day = 0;
	int month = 0;
	int year = 0;

	int hour = 0;
	int minute = 0;
	int second = 0;

	int UTC = 0;

	Time_Moment normalize()const;
public:
	Time_Moment() {}
	explicit Time_Moment(int day, int month, int year,
		int hour, int minute, int second, int UTC = 0)
		: day(day),
		month(month),
		year(year),
		hour(hour),
		minute(minute),
		second(second),
		UTC(UTC)
	{}

	inline int getDay() const { return day; }
	inline int getMonth() const { return month; }
	inline int getYear() const { return year; }
	inline int getHour() const { return hour; }
	inline int getMinute() const { return minute; }
	inline int getSecond() const { return second; }

	bool operator<(const Time_Moment& rhs) const;
	bool operator>(const Time_Moment& rhs) const;
	bool operator==(const Time_Moment& rhs) const;

	TimeDifference operator-(const Time_Moment& rhs);
};

class Date : public Time_Moment {
	void makeRandomDate();
	int getDayOfWeekNumber() const;
public:
	Date() { makeRandomDate(); };
	explicit Date(int day, int month, int year,
		int hour, int minute, int second, int UTC = 0)
		: Time_Moment(day, month, year, hour, minute, second, UTC)
	{
		if (!isValid())
			throw std::invalid_argument("Invalid date!");
	}

	std::string getWeekday()const;

	int getWeekNumberInYear() const;
	//int getWeekNumberInMonth() const;

	bool isValid()const;

	Date operator+(const TimeDifference& diff) const;
	Date operator+=(const TimeDifference& diff);

	Date operator-(const TimeDifference& diff) const;
	Date operator-=(const TimeDifference& diff);

	TimeDifference operator-(const Date& rhs) const;

	friend std::ostream& operator<<(std::ostream& stream, const Date& date);
	friend std::istream& operator>>(std::istream& stream, Date& date);
};

class TimeDifference : public Time_Moment {
public:
	static TimeDifference week;
	explicit TimeDifference(int day, int month, int year, int hour, int minute, int second)
		: Time_Moment(day, month, year, hour, minute, second) {
		if (!isValid())
			throw std::invalid_argument("Invalid time difference!");
	}
	explicit TimeDifference(const Time_Moment& moment1, const Time_Moment& moment2);

	bool isValid();
};