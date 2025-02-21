/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:41:46 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/21 16:22:15 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool ft_create_threads(t_data *data)
{
  t_philo *philos;
  void *tmp;
  unsigned int i;

  //printf("hello here 2\n"); // TODO: remove me
  philos = (t_philo *)ft_calloc(sizeof(t_philo), data->philo_num + 1);
  i = -1;
  while (++(i) < data->philo_num)
  {
    //philos[i] = ft_calloc(sizeof(t_philo), 1);
    (philos[i]).id = i+1;
    (philos[i]).data = data;
    if (pthread_mutex_init(&((philos[i]).lstatus), NULL) != 0)
      return (t_bool)ft_usefree(data, philos, "Error: pthread_mutex_init\n");
    if (pthread_mutex_init(&((philos[i]).lstart_time), NULL) != 0)
      return (t_bool)ft_usefree(data, philos, "Error: pthread_mutex_init\n");
    if (pthread_create(&((philos[i]).thr), NULL, &ft_philo_life_cycle, &(philos[i])) != 0)
    {
      pthread_mutex_lock(&(data->lis_done));
      data->is_done = true;
      pthread_mutex_unlock(&(data->lis_done));
      break;
    }
  }
  while (true)
    continue;
  ft_watcher(data, philos);
  // joining threads
  i = -1;
  while (++i < data->philo_num)
    if (pthread_join((philos[i]).thr, &tmp))
      ft_usefree(data, philos, "Error: pthread join\n");
  // free threads
  ft_usefree(data, philos, NULL);
  //printf("hello here 2\n"); // TODO: remove me
  return (true);
}

