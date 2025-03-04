/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_creature.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:06:38 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/04 12:10:18 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// join thread
t_errno	ft_wait_thread(pthread_t thr)
{
	void	*tmp;

	if (pthread_join(thr, &tmp) != 0)
			return (ERR_PTHREAD_JOIN);
  return (ERR_SUCCESS);
}

t_errno ft_philos_creature(t_data *d)
{
  int i;
  t_philo *p;

  i = -1;
  while (++i < d->philo_num)
  {
    d->pid[i] = fork();
    if (d->pid[i] == -1)
    {
      d->err = ERR_FORK_FAILED;
      // TODO:create stop point here 
      break;
    }
    else if (d->pid[i] == 0)
    {
      free(d->pid);
      p = ft_calloc(sizeof(t_philo), 1);
      if (!p)
        exit(ERR_MALLOC_FAIL);// TODO:
      printf("Hello! from child %d\n", i+1);
      d->err = ft_philo_init(i + 1, d, p);// TODO: init philo data
      if (d->err)
      {
        ft_perror(NULL, d->err);
        exit(d->err);
      }
      // TODO: create philo cyrcle life
      ft_life_cycle(p);
      // TODO: join threds
      ft_wait_thread(p->self_watcher);
      ft_wait_thread(p->other_watcher);
      // TODO: free philo
      exit(0);
    }
  }
  i = -1;
  while (d->pid[++i])
		waitpid(d->pid[i], NULL, 0);
  return (d->err);
}

