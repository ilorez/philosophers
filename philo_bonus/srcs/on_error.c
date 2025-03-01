/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:29:28 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/02 16:01:04 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_errno	ft_free_data(t_data *data, t_errno err)
{
	if (data)
	  free(data);
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
