#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


static void * threadFunc(void *arg)
{
  int *is_died = (int *) arg;
  *is_died = 1;
  return (void *) is_died;
}

int main(int argc, char *argv[])
{
  pthread_t t1;
  int s;
  int *is_died;

  is_died = malloc(sizeof(int));
  *is_died = 0;
  s = pthread_create(&t1, NULL, threadFunc, is_died);
  if (s != 0)
    printf("error: pthread_create");
  pthread_join(t1, NULL);
  if (*is_died)
    printf("ooh no! i'm alredy died (^_^)\n");
  else 
    printf("hihi! i'm not died (^v^)\n");
  exit(EXIT_SUCCESS);
}
