/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:57:19 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/05 14:42:40 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// return current time in ms
time_t	ft_time_now(void)
{
	time_t			mills;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	mills = (time_t)tv.tv_sec * 1000 + (time_t)tv.tv_usec / 1000;
	return (mills);
}

// change the value of var which is a pointer to current time in ms
void	ft_change_time(time_t *var, pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
	*var = ft_time_now();
	pthread_mutex_unlock(lock);
}

// change philo->status to "to" status
void	ft_change_status(t_philo *philo, t_pstatus to)
{
	pthread_mutex_lock(&(philo->lstatus));
	philo->status = to;
	pthread_mutex_unlock(&(philo->lstatus));
	pthread_mutex_lock(&(philo->lis_done));
	if (!(philo->is_done))
	{
		pthread_mutex_unlock(&(philo->lis_done));
		ft_print_msg_status(philo);
	}
	else
		pthread_mutex_unlock(&(philo->lis_done));
	return ;
}

// return after current time is more then or egal the time got as param
void	ft_dely(time_t time)
{
	while (ft_time_now() < time)
		continue ;
}

// work for checking the cond if its true after lock it
t_bool	ft_mutex_cond(int *cond, pthread_mutex_t *lock)
{
	t_bool	re;

	re = false;
	pthread_mutex_lock(lock);
	if (*cond)
		re = true;
	pthread_mutex_unlock(lock);
	return (re);
}
