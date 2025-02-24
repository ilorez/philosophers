// this example for allocate 

#include <stdlib.h>
#include <stdio.h>

typedef struct charint 
{
  int a;
  char *b;
};

int main(int ac, char **av)
{
  struct charint *lst;
  int i;

  lst = malloc(sizeof(struct charint) * ac);
  for (i = 0; i < ac; i++)
  {
    lst[i].a = i;
    lst[i].b = av[i];
  }
  for (i = 0; i < ac; i++)
  {
    printf("a: %d => b: %s\n", lst[i].a, lst[i].b);
  }
  free(lst);
}
