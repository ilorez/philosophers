/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_creature.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:24:05 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/28 15:38:44 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_errno	ft_threads_creature(t_data *data)
{
	t_philo	**phs;
	int		i;

	phs = (t_philo **)ft_calloc(sizeof(t_philo *), data->philo_num + 1);
	i = -1;
	while (++i < data->philo_num)
	{
		phs[i] = (t_philo *)ft_calloc(sizeof(t_philo), 1);
		phs[i]->id = i + 1;
		phs[i]->data = data;
		if (pthread_mutex_init(&(phs[i]->lstatus), NULL) != 0)
			return (ft_free_philos(phs, ERR_MUTEX_INIT));
		if (pthread_mutex_init(&(phs[i]->lstart_time), NULL) != 0)
			return (ft_free_philos(phs, ERR_MUTEX_INIT));
		phs[i]->start_time = data->start_time;
		if (pthread_create(&(phs[i]->thr), NULL, &ft_philo_life_cycle, phs[i]))
		{
			pthread_mutex_lock(&(data->lis_done));
			data->is_done = 2;
			pthread_mutex_unlock(&(data->lis_done));
			return (ft_clean_table(data, phs), ERR_PTHREAD_CREATE);
		}
	}
	ft_watcher(data, phs);
	return (ft_clean_table(data, phs));
}

// clean table it's just waiting threads or philosophers
// after that it's free data
// which is some thing look like cleaning table
t_errno	ft_clean_table(t_data *data, t_philo **phs)
{
	int		i;
	void	*tmp;

	i = 0;
	while (phs[i])
	{
		if (phs[i] && pthread_join(phs[i]->thr, &tmp) != 0)
			return (ft_free_philos(phs, ERR_PTHREAD_JOIN));
		i++;
	}
	return (ft_free_philos(phs, data->err));
}
