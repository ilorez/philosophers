/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:47:14 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/21 15:38:36 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool _ft_create_forks(t_data *data)
{
  unsigned int i;

  i = -1;
  data->forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), (data->philo_num + 1));
  if (!(data->forks))
    return (ft_on_error("Error: forks allocation field\n"), false);
  while (++i < data->philo_num)
  {
    //((data->forks)[i]) = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), 1); 
    //if (((data->forks)[i]) == NULL)
     // return (ft_on_error("Error: fork allocation field\n"), false);
    if (pthread_mutex_init(&((data->forks)[i]), NULL) != 0)
      return (ft_on_error("Error: pthread mutex init\n"), false);
  }
  return (true);
}

static t_bool	_ft_is_valid(char *str)
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

static t_bool _ft_get_num(char *str, unsigned int *num)
{
  long long re;

  if (!_ft_is_valid(str))
    return (false);
  re = ft_atol(str);
  if (re <= 0 || re > INT_MAX)
    return (false);
  *num = (unsigned int) re;
  return true;
}

/* this function for init data by get argmunet info 
* and also it's create forks array using mutex_init for each fork 
* */
t_data *ft_init_data(t_data *data, int ac, char **av)
{

  data = ft_calloc(sizeof(data), 1);
  if (!data)
    return (ft_on_error("Error: could not allocate data\n"));

  //printf("hello here 1\n"); // TODO: remove me
  if (!_ft_get_num(av[1], &(data->philo_num)) 
      || !_ft_get_num(av[2], &(data->tdie))
      || !_ft_get_num(av[3], &(data->teat))
      || !_ft_get_num(av[4], &(data->tsleep))
      || (ac == 6 && !_ft_get_num(av[5], &(data->max_eats))))
      return (ft_free_data_error(data, "Error: invalid argument\n"));

  //printf("hello here 1\n"); // TODO: remove me
  if (ac == 6)
    data->limited = true;
  if (pthread_mutex_init(&(data->lis_done), NULL) != 0)
      return (ft_on_error("Error: pthread mutex init\n"));
  if (pthread_mutex_init(&(data->lfinish_count), NULL) != 0)
      return (ft_on_error("Error: pthread mutex init\n"));
  if (!_ft_create_forks(data))
    return (ft_free_data_error(data, NULL));
  data->the_start_time = ft_time_now();
  if (((long)data->tdie - (long)data->tsleep - (long)data->teat) < 0)
    data->tthink = 0;
  else 
    data->tthink = data->tdie - data->tsleep - data->teat;
  //printf("hello here 1\n"); // TODO: remove me
  return (data);
}
