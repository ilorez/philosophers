/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:56:56 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/08 11:27:27 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 *
 *
 */
// we need to found and idea to make the half go for forks
// i'm thinking using another sima for that
// sema size is forks/2 and waiting between take forks and posted after that
t_errno	ft_life_cycle(t_philo *p)
{
	// dely
	ft_dely(p->data->start_time);
	// think time
	if (p->id % 2 == 0)
		ft_think_time(p, true);
	printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
	while (true)
	{
		// get forks using semaphore
		sem_wait(p->data->forks.addr);
		ft_print_msg_status(p);
		sem_wait(p->data->forks.addr);
		ft_print_msg_status(p);
		// eating
		ft_change_time(&(p->start_time), &(p->lstart_time));
		ft_change_status(p, EATING);
		ft_msleep(p->data->teat);
		sem_post(p->data->forks.addr);
		sem_post(p->data->forks.addr);
		if (ft_mutex_cond(&(p->is_done), &(p->lis_done)))
			break ;
		if (p->data->limited && (++(p->eats) >= p->data->max_eats))
		{
			pthread_mutex_lock(&(p->lis_done));
			p->is_done = 1;
			pthread_mutex_unlock(&(p->lis_done));
			pthread_mutex_lock(&(p->lstatus));
			p->status = DONE;
			pthread_mutex_unlock(&(p->lstatus));
			break ;
		}
		ft_change_status(p, SLEEPING);
		ft_msleep(p->data->tsleep);
		ft_change_status(p, THINKING);
		// ft_think_time(p, false);
		pthread_mutex_lock(&(p->lstatus));
		p->status = WAITING_FORKS;
		pthread_mutex_unlock(&(p->lstatus));
	}
	return (ERR_SUCCESS);
}
