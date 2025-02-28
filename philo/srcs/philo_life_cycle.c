/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:58:38 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/28 16:00:23 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool ft_hold_forks(t_philo *p, pthread_mutex_t *forks,int left, int r8)
{
  pthread_mutex_lock(&(forks[left]));
	ft_print_msg_status(p);
  if (left == r8)
    return (false);
	pthread_mutex_lock(&(forks[r8]));
	ft_print_msg_status(p);
  return (true);
}

void	*ft_philo_life_cycle(void *ptr) {
	t_philo	*p;
  int left;

  // id start counting from 1 not 0
	p = (t_philo *)ptr;
  if (p->id % 2 == 0)
    left = p->id; // id +1
  else 
    left = p->id - 1; // id 
  ft_dely(p->data->start_time);
  if (p->id % 2 == 0)
    ft_think_time(p, true);
  while (true)
	{
    // get forks
    if (!ft_hold_forks(p, p->data->forks, left % p->data->philo_num, (left + 1) % p->data->philo_num))
      return (NULL);
    // eating
		ft_change_status(p->data, p, EATING);
		ft_change_time(&(p->start_time), &(p->lstart_time));
		ft_msleep(p->data->teat);
    // put forks
		pthread_mutex_unlock(&(p->data->forks[left % p->data->philo_num]));
		pthread_mutex_unlock(&(p->data->forks[(left + 1) % p->data->philo_num]));
    // check done
    pthread_mutex_lock(&(p->data->lis_done));
    if (p->data->is_done != 0 || (p->eats >= p->data->max_eats && p->data->limited))
    {
		  pthread_mutex_unlock(&(p->data->lis_done));
      break;
    }
		pthread_mutex_unlock(&(p->data->lis_done));
    // sleeping
		ft_change_status(p->data, p, SLEEPING);
		ft_msleep(p->data->tsleep);
    // thinking
		ft_change_status(p->data, p, THINKING);
    ft_think_time(p, false);
    // waiting forks
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
