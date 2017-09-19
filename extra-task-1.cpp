#include <cassert>
#include <cmath>
#include <iostream>

double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
	assert(0 <= minutes < 60);
	assert(0 <= seconds < 60);
	return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	return modf(hours, &hours) + int(hours) % 24;
}

int get_hours(int seconds)
{
	return seconds / 3600;
}

int get_minutes(int seconds)
{
	return seconds % 3600 / 60;
}

int get_seconds(int seconds)
{
	return seconds % 3600 % 60;
}


double time_to_utc(int utc_offset, double time)
{
	return modf(time, &time) + (int(time) - utc_offset) % 24;
}

double time_from_utc(int utc_offset, double time)
{
	return modf(time, &time) + (24 + utc_offset + int(time)) % 24;
}
