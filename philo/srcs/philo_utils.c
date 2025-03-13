/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:40:30 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/13 11:15:08 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * to explain why that and not just usleep(time * 1000);
 * that's because the time that usleep take in the background
 * it's not exacly the same time as you give it
 * it's add a 1ms every 1s less or more lies on machine speed
 * so if when you sleep just 100 microsec every time
 * the time that usleep adds is less than 100 microsec
 * which make no effect
 */
void	ft_msleep(time_t time, int *check, pthread_mutex_t *lock)
{
	ft_dely(ft_time_now() + time, check, lock);
}

/* we should always calculate think time because
 * may the thread wait more time in the trying to get forks
 * so when you when you sleep fixed time you just kill the thread in think
 * time and that not correct
 */
void	ft_think_time(t_philo *p, t_bool start)
{
	time_t	time;

	pthread_mutex_lock(&(p->lstart_time));
	time = (p->data->tdie - (ft_time_now() - p->start_time)) / 2;
	if (time < 0)
		time = 0;
	if (time < 1 && start)
		time = 1;
	else if (time > 200)
		time = 200;
	pthread_mutex_unlock(&(p->lstart_time));
	ft_msleep(time, &(p->data->is_done), &(p->data->lis_done));
}
