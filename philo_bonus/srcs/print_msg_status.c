/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:21:03 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/10 07:57:59 by znajdaou         ###   ########.fr       */
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
	char	*status[DONE];

	status[WAITING_FORKS] = "has taken a fork";
	status[EATING] = "is eating";
	status[SLEEPING] = "is sleeping";
	status[THINKING] = "is thinking";
	status[DIE] = "died";
	pthread_mutex_lock(&(philo->lstatus));
	pthread_mutex_lock(&(philo->lis_done));
	if (philo->is_done == 0 && philo->status >= 0 && philo->status < DIE)
		ft_print_status(philo, status[philo->status]);
	else if (philo->is_done == 1 && philo->status == DIE)
	{
		philo->is_done = 2;
		ft_print_status(philo, status[philo->status]);
	}
	pthread_mutex_unlock(&(philo->lis_done));
	pthread_mutex_unlock(&(philo->lstatus));
}
