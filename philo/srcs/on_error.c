/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:29:28 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/25 10:59:33 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_errno	ft_free_data(t_data *data, t_errno err)
{
	if (!data)
		return (err);
	if (data->forks)
		free(data->forks);
	free(data);
	if (err)
		ft_perror(NULL, err);
	return (err);
}

void	*ft_usefree(t_data *data, t_philo **philos, t_errno err)
{
	if (philos)
		ft_free_lst((void **)philos);
	if (data)
		ft_free_data(data, err);
	return (NULL);
}

int	ft_print_syntax_error(char *program)
{
	printf("./%s <*number_of_philosophers> <*time_to_die> \
          \n\t<*time_to_eat> <time_to_sleep> \
          \n\t[number_of_times_each_philosopher_must_eat] \
          \n", program);
	return (EXIT_FAILURE);
}
