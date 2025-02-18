/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:38:43 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/18 11:37:24 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>

// t_bool type
typedef enum s_bool
{
	false,
	true
}	t_bool;

typedef enum s_pstatus
{
  WAITING_FORKS = 0,
  EATING,
  SLEEPING,
  THINKING
} t_pstatus;

typedef struct s_philo 
{
  unsigned int id;
  pthread_t thr;
  t_pstatus status;
  unsigned int eats;
  t_data *data;
} t_philo;

typedef struct s_data
{
  unsigned int philo_num;
  unsigned int tdie;
  unsigned int teat;
  unsigned int tsleep;
  unsigned int max_eats;
  t_bool is_somephilo_died;
  t_bool limited;
  pthread_mutex_t *forks[];
} t_data;

// init data
t_data *ft_init_data(t_data *data, int ac, char **av);

// on errors
void *ft_on_error(char *err_msg);

#endif
