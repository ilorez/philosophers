/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:56:56 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/13 06:40:27 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_philo_eat(t_philo *p)
{
	sem_wait(p->data->half.addr);
	sem_wait(p->data->forks.addr);
	ft_print_msg_status(p);
	sem_wait(p->data->forks.addr);
	ft_print_msg_status(p);
	sem_post(p->data->half.addr);
	ft_change_time(&(p->start_time), &(p->lstart_time));
	ft_change_status(p, EATING);
	ft_msleep(p->data->teat);
	sem_post(p->data->forks.addr);
	sem_post(p->data->forks.addr);
	if (ft_mutex_cond(&(p->is_done), &(p->lis_done)))
		return (1);
	if (p->data->limited && (++(p->eats) >= p->data->max_eats))
	{
		pthread_mutex_lock(&(p->lis_done));
		p->is_done = 1;
		pthread_mutex_unlock(&(p->lis_done));
		pthread_mutex_lock(&(p->lstatus));
		p->status = DONE;
		pthread_mutex_unlock(&(p->lstatus));
		sem_post(p->data->done.addr);
		return (1);
	}
	return (0);
}

t_errno	ft_life_cycle(t_philo *p)
{
	ft_dely(p->data->start_time);
	if (p->data->philo_num == 1)
	{
		sem_wait(p->data->forks.addr);
		ft_print_msg_status(p);
		ft_msleep(p->data->tdie + 10);
		return (ERR_SUCCESS);
	}
	if (p->id % 2 == 0)
		ft_think_time(p, true);
	while (true)
	{
		if (ft_philo_eat(p))
			break ;
		ft_change_status(p, SLEEPING);
		ft_msleep(p->data->tsleep);
		ft_change_status(p, THINKING);
		ft_think_time(p, false);
		pthread_mutex_lock(&(p->lstatus));
		p->status = WAITING_FORKS;
		pthread_mutex_unlock(&(p->lstatus));
	}
	return (ERR_SUCCESS);
}
