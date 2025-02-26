/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:38:43 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/26 09:59:16 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h> 
#include <sys/time.h>
#include <stdint.h>
#include "t_errno.h"

#define MAX_ARG_RANGE 2147483649 
// it's should always be between ]0, long long[  NOTE: o and long long not included
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
  THINKING,
  DIE,
  DONE,
  STATUS_COUNT
} t_pstatus;

typedef struct s_data
{
  int philo_num;
  int max_eats;
  int finish_count;
  size_t tdie;
  size_t teat;
  size_t tsleep;
  size_t tthink;
  time_t start_time;
  t_bool is_done;
  t_bool limited;
  t_errno err;
  pthread_mutex_t lis_done;
  pthread_mutex_t lfinish_count;
  pthread_mutex_t *forks;
} t_data;

typedef struct s_philo
{
  unsigned int id;
  unsigned int eats;
  time_t start_time;
  t_pstatus status;
  pthread_t thr;
  pthread_mutex_t lstart_time;
  pthread_mutex_t lstatus;
  t_data *data;
} t_philo;

// functions
// init data
t_errno ft_init_data(t_data *data, int ac, char **av);
// init forks
t_errno ft_init_forks(t_data *data);

// on errors
//void *ft_on_error(char *err_msg);
int ft_print_syntax_error(char *program);
t_errno	ft_free_philos(t_philo **philos, t_errno err);
t_errno ft_free_data(t_data *data, t_errno err);
// void *ft_usefree(t_data *data, t_philo **philos, t_errno msg);

// create threads
t_errno ft_threads_creature(t_data *data);
//t_bool ft_create_threads(t_data *data);

// philo life cycle
//void *ft_philo_life_cycle(void *ptr);
//void ft_change_time(time_t *var, pthread_mutex_t *lock);
//void ft_change_status(t_data *data, t_philo *philo, t_pstatus to);

// utils
void ft_free_lst(void **lst);
time_t ft_time_now();

// watcher
//t_bool ft_watcher(t_data *data, t_philo **philos);

// utils folder
long long	ft_atol(const char *nptr);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int	ft_isdigit(int c);
int	ft_isspace(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

// print msg status
void ft_print_msg_status(t_philo *philo);

#endif
