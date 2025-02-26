/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_creature.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:24:05 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/26 10:26:28 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	*ft_philo_life_cycle(void *ptr)
{
	t_philo	*p;

	p = (t_philo *)ptr;
	printf("philosopher id=>%d set in the table\n", p->id);
  return (NULL);
}

t_errno ft_threads_creature(t_data *data)
{
  t_philo			**philos;
	int	i;

	philos = (t_philo **)ft_calloc(sizeof(t_philo *), data->philo_num + 1);
	i = -1;
	while (++i < data->philo_num)
	{
		philos[i] = (t_philo *)ft_calloc(sizeof(t_philo), 1);
		philos[i]->id = i + 1;
		philos[i]->data = data;
		if (pthread_mutex_init(&(philos[i]->lstatus), NULL) != 0)
			return (ft_free_philos(philos, ERR_MUTEX_INIT));
		if (pthread_mutex_init(&(philos[i]->lstart_time), NULL) != 0)
			return (ft_free_philos(philos, ERR_MUTEX_INIT));
	  ft_change_time(&(philos[i]->start_time), &(philos[i]->lstart_time));
		if (pthread_create(&(philos[i]->thr), NULL, &ft_philo_life_cycle, philos[i]) != 0)
		{
			pthread_mutex_lock(&(data->lis_done));
			data->is_done = true;
			pthread_mutex_unlock(&(data->lis_done));
			break ;
		}
	}
	ft_watcher(data, philos);
  return (ERR_SUCCESS);
}
