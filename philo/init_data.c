/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:47:14 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/17 14:40:51 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct s_data
{
  int philo_num;
  unsigned int tdie;
  unsigned int teat;
  unsigned int tsleep;
  unsigned int max_eat_times;
  t_bool is_somephilo_died;
  pthread_mutex_t *forks[];
} t_data;

static t_bool 

t_data *ft_init_data(t_data *data, int ac, char **av)
{
  data = ft_calloc(sizeof(data), 1);
  if (!data)
    return (NULL);
  // parsing data
  // create forks array
  // 



}
