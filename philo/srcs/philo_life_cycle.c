/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:58:38 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/13 11:15:09 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	ft_hold_forks(t_philo *p, pthread_mutex_t *forks, int a, int b)
{
	pthread_mutex_lock(&(forks[a]));
	ft_print_msg_status(p);
	if (a == b)
	{
		pthread_mutex_unlock(&(forks[a]));
		return (false);
	}
	pthread_mutex_lock(&(forks[b]));
	ft_print_msg_status(p);
	return (true);
}

// philo habits
t_bool	ft_life_habits(t_data *data, t_philo *p, int first, int second)
{
	ft_dely(p->data->start_time, &(data->is_done), &(data->lis_done));
	if (p->id % 2 == 0)
		ft_think_time(p, true);
	while (true)
	{
		if (!ft_hold_forks(p, data->forks, first, second))
			return (false);
		ft_change_status(data, p, EATING);
		ft_change_time(&(p->start_time), &(p->lstart_time));
		ft_msleep(data->teat, &(data->is_done), &(data->lis_done));
		pthread_mutex_unlock(&(data->forks[first]));
		pthread_mutex_unlock(&(data->forks[second]));
		if (ft_mutex_cond(&(data->is_done), &(data->lis_done)))
			break ;
		if ((++(p->eats) >= data->max_eats && data->limited))
			break ;
		ft_change_status(data, p, SLEEPING);
		ft_msleep(data->tsleep, &(data->is_done), &(data->lis_done));
		ft_change_status(data, p, THINKING);
		ft_think_time(p, false);
		pthread_mutex_lock(&(p->lstatus));
		p->status = WAITING_FORKS;
		pthread_mutex_unlock(&(p->lstatus));
	}
	return (true);
}

// id start counting from 1 not 0
void	*ft_philo_life_cycle(void *ptr)
{
	t_philo	*p;
	int		first;
	int		second;

	p = (t_philo *)ptr;
	if (p->id % 2 == 0)
	{
		first = p->id % p->data->philo_num;
		second = p->id - 1;
	}
	else
	{
		first = p->id - 1;
		second = p->id % p->data->philo_num;
	}
	if (!ft_life_habits(p->data, p, first, second))
		return (NULL);
	pthread_mutex_lock(&(p->lstatus));
	p->status = DONE;
	pthread_mutex_unlock(&(p->lstatus));
	pthread_mutex_lock(&(p->data->lfinish_count));
	p->data->finish_count += 1;
	pthread_mutex_unlock(&(p->data->lfinish_count));
	return (NULL);
}
