/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:57:19 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/26 14:53:46 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_lst(void **lst)
{
	void	**org;

	if (!lst)
		return ;
	org = lst;
	while (*lst)
		free(*lst++);
	free(org);
	return ;
}

time_t	ft_time_now()
{
	time_t			mills;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	mills = (time_t)tv.tv_sec * 1000 + (time_t)tv.tv_usec / 1000;
	return (mills);
}

void	ft_change_time(time_t *var, pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
	*var = ft_time_now();
	pthread_mutex_unlock(lock);
}

void	ft_change_status(t_data *data, t_philo *philo, t_pstatus to)
{
	pthread_mutex_lock(&(philo->lstatus));
	philo->status = to;
	pthread_mutex_unlock(&(philo->lstatus));
	pthread_mutex_lock(&(data->lis_done));
	if (!(data->is_done))
	{
	  pthread_mutex_unlock(&(data->lis_done));
		ft_print_msg_status(philo);
	}
  else 
	  pthread_mutex_unlock(&(data->lis_done));
	return ;
}
