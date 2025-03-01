#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


static int glob = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static void *threadFunc(void *arg)
{
  int loops = *((int *) arg);
  int loc, j, s;
  for (j = 0; j < loops; j++) {
    printf("j=>%d\n", j);
    s = pthread_mutex_lock(&mtx);
    if (s != 0)
      printf("pthread_mutex_lock");
    loc = glob;
    loc++;
    glob = loc;
    // or glob++;
  }
  return NULL;
}

int main(int argc, char *argv[])
{
  pthread_t t1, t2;
  int loops, s;
  loops = (argc > 1) ? atoi(argv[1]) : 10000000;
  s = pthread_create(&t1, NULL, threadFunc, &loops);
  if (s != 0)
    printf("pthread_create");
  s = pthread_create(&t2, NULL, threadFunc, &loops);
  if (s != 0)
    printf("pthread_create");
  s = pthread_join(t1, NULL);
  if (s != 0)
    printf("pthread_join");
  s = pthread_join(t2, NULL);
  if (s != 0)
    printf("pthread_join");
  printf("glob = %d\n", glob);
  exit(EXIT_SUCCESS);
}
