/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:58:38 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/27 10:27:56 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void ft_msleep(time_t time)
{
  usleep(time * 1000);
}

void ft_think_time(t_philo *p)
{
  time_t time;
	pthread_mutex_lock(&(p->lstart_time));
  if (p->data->tdie <= ((ft_time_now() - p->start_time) - p->data->teat / 2))
    time = 1;
  else 
    time = p->data->tdie - (ft_time_now() - p->start_time) - p->data->teat / 2;
  if (time > 200)
    time = 200;
	pthread_mutex_unlock(&(p->lstart_time));
  ft_msleep(time);
}

void	*ft_philo_life_cycle(void *ptr)
{
	t_philo	*p;
  int left;

  // id start counting from 1 not 0
	p = (t_philo *)ptr;
  if (p->id % 2 == 0)
    left = p->id; // id +1
  else 
    left = p->id - 1; // id 
  ft_dely(p->data->start_time);
  if (p->id % 2)
    usleep(p->data->tthink * 1000);
  while (!(p->data->limited) || (p->eats)++ < p->data->max_eats)
	{
		pthread_mutex_lock(&(p->data->forks[left % p->data->philo_num]));
		ft_print_msg_status(p);
		pthread_mutex_lock(&(p->data->forks[(left + 1) % p->data->philo_num]));
		ft_print_msg_status(p);
		ft_change_status(p->data, p, EATING);
		ft_change_time(&(p->start_time), &(p->lstart_time));
		ft_msleep(p->data->teat);
		pthread_mutex_unlock(&(p->data->forks[p->id % p->data->philo_num]));
		pthread_mutex_unlock(&(p->data->forks[p->id - 1]));
		ft_change_status(p->data, p, SLEEPING);
		ft_msleep(p->data->tsleep);
		ft_change_status(p->data, p, THINKING);
		pthread_mutex_lock(&(p->lstatus));
		p->status = WAITING_FORKS;
		pthread_mutex_unlock(&(p->lstatus));
		pthread_mutex_lock(&(p->data->lis_done));
    if (p->data->is_done != 0)
      break;
		pthread_mutex_unlock(&(p->data->lis_done));
    ft_think_time(p);
	}
	pthread_mutex_lock(&(p->lstatus));
	p->status = DONE;
	pthread_mutex_unlock(&(p->lstatus));
	pthread_mutex_lock(&(p->data->lfinish_count));
	p->data->finish_count += 1;
	pthread_mutex_unlock(&(p->data->lfinish_count));
  return (NULL);
}

