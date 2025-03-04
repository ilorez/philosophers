/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:52:03 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/04 11:13:50 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
	pthread_t		self_watcher;
	pthread_t		other_watcher;

void *ft_self_watcher(void *ptr)
{
  t_philo *p;

  p = (t_philo *)ptr;
  printf("Hello from slef watcher philo[%d]\n", p->id);
  return (NULL);
}

void *ft_other_watcher(void *ptr)
{
  t_philo *p;

  p = (t_philo *)ptr;
  printf("Hello from other watcher philo[%d]\n", p->id);
  return (NULL);
}

// INFO:---------------------------
t_errno ft_philo_init(int id, t_data *data, t_philo *p)
{
  p->id = id;
  printf("id=>%d\n", p->id);
  p->data = data;
  if (pthread_mutex_init(&(p->lis_done), NULL) != 0)
			return (ERR_MUTEX_INIT);
  if (pthread_mutex_init(&(p->lstatus), NULL) != 0)
			return (ERR_MUTEX_INIT);
	if (pthread_mutex_init(&(p->lstart_time), NULL) != 0)
			return (ERR_MUTEX_INIT);
	p->start_time = data->start_time;
  printf("id=>%d\n", p->id);
  if (pthread_create(&(p->self_watcher), NULL, &ft_self_watcher, p))
	{
			//pthread_mutex_lock(&(data->lis_done));
			//data->is_done = 2;
			//pthread_mutex_unlock(&(data->lis_done));
			//return (ft_clean_table(data, phs), ERR_PTHREAD_CREATE);
    return (ERR_PTHREAD_CREATE);
	}
  if (pthread_create(&(p->other_watcher), NULL, &ft_other_watcher, p))
  {
    return (ERR_PTHREAD_CREATE);
  }
  // create two thread
  // - for check die
  // - another one for check in another philo died
  return (ERR_SUCCESS);
}
