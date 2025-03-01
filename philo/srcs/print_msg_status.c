/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:21:03 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/01 07:52:24 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_msg_status(t_philo *philo)
{
	char	*status[DONE];
	time_t	time;

	pthread_mutex_lock(&(philo->lstatus));
	if (philo->status < 0 || philo->status >= DONE)
		return ;
	pthread_mutex_unlock(&(philo->lstatus));
	status[WAITING_FORKS] = "has taken a fork";
	status[EATING] = "is eating";
	status[SLEEPING] = "is sleeping";
	status[THINKING] = "is thinking";
	status[DIE] = "died";
	pthread_mutex_lock(&(philo->lstatus));
	pthread_mutex_lock(&(philo->data->lis_done));
	if ((philo->data->is_done == 0) || (philo->status == DIE
			&& philo->data->is_done == 1))
	{
		time = ft_time_now() - philo->data->start_time;
		printf("%lu %d %s\n", time, philo->id, status[philo->status]);
		if (philo->status == DIE)
			philo->data->is_done = 2;
	}
	pthread_mutex_unlock(&(philo->data->lis_done));
	pthread_mutex_unlock(&(philo->lstatus));
}
