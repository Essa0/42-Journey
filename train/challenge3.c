#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
long long get_time_in_ms()
{
	struct timeval time;
	gettimeofday(&time, NULL);

	return (((long long)time.tv_sec * 1000) + ((long long)time.tv_usec / 1000));
}

void prices_sleep(long long time_ms)
{
	long long start;
	start = get_time_in_ms();
	while (get_time_in_ms() - start < time_ms)
	{
		usleep(500);
	}
	
}
int main()
{
	

	int i = 0;
	while (i < 5)
	{
		printf("%lld\n", get_time_in_ms());
		prices_sleep(5);
		i++;
	}
	
    return 0;
}
// long long start;
	// long long currentTime;
	// start = get_time_in_ms();
	// printf("the program start in: %lld\n", get_time_in_ms() - start);
	// usleep(500000);
	// currentTime = get_time_in_ms() - start;
	// printf("%lld time passed\n", currentTime);
	// usleep(1000000);
	// currentTime = get_time_in_ms() - start;
	// printf("program end after: %lld ms\n", currentTime);