/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:21:03 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/13 06:34:42 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_print_status(t_philo *philo, char *status)
{
	time_t	time;

	sem_wait(philo->data->write.addr);
	time = ft_time_now() - philo->data->start_time;
	printf("%lu %d %s\n", time, philo->id, status);
	sem_post(philo->data->write.addr);
}
// fflush(stdout);

void	ft_print_msg_status(t_philo *philo)
{
	pthread_mutex_lock(&(philo->lstatus));
	pthread_mutex_lock(&(philo->lis_done));
	if (philo->is_done == 0 && philo->status >= 0 && philo->status < DIE)
		ft_print_status(philo, philo->data->status[philo->status]);
	else if (philo->is_done == 1 && philo->status == DIE)
	{
		philo->is_done = 2;
		ft_print_status(philo, philo->data->status[philo->status]);
	}
	pthread_mutex_unlock(&(philo->lis_done));
	pthread_mutex_unlock(&(philo->lstatus));
}

void	ft_set_msg_status(t_data *data)
{
	data->status[WAITING_FORKS] = "has taken a fork";
	data->status[EATING] = "is eating";
	data->status[SLEEPING] = "is sleeping";
	data->status[THINKING] = "is thinking";
	data->status[DIE] = "died";
}
