/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:58:38 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/26 15:43:14 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void ft_msleep(time_t time)
{
  usleep(time * 1000);
}

void	*ft_philo_life_cycle(void *ptr)
{
	t_philo	*p;
  int left;


	p = (t_philo *)ptr;
  if (p->id % 2 == 0)
    left = p->id - 2;
  else 
    left = p->id - 1;
	// printf("philosopher id=>%d set in the table\n", p->id);
  while (!(p->data->limited) || (p->eats)++ < p->data->max_eats)
	{

    //printf("x point %d\n", p->id);
		pthread_mutex_lock(&(p->data->forks[left]));
		ft_print_msg_status(p);
		pthread_mutex_lock(&(p->data->forks[(left + 1) % p->data->philo_num]));
		ft_print_msg_status(p);
    //printf("y point %d\n", p->id);
		ft_change_status(p->data, p, EATING);
    //printf("z point %d\n", p->id);
		ft_change_time(&(p->start_time), &(p->lstart_time));
		ft_msleep(p->data->teat);
		pthread_mutex_unlock(&(p->data->forks[p->id % p->data->philo_num]));
		pthread_mutex_unlock(&(p->data->forks[p->id - 1]));
		ft_change_status(p->data, p, SLEEPING);
		ft_msleep(p->data->tsleep);
		ft_change_status(p->data, p, THINKING);
		//ft_msleep(p->data->tthink);
		pthread_mutex_lock(&(p->lstatus));
		p->status = WAITING_FORKS;
		pthread_mutex_unlock(&(p->lstatus));
    //printf("e point %d\n", p->id);
		pthread_mutex_lock(&(p->data->lis_done));
    if (p->data->is_done != 0)
      break;
		pthread_mutex_unlock(&(p->data->lis_done));
    //printf("$\n");
	}
	pthread_mutex_lock(&(p->lstatus));
	p->status = DONE;
	pthread_mutex_unlock(&(p->lstatus));
	pthread_mutex_lock(&(p->data->lfinish_count));
	p->data->finish_count += 1;
	pthread_mutex_unlock(&(p->data->lfinish_count));
  return (NULL);
}


