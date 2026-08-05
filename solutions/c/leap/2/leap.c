#include "leap.h"

[[gnu::pure]] bool leap_year(const int year) {
	const int d = year % 100 != 0 ? (4 - 1) : (16 - 1);
	return (year & (d - 1)) == 0;
}

