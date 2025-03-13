/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:06:37 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/13 09:37:39 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// include
static int		ft_parsing_params(t_data *data, int ac, char **av);
static t_bool	ft_is_valid(char *str);
static t_errno	ft_get_time_t(char *str, time_t *num, t_errno *err);
static t_errno	ft_get_int(char *str, int *num, t_errno *err);

t_errno	ft_init_data(t_data *data, int ac, char **av)
{
	if (ft_parsing_params(data, ac, av))
		return (data->err);
	data->pid = ft_calloc(sizeof(int), data->philo_num + 1);
	if (!(data->pid))
	{
		data->err = ERR_MALLOC_FAIL;
		return (data->err);
	}
	if (!ft_sem_open(&(data->forks), data->philo_num, &(data->err))
		|| !ft_sem_open(&(data->half), data->philo_num / 2, &(data->err))
		|| !ft_sem_open(&(data->die_gate), 1, &(data->err))
		|| !ft_sem_open(&(data->inform), 0, &(data->err))
		|| !ft_sem_open(&(data->write), 1, &(data->err))
		|| !ft_sem_open(&(data->done), 0, &(data->err))
		|| !ft_sem_open(&(data->die), 0, &(data->err)))
		return (data->err);
	data->start_time = ft_time_now() + data->philo_num * 20;
	ft_set_msg_status(data);
	return (data->err);
}

static int	ft_parsing_params(t_data *d, int ac, char **av)
{
	ft_get_time_t(av[4], &(d->tsleep), &(d->err));
	ft_get_time_t(av[3], &(d->teat), &(d->err));
	ft_get_time_t(av[2], &(d->tdie), &(d->err));
	ft_get_int(av[1], &(d->philo_num), &(d->err));
	if (d->philo_num > MAX_PHILO_NUM || d->philo_num < MIN_PHILO_NUM)
		d->err = ERR_PHILO_NUM;
	if (!(d->err) && ac == 6)
	{
		ft_get_int(av[5], &(d->max_eats), &(d->err));
		d->limited = true;
		if (!(d->err) && d->max_eats == 0)
			d->err = ERR_COUNT;
	}
	return (d->err);
}

static t_bool	ft_is_valid(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

static t_errno	ft_get_int(char *str, int *num, t_errno *err)
{
	long long	re;

	if (!ft_is_valid(str))
	{
		*err = ERR_INVALID_ARG;
		return (*err);
	}
	re = ft_atol(str);
	if (re < 0 || re > INT_MAX)
	{
		*err = ERR_ARG_RANGE_INT;
		return (*err);
	}
	*num = (int)re;
	return (ERR_SUCCESS);
}

static t_errno	ft_get_time_t(char *str, time_t *num, t_errno *err)
{
	long long	re;

	if (!ft_is_valid(str))
	{
		*err = ERR_INVALID_ARG;
		return (*err);
	}
	re = ft_atol(str);
	if (re < 0 || re > MAX_ARG_RANGE)
	{
		*err = ERR_ARG_RANGE;
		return (*err);
	}
	*num = (time_t)re;
	return (ERR_SUCCESS);
}
