/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:38:43 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/13 10:57:05 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "t_errno.h"
# include <fcntl.h> /* For O_* constants */
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
// #include <signal.h>  /* for kill */
// #include <sys/stat.h>        /* For mode constants */

# define MAX_PHILO_NUM 200
# define MAX_ARG_RANGE 2147483649
// it's should always be between [0,
// long long[  NOTE: long long not included

// max: 9223372036854775806

// t_bool type
typedef enum s_bool
{
	false,
	true
}					t_bool;

typedef enum s_pstatus
{
	WAITING_FORKS = 0,
	EATING,
	SLEEPING,
	THINKING,
	DIE,
	DONE
}					t_pstatus;

typedef struct s_sem
{
	char			*name;
	sem_t			*addr;
}					t_sem;

typedef struct s_data
{
	int				philo_num;
	int				max_eats;
	time_t			tdie;
	time_t			teat;
	time_t			tsleep;
	time_t			tthink;
	time_t			start_time;
	t_bool			limited;
	t_errno			err;
	t_sem			forks;
	t_sem			write;
	t_sem			die;
	t_sem			inform;
	t_sem			die_gate;
	t_sem			half;
	t_sem			done;
	pthread_t		doorman;
	char			*status[DONE];
	int				*pid;
}					t_data;

typedef struct s_philo
{
	unsigned int	id;
	int				eats;
	time_t			start_time;
	t_pstatus		status;
	pthread_t		self_watcher;
	pthread_t		other_watcher;
	int				is_done;
	pthread_mutex_t	lis_done;
	pthread_mutex_t	lstart_time;
	pthread_mutex_t	lstatus;
	t_data			*data;
}					t_philo;
// functions
// init data
t_errno				ft_init_data(t_data *data, int ac, char **av);

// on errors
// void *ft_on_error(char *err_msg);
int					ft_print_syntax_error(char *program);
t_errno				ft_free_data(t_data *data, t_errno err);
t_errno				ft_free_philo(t_philo *philo, t_errno err);

// utils
time_t				ft_time_now(void);
void				ft_change_time(time_t *var, pthread_mutex_t *lock);
// void				ft_dely(time_t time);
void				ft_dely(time_t end, int *check, pthread_mutex_t *lock);
t_bool				ft_mutex_cond(int *cond, pthread_mutex_t *lock);
void				ft_change_status(t_philo *philo, t_pstatus to);
char				*ft_itoa(long n);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);

// utils folder
long long			ft_atol(const char *nptr);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
int					ft_isdigit(int c);
int					ft_isspace(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);

// print msg status
void				ft_print_msg_status(t_philo *philo);
void				ft_set_msg_status(t_data *data);

// philo utils
void				ft_msleep(time_t time, int *check, pthread_mutex_t *lock);
void				ft_think_time(t_philo *p, t_bool start);

// sema_utitls
char				*ft_randname(void *sema);
t_bool				ft_sem_open(t_sem *sema, int value, t_errno *err);
void				ft_free_t_sem(t_sem *sema);

// philos creature
t_errno				ft_philos_creature(t_data *d);

// philo init
t_errno				ft_philo_init(int id, t_data *data, t_philo *p);
// philo life
t_errno				ft_life_cycle(t_philo *p);

#endif
