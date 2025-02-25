/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:21:03 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/25 10:09:31 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_msg_status(t_philo *philo)
{
	char	*status[STATUS_COUNT];

	if (philo->status < 0 || philo->status >= STATUS_COUNT
		|| philo->status == DONE)
		return ;
	status[WAITING_FORKS] = "has taken a fork";
	status[EATING] = "is eating";
	status[SLEEPING] = "is sleeping";
	status[THINKING] = "is thinking";
	status[DIE] = "died";
	status[DONE] = "";
	pthread_mutex_lock(&(philo->lstatus));
	printf("%lu %d %s\n", ft_time_now() - philo->data->start_time, philo->id,
		status[philo->status]);
	pthread_mutex_unlock(&(philo->lstatus));
	return ;
}
