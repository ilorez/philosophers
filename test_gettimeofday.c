#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
int main()
{
  char buffer[30];
  struct timeval tv;
  suseconds_t curtime;

  gettimeofday(&tv, NULL); 
  curtime= tv.tv_usec;
  //strftime(buffer,30,"%m-%d-%Y  %T.",localtime(&curtime));
  printf("%lld\n", curtime);
}
