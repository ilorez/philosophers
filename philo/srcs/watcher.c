/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:18:31 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/19 16:41:51 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


t_bool ft_watcher(t_data *data, t_philo **philos)
{
  unsigned int id;
  unsigned int time_now;

  id = 0;
  while (true)
  {
    if (id == data->philo_num)
      id = 0;
    pthread_mutex_lock((philos[id])->lstatus);
    if ((philos[id])->status == DONE)
    {
      pthread_mutex_lock(done->lfinish_count);
      if (data->finish_count == data->philo_num)
      {
        pthread_mutex_lock(done->lis_done);
        data->is_done = true;
        pthread_mutex_unlock(done->lis_done);
        break;
      }
      pthread_mutex_unlock(done->lfinish_count);
      pthread_mutex_unlock(done->lstatus);
      id++;
      continue;
    }
    pthread_mutex_lock((philos[id])->lstart_time);
    pthread_mutex_lock((philos[id])->lstatus);
    if (ft_time_now() - (philos[id])->start_time > data->tdie 
      && (philos[id])->status != EATING)
    {
      pthread_mutex_lock(done->lis_done);
      data->is_done = true;
      pthread_mutex_unlock(done->lis_done);
      (philos[id])->status = DIE;
      pthread_mutex_unlock(done->lstatus);
      ft_print_msg_status(philos[id]);
      pthread_mutex_unlock((philos[id])->lstart_time);
      break;
    }
    pthread_mutex_unlock(done->lstatus);
    pthread_mutex_unlock((philos[id])->lstart_time);
    id++;
  }
  return true;
}
