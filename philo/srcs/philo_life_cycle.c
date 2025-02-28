/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:58:38 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/28 10:14:29 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_msleep(time_t time);
void ft_think_time(t_philo *p, t_bool start);
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
  while (!(p->data->limited) || (p->eats)++ < p->data->max_eats)
	{
		pthread_mutex_lock(&(p->data->forks[left % p->data->philo_num]));
		ft_print_msg_status(p);
    if (p->data->philo_num == 1)
      return (NULL);
		pthread_mutex_lock(&(p->data->forks[(left + 1) % p->data->philo_num]));
		ft_print_msg_status(p);
		ft_change_status(p->data, p, EATING);
		ft_change_time(&(p->start_time), &(p->lstart_time));
		ft_msleep(p->data->teat);
		pthread_mutex_unlock(&(p->data->forks[left % p->data->philo_num]));
		pthread_mutex_unlock(&(p->data->forks[(left + 1) % p->data->philo_num]));
		ft_change_status(p->data, p, SLEEPING);
		ft_msleep(p->data->tsleep);
		ft_change_status(p->data, p, THINKING);
    ft_think_time(p, false);
    pthread_mutex_lock(&(p->lstatus));
    p->status = WAITING_FORKS;
    pthread_mutex_unlock(&(p->lstatus));
		pthread_mutex_lock(&(p->data->lis_done));
    if (p->data->is_done != 0)
    {
		  pthread_mutex_unlock(&(p->data->lis_done));
      break;
    }
		pthread_mutex_unlock(&(p->data->lis_done));
	}
	pthread_mutex_lock(&(p->lstatus));
	p->status = DONE;
	pthread_mutex_unlock(&(p->lstatus));
	pthread_mutex_lock(&(p->data->lfinish_count));
	p->data->finish_count += 1;
	pthread_mutex_unlock(&(p->data->lfinish_count));
  printf("Done %d\n", p->id);
  return (NULL);
}

/*
 * to explain why that and not just usleep(time * 1000);
 * that's because the time that usleep take in the background
 * it's not exacly the same time as you give it
 * it's add a 1ms every 1s less or more lies on machine speed
 * so if when you sleep just 100 microsec every time
 * the time that usleep adds is less than 100 microsec 
 * which make no effect
 */
void ft_msleep(time_t time)
{
  time_t	end;

	end = ft_time_now() + time;
	while (ft_time_now() < end)
		usleep(100);
}

/* we should always calculate think time because
 * may the thread wait more time in the trying to get forks
 * so when you when you sleep fixed time you just kill the thread in think
 * time and that not correct
*/
void ft_think_time(t_philo *p, t_bool start)
{
  time_t time;

	pthread_mutex_lock(&(p->lstart_time));
  time = (p->data->tdie - (ft_time_now() - p->start_time) - p->data->teat) / 2;
  if (time < 0)
    time = 0; 
  if (time < 2 && start)
    time = 2;
  else if (time > 200)
    time = 200;
	pthread_mutex_unlock(&(p->lstart_time));
  printf("think time is: %ld\n", time);
  ft_msleep(time);
}
