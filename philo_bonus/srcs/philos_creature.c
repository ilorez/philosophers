/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_creature.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:06:38 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/03 12:34:18 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


t_errno ft_philos_creature(t_data *d)
{
  int i;

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
      printf("Hello! from child %d\n", i+1);
      exit(0);
    }
  }
  i = -1;
  while (d->pid[++i])
		waitpid(d->pid[i], NULL, 0);
  return (d->err);
}
