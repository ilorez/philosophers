#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
//#include <time.h>
int main()
{
  time_t mili;
  struct timeval tv;

  gettimeofday(&tv, NULL); 
  mili = (time_t) tv.tv_sec * 1000 + (time_t)tv.tv_usec / 1000;
  printf(" gettimeofday() returned %ld secs, %ld microsecs\ntime in millisecond is %ld", (long) tv.tv_sec, (long) tv.tv_usec, mili);
}
