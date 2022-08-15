#ifndef TINYHTTP_UTIL_TIMESTAMP_H
#define TINYHTTP_UTIL_TIMESTAMP_H

#include <time.h>
#include <string>

class Timestamp {
public:
	explicit Timestamp(time_t microseconds_since_epoch);

	// default copy/assignment/dtor are ok

	time_t getMicroSecondsSinceEpoch() const;

	static Timestamp now();

	std::string formatStr(bool show_microsecond);

	static const int kMicroSecondsPerSecond = 1000 * 1000;
private:
	time_t microseconds_since_epoch_;

};

double timeDifference(const Timestamp &high, const Timestamp &low);
#endif  // TINYHTTP_UTIL_TIMESTAMP_H
