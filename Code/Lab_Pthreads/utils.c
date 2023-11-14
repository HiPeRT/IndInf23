#include <time.h>
#include <sys/time.h>

#define SECONDS 1000000000

unsigned long long gettime(void)
{
  struct timespec t;
  int r;

  r = clock_gettime(CLOCK_MONOTONIC, &t);
  if (r < 0)
  {
    printf("Error to get time! (%i)\n", r);
    return -1L;
  }

  return (unsigned long long) t.tv_sec * SECONDS + t.tv_nsec;
 }
