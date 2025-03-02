/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:18:31 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/28 15:23:23 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_errno	ft_watcher(t_data *data, t_philo **philos)
{
	int	id;
	int	re;

	id = 0;
	ft_dely(data->start_time);
	while (true)
	{
		if (id == data->philo_num)
			id = 0;
		re = ft_is_finish_eating(data, philos[id]);
		if (re == 1)
			break ;
		else if (re == 2)
		{
			id++;
			continue ;
		}
		if (ft_strave_check(data, philos[id]))
			break ;
		id++;
	}
	return (ERR_SUCCESS);
}

// finished case
// this function check if the philo has done status
// if it has it it's check if all other philo done if that true
// it's return 1
// if it's has done status but it's not all philo done
// it's return 2
// other cases return 0
int	ft_is_finish_eating(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(philo->lstatus));
	if (philo->status == DONE)
	{
		pthread_mutex_unlock(&(philo->lstatus));
		pthread_mutex_lock(&(data->lfinish_count));
		if (data->finish_count == data->philo_num)
		{
			pthread_mutex_unlock(&(data->lfinish_count));
			pthread_mutex_lock(&(data->lis_done));
			data->is_done = 1;
			pthread_mutex_unlock(&(data->lis_done));
			return (1);
		}
		pthread_mutex_unlock(&(data->lfinish_count));
		return (2);
	}
	pthread_mutex_unlock(&(philo->lstatus));
	return (0);
}

// strave die case return true if philo die from strave
t_bool	ft_strave_check(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(philo->lstatus));
	pthread_mutex_lock(&(philo->lstart_time));
	if ((ft_time_now() - philo->start_time) > data->tdie)
	{
		pthread_mutex_lock(&(data->lis_done));
		data->is_done = 1;
		pthread_mutex_unlock(&(data->lis_done));
		philo->status = DIE;
		pthread_mutex_unlock(&(philo->lstart_time));
		pthread_mutex_unlock(&(philo->lstatus));
		ft_print_msg_status(philo);
		return (true);
	}
	pthread_mutex_unlock(&(philo->lstart_time));
	pthread_mutex_unlock(&(philo->lstatus));
	return (false);
}
