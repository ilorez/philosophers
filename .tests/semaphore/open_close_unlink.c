#include <fcntl.h>           /* For O_* constants */
//#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <stdio.h>

#define NAME "hello"
#define VALUE 90

int main()
{
  sem_t *my_sem;

  // | O_EXCL
  my_sem = sem_open(NAME, O_CREAT , 0777, VALUE);
  if (my_sem == SEM_FAILED)
    perror("Error");
  printf("addr: %p\n", my_sem);
  if (sem_close(my_sem) != 0)
    perror("Error");
  if (sem_unlink(NAME) != 0)
    perror("Error");
  return 0;
}
