/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:41:46 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/19 16:51:29 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_change_status(t_data *data, t_philo *philo, t_pstatus to)
{
  pthread_mutex_lock(philo->lstatus);
  philo->status = to;
  pthread_mutex_unlock(philo->lstatus);
  pthread_mutex_lock(data->lis_done);
  if (!data->is_done)
    ft_print_msg_status(philo);
  pthread_mutex_unlock(data->lis_done);
  return ;
}

void ft_change_time(unsigned int *var, pthread_mutex_t lock)
{
  pthread_mutex_lock(lock);
  *var = ft_time_now();
  pthread_mutex_unlock(lock);
}

void *ft_philo_life_cycle(t_philo *p)
{
  p->start_time = ft_time_now();
  ft_change_time(&(p->start_time), p->lstart_time);
  while (!p->data->limited || ++p->eats <= p->data->max_eats)
  {
    pthread_mutex_lock(p->data->forks[p->id -1]);
    ft_print_msg_status(philo);
    pthread_mutex_lock(p->data->forks[p->id % p->data->philo_num]);
    ft_print_msg_status(philo);
    ft_change_status(p->data, p, EATING);
    usleep(p->data->teat);
    ft_change_time(&(p->start_time), p->lstart_time);
    ft_change_status(p->data, p, SLEEPING);
    usleep(p->data->tsleep);
    ft_change_status(p->data, p, THINKING);
    usleep(p->data->tthink;
  }
  pthread_mutex_lock(p->data->status);
  p->status = DONE;
  pthread_mutex_unlock(p->data->status);
  pthread_mutex_lock(p->data->lfinish_count);
  p->data->finish_count += 1;
  pthread_mutex_unlock(p->data->lfinish_count);
  return (NULL);
}

t_bool create_threads(t_data *data)
{
  t_philo **philos;
  void *tmp;
  unsigned int id;
  t_philo 

  philos = ft_calloc(sizeof(t_philo*), data->philo_num);
  i = -1;
  while (++(i) < data->philo_num)
  {
    philos[i] = ft_calloc(sizeof(t_philo), 1);
    (philos[i])->id = i;
    (philos[i])->data = data;
    if (pthread_mutex_init((philos[i])->lstatus, NULL) != 0)
      continue ;/* TODO: error here */
    if (pthread_mutex_init((philos[i])->lstart_time, NULL) != 0)
      continue ;/* TODO:  error here */
    if (pthread_create(&((philos[i])->thr), NULL, &ft_philo_life_cycle, philos[i]))
    {
      // TODO: set is done true
      break;
    }
  }

  if (ft_watcher(data, philos))
         return false; // TODO: error
  // joining threads
  i = -1;
  while (++i < data->philo_num)
  {
    if (pthread_join((philos[i])->thr, &tmp))
      continue ; // TODO: handel this error
  }
  // free threads
  ft_free_lst(philos);
  while ()
}

