/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:29:28 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/02 08:58:08 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_errno	ft_free_data(t_data *data, t_errno err)
{
	int	i;

	if (!data)
		return (err);
	if (data->forks)
	{
		i = -1;
		while (++i < data->philo_num)
			if (pthread_mutex_destroy(&(data->forks[i])) && !err)
				err = ERR_MUTEX_DESTROY;
		free(data->forks);
	}
	if (pthread_mutex_destroy(&(data->lis_done)) && !err)
		err = ERR_MUTEX_DESTROY;
	if (pthread_mutex_destroy(&(data->lfinish_count)) && !err)
		err = ERR_MUTEX_DESTROY;
	free(data);
	if (err)
		ft_perror(NULL, err);
	return (err);
}

t_errno	ft_free_philos(t_philo **philos, t_errno err)
{
	int	i;

	if (!philos)
		return (err);
	i = 0;
	while (philos[i])
	{
		if (pthread_mutex_destroy(&(philos[i]->lstatus)) && !err)
			err = ERR_MUTEX_DESTROY;
		if (pthread_mutex_destroy(&(philos[i]->lstart_time)) && !err)
			err = ERR_MUTEX_DESTROY;
		free(philos[i]);
		i++;
	}
	free(philos);
	return (err);
}

int	ft_print_syntax_error(char *program)
{
	printf("./%s <*number_of_philosophers> <*time_to_die> \
    \n\t<*time_to_eat> <time_to_sleep> \
    \n\t[number_of_times_each_philosopher_must_eat] \n", program);
	return (EXIT_FAILURE);
}
