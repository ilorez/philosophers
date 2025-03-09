/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_creature.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:06:38 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/09 10:31:22 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_errno	ft_wait_thread(pthread_t thr);
static t_errno	ft_philo_exit(t_philo *p, t_data *data, t_errno err);
static void		ft_child(t_data *d, int i);

t_errno	ft_philos_creature(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->philo_num)
	{
		d->pid[i] = fork();
		if (d->pid[i] == -1)
		{
			d->err = ERR_FORK_FAILED;
			sem_post(d->die.addr);
			break ;
		}
		else if (d->pid[i] == 0)
			ft_child(d, i);
	}
	i = -1;
	while (d->pid[++i])
		waitpid(d->pid[i], NULL, 0);
	return (d->err);
}

static void	ft_child(t_data *d, int i)
{
	t_philo	*p;

	p = ft_calloc(sizeof(t_philo), 1);
	if (!p)
		ft_philo_exit(p, d, ERR_MALLOC_FAIL);
	d->err = ft_philo_init(i + 1, d, p);
	if (d->err)
		ft_philo_exit(p, d, ERR_SUCCESS);
	ft_life_cycle(p);
	ft_philo_exit(p, d, ERR_SUCCESS);
}

static t_errno	ft_philo_exit(t_philo *p, t_data *data, t_errno err)
{
	sem_post(data->die.addr);
	if (p)
	{
		ft_wait_thread(p->self_watcher);
		ft_wait_thread(p->other_watcher);
	}
	ft_free_data(data, err);
	exit(ft_free_philo(p, err));
}

static t_errno	ft_wait_thread(pthread_t thr)
{
	void	*tmp;

	if (pthread_join(thr, &tmp) != 0)
		return (ERR_PTHREAD_JOIN);
	return (ERR_SUCCESS);
}
