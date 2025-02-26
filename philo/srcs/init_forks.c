/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:58:04 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/26 09:20:52 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_errno	ft_init_forks(t_data *data)
{
	int				i;
	pthread_mutex_t	*forks;

	i = -1;
	forks = ft_calloc(sizeof(pthread_mutex_t), data->philo_num);
	if (!forks)
		return (ERR_MALLOC_FAIL);
	while (++i < data->philo_num)
		if (pthread_mutex_init(&(forks[i]), NULL) != 0)
			return (ERR_MUTEX_INIT);
	data->forks = forks;
	return (ERR_SUCCESS);
}
