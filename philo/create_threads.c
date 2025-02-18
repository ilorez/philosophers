/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:41:46 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/18 17:04:37 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//- the thread function let's call it ft_philo_life_cycle is also while function that do this:
//  -  the loop goes from 0 to number of eat before stop. 
//  - the first thing in the while is create another thread that should be detached after 
//    return, and it's used for checking if this mother philo has died, it's just  check the 
//    status of mother thread after usleep(time_to_die)
//    if the status is waiting_forks that's mean it's  died
//    so we set is_died true  && print die status and free memory and exit program
//    in other case it's should just return              
//  - after that we lock the both forks with order philo_id -1 , philo_id
//  - after each fork lock immediately should test if philo already died
//  - after each lock it's print state message that has take a fork
//  - after take both forks, it's print state message eating and wait time of eat
//  - after that it's immediately unlock forks
//  - start sleeping by print message status and sleep() time of sleep
//  - start thinking by print message status and sleep time of think
//  - here end of loop
//  - after loop the function return

t_bool ft_philo_life_cycle(t_philo *p)
{
  while (!p->data->limited || ++p->eats <= p->data->max_eats)
  {
    //  get time now 
    //  try to get forks
    //  change status after get boths
    //  check if there's a died philo 
    //  in case of died
    //  in case there's no died philo 
    //  eat
    //  put forks in the table
    //  sleep
    //  think
  }
  free(p->thr);
  free(p);
  return (true);
}

t_bool ft_philos_watcher(t_data *data, t_philo **philos)
{
  unsigned int id;

  id = -1;
  while (true && ++id)
  {
    id = data->philo_num % id;
    // check status of philo
    if ((philos[id])->status == waiting_forks)
    


  }
}

t_bool create_threads(t_data *data)
{
  t_philo **philos;
  unsigned int id;
  t_philo 

  philos = ft_calloc(sizeof(t_philo*), data->philo_num);
  i = -1;
  while (++(i) <= data->philo_num)
  {
    philos[i] = ft_calloc(sizeof(t_philo), 1);
    (philos[i])->id = i;
    (philos[i])->data = data;
    if (pthread_create(&((philos[i])->thr), NULL, &ft_philo_life_cycle, philos[i]))
      return (false);
  }
  // ft_philo_watcher: 
  //      - is a while function that watch threads status
  // joining threads
  // free threads
  while ()
}

