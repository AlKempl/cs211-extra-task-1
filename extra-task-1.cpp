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

int main()
{
	//test 1
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON && "test-01-1");
	assert(fabs(seconds_difference(3600.0, 1800.0) - -1800.0) < DBL_EPSILON && "test-01-2");
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON && "test-01-3");
	assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON && "test-01-4");
	std::cout << "Test #1 has passed" << std::endl;

	//test 2
	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON && "test-02-1");
	assert(fabs(hours_difference(3600.0, 1800.0) - -0.5) < DBL_EPSILON && "test-02-2");
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON && "test-02-3");
	assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON && "test-02-4");
	std::cout << "Test #2 has passed" << std::endl;

	//test 3
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON && "test-03-1");
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON && "test-03-2");
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON && "test-03-3");
	std::cout << "Test #3 has passed" << std::endl;

	//test 4
	assert(fabs(to_24_hour_clock(24) - 0) < DBL_EPSILON && "test-04-1");
	assert(fabs(to_24_hour_clock(48) - 0) < DBL_EPSILON && "test-04-2");
	assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON && "test-04-3");
	assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON && "test-04-4");
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON && "test-04-5");
	std::cout << "Test #4 has passed" << std::endl;

	//test 5
	assert(get_hours(3800) == 1 && "test-05-1");
	assert(get_minutes(3800) == 3 && "test-05-2");
	assert(get_seconds(3800) == 20 && "test-05-3");
	std::cout << "Test #5 has passed" << std::endl;

	//test 6
	assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON && "test-06-1");
	assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON && "test-06-2");
	assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON && "test-06-3");
	assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON && "test-06-4");
	assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON && "test-06-5");
	assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON && "test-06-6");
	std::cout << "Test #6 has passed" << std::endl;

	//test 7
	assert(fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON && "test-07-1");
	assert(fabs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON && "test-07-2");
	assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON && "test-07-3");
	assert(fabs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON && "test-07-4");
	assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON && "test-07-5");
	assert(fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON && "test-07-6");
	assert(fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON && "test-07-7");
	assert(fabs(time_from_utc(+1, 23.0) - 0.0) < DBL_EPSILON && "test-07-8");
	std::cout << "Test #7 has passed" << std::endl;

	std::cout << "All tests have passed" << std::endl;
	system("pause");
}