#include <pthread.h>
#include <unistd.h>
#include <stdio.h>


static void * threadFunc(void *arg)
{
  char *s = (char *) arg;
  printf("%s", s);
  long n = pthread_self();
  printf("sid: %ld\nresturn value is %d\n",n,  pthread_join(n, NULL));
  return (void *) strlen(s);
}

int main()
{
  pthread_t t1;
  void *res;
  int s;
  s = pthread_create(&t1, NULL, threadFunc, "Hello world\n");
  if (s != 0)
    printf("error: pthread_create");
  s = pthread_join(t1, &res);
  if (s != 0)
    printf("errr: pthread_join");
  printf("Thread returned %ld\n", (long) res);
  exit(0);
}
