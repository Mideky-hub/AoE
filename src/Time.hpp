#ifndef TIME_HPP
#define TIME_HPP

#include <string>

enum Days {
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

enum Months {
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

struct Time {
	uint64_t hour;
	uint64_t minute;
	uint64_t second;
};

struct Date {
	Days day;
	Months month;
	uint64_t year;
};

__interface ITimeManager {
public:
	virtual Time get_time() noexcept = 0;
	virtual Date get_date() noexcept = 0;
	virtual std::string get_time_string() const noexcept = 0;
	virtual std::string get_date_string() const noexcept = 0;
	virtual std::string get_date_time_string() const noexcept = 0;
	virtual bool isDateValid(Date date) const noexcept = 0;
	virtual bool isTimeValid(Time time) const noexcept = 0;
	virtual bool isDateTimeValid(Date date, Time time) const noexcept = 0;
};

class TimeManager {
private:
	Time time;
	Date date;
public:
	
};
	

#endif // !TIME_HPP