/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:21:03 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/05 14:49:12 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_msg_status(t_philo *philo)
{
	char	*status[DONE];
	time_t	time;

  status[WAITING_FORKS] = "has taken a fork";
	status[EATING] = "is eating";
	status[SLEEPING] = "is sleeping";
	status[THINKING] = "is thinking";
	status[DIE] = "died";
	pthread_mutex_lock(&(philo->lstatus));
	if (philo->status < 0 || philo->status >= DONE)
  {
	  pthread_mutex_unlock(&(philo->lstatus));
		return ;
  }
	pthread_mutex_lock(&(philo->lis_done));
  if (philo->is_done && philo->status != DIE)
    return ;
	pthread_mutex_unlock(&(philo->lis_done));
  sem_wait(philo->data->write.addr);
	time = ft_time_now() - philo->data->start_time;
	printf("%lu %d %s\n", time, philo->id, status[philo->status]);
  sem_post(philo->data->write.addr);
	pthread_mutex_unlock(&(philo->lstatus));
}
