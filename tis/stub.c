#include <time.h>

time_t time(time_t *tloc) {
  return 99;
}

struct tm *localtime_r(const time_t *timep, struct tm *result)
{
  return 0;
}

size_t strftime(char *s, size_t max, const char *format,
		const struct tm *tm)
{
  return 0;
}
