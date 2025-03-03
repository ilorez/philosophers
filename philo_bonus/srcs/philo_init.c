/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:52:03 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/04 12:26:58 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
	pthread_t		self_watcher;
	pthread_t		other_watcher;

/*
* dely to start time
* a while that check if the child is already dead
* lock and set is done to true
* die semphore update
* sema write wait 
* print die msg
* unlock is_done
* return (NULL)
*/
void *ft_self_watcher(void *ptr)
{
  t_philo *p;

  p = (t_philo *)ptr;
  printf("Hello from slef watcher philo[%d]\n", p->id);
  ft_dely(p->start_time);
  while (true)
  {
    pthread_mutex_lock(&(p->lstatus));
	  pthread_mutex_lock(&(p->lstart_time));
	  if ((ft_time_now() - p->start_time) > p->data->tdie)
	  {
	  	pthread_mutex_unlock(&(p->lstart_time));
	  	pthread_mutex_lock(&(p->lis_done));
	  	p->is_done = true;
	  	pthread_mutex_unlock(&(p->lis_done));
      sem_post(p->data->die);
	  	p->status = DIE;
	  	pthread_mutex_unlock(&(p->lstatus));
      sem_wait(p->data->print);
	  	ft_print_msg_status(p);
      sem_post(p->data->print);
      break;
	  }
	  pthread_mutex_unlock(&(p->lstart_time));
	  pthread_mutex_unlock(&(p->lstatus));
  }
  return (NULL);
}

// wait in die semaphore to be posted
// lock & set is done true & unlock
// return NULL;
void *ft_other_watcher(void *ptr)
{
  t_philo *p;

  p = (t_philo *)ptr;
  printf("Hello from other watcher philo[%d]\n", p->id);
  sem_wait(p->data->die);
  pthread_mutex_lock(&(p->lis_done));
  p->is_done = true;
  pthread_mutex_unlock(&(p->lis_done));
  sem_post(p->data->die);
  return (NULL);
}

// INFO:---------------------------
t_errno ft_philo_init(int id, t_data *data, t_philo *p)
{
  p->id = id;
  p->data = data;
  if (pthread_mutex_init(&(p->lis_done), NULL) != 0)
			return (ERR_MUTEX_INIT);
  if (pthread_mutex_init(&(p->lstatus), NULL) != 0)
			return (ERR_MUTEX_INIT);
	if (pthread_mutex_init(&(p->lstart_time), NULL) != 0)
			return (ERR_MUTEX_INIT);
	p->start_time = data->start_time;
  if (pthread_create(&(p->self_watcher), NULL, &ft_self_watcher, p))
	{
			//pthread_mutex_lock(&(data->lis_done));
			//data->is_done = 2;
			//pthread_mutex_unlock(&(data->lis_done));
			//return (ft_clean_table(data, phs), ERR_PTHREAD_CREATE);
    return (ERR_PTHREAD_CREATE);
	}
  if (pthread_create(&(p->other_watcher), NULL, &ft_other_watcher, p))
    return (ERR_PTHREAD_CREATE);
  // create two thread
  // - for check die
  // - another one for check in another philo died
  return (ERR_SUCCESS);
}
