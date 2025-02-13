#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


static void * threadFunc(void *arg)
{
    struct someStruct *pbuf = (struct someStruct *) arg;
    /* Do some work with structure pointed to by 'pbuf' */
}

int main(int argc, char *argv[])
{
  int buf;
  pthread_t thr;

  pthread_create(&thr, NULL, threadFunc, (void *) &buf);
  pthread_exit(NULL);
}
