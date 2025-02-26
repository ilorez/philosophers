/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:58:38 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/26 11:58:44 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_life_cycle(void *ptr)
{
	t_philo	*p;

	p = (t_philo *)ptr;
  if (p->id % 2 == 0)
    usleep(p->data->teat * 1000);
	//printf("philosopher id=>%d set in the table\n", p->id);
  while (!(p->data->limited) || ++(p->eats) <= p->data->max_eats)
	{
		pthread_mutex_lock(&(p->data->forks[p->id - 1]));
		ft_print_msg_status(p);
		pthread_mutex_lock(&(p->data->forks[p->id % p->data->philo_num]));
		ft_print_msg_status(p);
		ft_change_status(p->data, p, EATING);
		usleep(p->data->teat * 1000);
		pthread_mutex_unlock(&(p->data->forks[p->id % p->data->philo_num]));
		pthread_mutex_unlock(&(p->data->forks[p->id - 1]));
		ft_change_time(&(p->start_time), &(p->lstart_time));
		ft_change_status(p->data, p, SLEEPING);
		usleep(p->data->tsleep * 1000);
		ft_change_status(p->data, p, THINKING);
		usleep(p->data->tthink * 1000);
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


