/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_creature.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:06:38 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/03 12:51:38 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
* typedef struct s_philo
{
	unsigned int	id;
	int				eats;
	time_t			start_time;
	t_pstatus		status;
	pthread_t		thr;
	t_bool			is_done;
	pthread_mutex_t	lis_done;
	pthread_mutex_t	lstart_time;
	pthread_mutex_t	lstatus;
	t_data			*data;
}					t_philo;
*/

// INFO:---------------------------
t_philo ft_philo_init(int id, t_data *data)
{
  t_philo *p;

  p = ft_calloc(sizeof(t_philo), 1);
  if (!p)
    //TODO:
  p->id = id;
  p->data = data;
  p->start_time = data->start_time + data->philo_num * 20;





}
 

// --------------------------------

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
      free(d->pid)
      printf("Hello! from child %d\n", i+1);
      // TODO: init philo data
      // TODO: create philo cyrcle life
      // TODO: free philo
      exit(0);
    }
  }
  i = -1;
  while (d->pid[++i])
		waitpid(d->pid[i], NULL, 0);
  return (d->err);
}
