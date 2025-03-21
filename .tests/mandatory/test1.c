#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static void * threadFunc(void *arg)
{
  char *s = (char *) arg;
  printf("%s", s);
  return (void *) strlen(s);
}

int main(int argc, char *argv[])
{
  pthread_t t1;
  void *res;
  int s;

  s = pthread_create(&t1, NULL, threadFunc, "Hello world\n");
  if (s != 0)
    printf("error: pthread_create");

  printf("Message from main()\n");
  printf("Message from main()\n");
  printf("Message from main()\n");
  sleep(1);
  printf("Message from main()\n");
  printf("Message from main()\n");
  printf("Message from main()\n");
  printf("Message from main()\n");
  printf("Message from main()\n");
  printf("Message from main()\n");
  printf("Message from main()\n");
  printf("Message from main()\n");
  s = pthread_join(t1, &res);
  if (s != 0)
    printf("errr: pthread_join");
  printf("Thread returned %ld\n", (long) res);
  exit(EXIT_SUCCESS);
}
