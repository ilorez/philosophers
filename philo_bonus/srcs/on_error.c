/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:29:28 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/12 17:08:19 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_errno	ft_free_data(t_data *data, t_errno err)
{
	if (data)
	{
		ft_free_t_sem(&(data->forks));
		ft_free_t_sem(&(data->write));
		ft_free_t_sem(&(data->die));
		ft_free_t_sem(&(data->inform));
		ft_free_t_sem(&(data->die_gate));
		ft_free_t_sem(&(data->half));
		ft_free_t_sem(&(data->done));
		if (data->pid)
			free(data->pid);
		free(data);
	}
	if (err)
		ft_perror(NULL, err);
	return (err);
}

t_errno	ft_free_philo(t_philo *philo, t_errno err)
{
	if (!philo)
		return (err);
	if (pthread_mutex_destroy(&(philo->lstatus)) && !err)
		err = ERR_MUTEX_DESTROY;
	if (pthread_mutex_destroy(&(philo->lstart_time)) && !err)
		err = ERR_MUTEX_DESTROY;
	if (pthread_mutex_destroy(&(philo->lis_done)) && !err)
		err = ERR_MUTEX_DESTROY;
	free(philo);
	return (err);
}

int	ft_print_syntax_error(char *program)
{
	printf("./%s <*number_of_philosophers> <*time_to_die> \
    \n\t<*time_to_eat> <time_to_sleep> \
    \n\t[number_of_times_each_philosopher_must_eat] \n", program);
	return (EXIT_FAILURE);
}
