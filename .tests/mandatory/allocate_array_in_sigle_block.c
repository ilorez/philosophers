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
  struct charint *lsti;
  int i;

  lst = malloc(sizeof(struct charint) * ac);
  for (i = 0; i < ac; i++)
  {
    lsti = &(lst[i]);
    lsti->a = i;
    lsti->b = av[i];
  }
  for (i = 0; i < ac; i++)
  {
    printf("a: %d => b: %s\n", lst[i].a, lst[i].b);
  }
  free(lst);
}
