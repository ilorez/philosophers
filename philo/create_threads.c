/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:41:46 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/17 17:29:05 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool ft_philo_life_cycle(t_data *data)
{
  while 

}

typedef enum s_pstatus
{
  WAITING_FORKS,
  EATING,
  SLEEPING,
  THINKING
} t_pstatus;
typedef struct s_philo 
{
  unsigned int id;
  t_pstatus status;

} t_philo;
t_bool create_threads(t_data *data)
{
  pthread_t **ths;
  unsigned int id;
  t_philo 

  ths = ft_calloc(1, sizeof(pthread_t) * data->philo_num);
  id = -1;
  while (++(data->id) <= data->philo_num)
  {

    if (pthread_create(&(ths[data->id - 1]), NULL, &ft_philo_life_cycle, data))
      return (false);
  }
  // who to give a thread it's id
  // joining threads
  while ()
}




