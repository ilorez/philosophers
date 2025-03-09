/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:52:03 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/09 09:43:56 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
void	*ft_self_watcher(void *ptr)
{
	t_philo	*p;
	int		i;

	p = (t_philo *)ptr;
	ft_dely(p->start_time);
	while (true)
	{
		pthread_mutex_lock(&(p->lis_done));
		if (p->is_done)
		{
			pthread_mutex_unlock(&(p->lis_done));
			return (NULL);
		}
		pthread_mutex_unlock(&(p->lis_done));
		pthread_mutex_lock(&(p->lstart_time));
		if ((ft_time_now() - p->start_time) > p->data->tdie)
		{
			pthread_mutex_unlock(&(p->lstart_time));
			sem_post(p->data->die.addr);
			sem_wait(p->data->die_gate.addr);
			pthread_mutex_lock(&(p->lis_done));
			if (p->is_done)
			{
				sem_post(p->data->die_gate.addr);
				pthread_mutex_unlock(&(p->lis_done));
				return (NULL);
			}
			p->is_done = 1;
			pthread_mutex_unlock(&(p->lis_done));
			i = -1;
			while (++i < p->data->philo_num)
				sem_wait(p->data->inform.addr);
			pthread_mutex_lock(&(p->lstatus));
			p->status = DIE;
			pthread_mutex_unlock(&(p->lstatus));
			ft_print_msg_status(p);
			sem_post(p->data->die_gate.addr);
			break ;
		}
		pthread_mutex_unlock(&(p->lstart_time));
	}
	return (NULL);
}

// wait in die semaphore to be posted
// lock & set is done true & unlock
// return (NULL);
void	*ft_other_watcher(void *ptr)
{
	t_philo	*p;

	p = (t_philo *)ptr;
	sem_wait(p->data->die.addr);
	sem_post(p->data->die.addr);
	pthread_mutex_lock(&(p->lis_done));
  if (!(p->is_done))
	  p->is_done = 1;
	pthread_mutex_unlock(&(p->lis_done));
	sem_post(p->data->inform.addr);
	return (NULL);
}

/* INFO:---------------------------
 * init philo info
 * - static data
 * - mutexs
 * - creating two threads
 *   - for check self strave died
 *   - for check if another philo died
 * ---------------------------------*/
t_errno	ft_philo_init(int id, t_data *data, t_philo *p)
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
		sem_post(data->die.addr);
		return (ERR_PTHREAD_CREATE);
	}
	if (pthread_create(&(p->other_watcher), NULL, &ft_other_watcher, p))
	{
		sem_post(data->die.addr);
		return (ERR_PTHREAD_CREATE);
	}
	return (ERR_SUCCESS);
}
