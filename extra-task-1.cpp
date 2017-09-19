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
    /*
        Return UTC time in time zone utc_offset.

        >>> time_from_utc(+0, 12.0)
        12.0
 
        >>> time_from_utc(+1, 12.0)
        13.0
 
        >>> time_from_utc(-1, 12.0)
        11.0
 
        >>> time_from_utc(+6, 6.0)
        12.0
 
        >>> time_from_utc(-7, 6.0)
        23.0
 
        >>> time_from_utc(-1, 0.0)
        23.0
 
        >>> time_from_utc(-1, 23.0)
        22.0
 
        >>> time_from_utc(+1, 23.0)
        0.0
    */
}
