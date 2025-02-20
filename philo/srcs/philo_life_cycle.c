/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:58:38 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/20 19:41:25 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *ft_philo_life_cycle(void *ptr)
{
  t_philo *p;

  p = (t_philo *)ptr;
  p->start_time = ft_time_now();
  ft_change_time(&(p->start_time), p->lstart_time);
  while (!p->data->limited || ++p->eats <= p->data->max_eats)
  {
    pthread_mutex_lock((p->data->forks[p->id -1]));
    ft_print_msg_status(p);
    pthread_mutex_lock((p->data->forks[p->id % p->data->philo_num]));
    ft_print_msg_status(p);
    ft_change_status(p->data, p, EATING);
    usleep(p->data->teat);
    pthread_mutex_unlock((p->data->forks[p->id % p->data->philo_num]));
    pthread_mutex_unlock((p->data->forks[p->id -1]));
    ft_change_time(&(p->start_time), p->lstart_time);
    ft_change_status(p->data, p, SLEEPING);
    usleep(p->data->tsleep);
    ft_change_status(p->data, p, THINKING);
    usleep(p->data->tthink);
    pthread_mutex_lock(&(p->lstatus));
    p->status = WAITING_FORKS;
    pthread_mutex_unlock(&(p->lstatus));
  }
  pthread_mutex_lock(&(p->lstatus));
  p->status = DONE;
  pthread_mutex_unlock(&(p->lstatus));
  pthread_mutex_lock(&(p->data->lfinish_count));
  p->data->finish_count += 1;
  pthread_mutex_unlock(&(p->data->lfinish_count));
  return (NULL);
}

void ft_change_time(time_t *var, pthread_mutex_t lock)
{
  pthread_mutex_lock(&(lock));
  *var = ft_time_now();
  pthread_mutex_unlock(&(lock));
}

void ft_change_status(t_data *data, t_philo *philo, t_pstatus to)
{
  pthread_mutex_lock(&(philo->lstatus));
  philo->status = to;
  pthread_mutex_unlock(&(philo->lstatus));
  pthread_mutex_lock(&(data->lis_done));
  if (!data->is_done)
    ft_print_msg_status(philo);
  pthread_mutex_unlock(&(data->lis_done));
  return ;
}
