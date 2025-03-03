/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:51:57 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/03 12:37:09 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "t_errno.h"

static void	_ft_create_err_list(char *lst[ERR_COUNT])
{
	char	*err_msgs[ERR_COUNT];

	err_msgs[ERR_SUCCESS] = "OK\n";
	err_msgs[ERR_INVALID_ARG] = "invalid argument\n";
	err_msgs[ERR_EMPTY_ARG] = "Empty argumnet\n";
	err_msgs[ERR_MALLOC_FAIL] = "an allocation failed\n";
	err_msgs[ERR_FORK_FAILED] = "fork failed\n";
	err_msgs[ERR_MUTEX_INIT] = "mutex init failed\n";
	err_msgs[ERR_PHILO_NUM] = "philo num must be between [1, 200]\n";
	err_msgs[ERR_SEM_OPEN] = "fieled to create semaphore\n";
	err_msgs[ERR_PTHREAD_JOIN] = "pthread join failed\n";
	err_msgs[ERR_PTHREAD_CREATE] = "pthread create failed\n";
	err_msgs[ERR_MUTEX_DESTROY] = "pthread mutex destroy failed\n";
	err_msgs[ERR_ARG_RANGE_INT] = "invalid argument:\n\t \
make sure that <number of philos> and <max eat time> \
is between [1, INT_MAX]\n";
	err_msgs[ERR_ARG_RANGE] = "invalid argument out of range\n";
	err_msgs[ERR_UNKNOWN] = "Unknown error occurred\n";
	ft_memcpy(lst, err_msgs, sizeof(char *) * ERR_COUNT);
}

void	ft_strerr(t_errno error_code)
{
	char	*err_msgs[ERR_COUNT];

	_ft_create_err_list(err_msgs);
	if (error_code < 0 || error_code >= ERR_COUNT)
		error_code = ERR_UNKNOWN;
	ft_putstr_fd(err_msgs[error_code], STDERR_FILENO);
}

void	ft_perror(char *msg, t_errno error_code)
{
	char	*err_msgs[ERR_COUNT];

	_ft_create_err_list(err_msgs);
	if (error_code < 0 || error_code >= ERR_COUNT)
		error_code = ERR_UNKNOWN;
	if (!msg || !*msg)
		ft_putstr_fd("Error", STDERR_FILENO);
	else
		ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(err_msgs[error_code], STDERR_FILENO);
}

/*
int	main(int argc, char *argv[]) {
	// Example 1: Direct printing
	if (argc < 2) {
		ft_strerr(ERR_EMPTY_ARG);
		return (1);
	}
  else
		ft_perror(argv[1], ERR_SUCCESS);
	return (0);
}*/

/*static void	_ft_create_err_list(t_errno_msg lst[ERR_COUNT])
{
	t_errno_msg	err_msgs[ERR_COUNT];

	err_msgs[ERR_SUCCESS] = (t_errno_msg){ERR_SUCCESS, "OK\n"};
	err_msgs[ERR_INVALID_ARG] = (t_errno_msg){ERR_INVALID_ARG,
		"invalid argument\n"};
	err_msgs[ERR_EMPTY_ARG] = (t_errno_msg){ERR_EMPTY_ARG, "Empty argumnet\n"};
	err_msgs[ERR_MALLOC_FAIL] = (t_errno_msg){ERR_MALLOC_FAIL,
		"an allocation failed\n"};
	err_msgs[ERR_MUTEX_INIT] = (t_errno_msg){ERR_MUTEX_INIT,
		"mutex init failed\n"};
	err_msgs[ERR_PHILO_NUM] = (t_errno_msg){ERR_PHILO_NUM,
		"philo num must be between [1, 200]\n"};
	err_msgs[ERR_SEM_OPEN] = (t_errno_msg){ERR_SEM_OPEN,
		"fieled to create semaphore\n"};
	err_msgs[ERR_PTHREAD_JOIN] = (t_errno_msg){ERR_PTHREAD_JOIN,
		"pthread join failed\n"};
	err_msgs[ERR_PTHREAD_CREATE] = (t_errno_msg){ERR_PTHREAD_CREATE,
		"pthread create failed\n"};
	err_msgs[ERR_MUTEX_DESTROY] = (t_errno_msg){ERR_MUTEX_DESTROY,
		"pthread mutex destroy failed\n"};
	err_msgs[ERR_ARG_RANGE_INT] = (t_errno_msg){ERR_ARG_RANGE_INT,
		"invalid argument:\n\t \
make sure that <number of philos> and <max eat time> \
is between [1, INT_MAX]\n"};
	err_msgs[ERR_ARG_RANGE] = (t_errno_msg){ERR_ARG_RANGE,
		"invalid argument out of range\n"};
	err_msgs[ERR_UNKNOWN] = (t_errno_msg){ERR_UNKNOWN,
		"Unknown error occurred\n"};
	ft_memcpy(lst, err_msgs, sizeof(t_errno_msg) * ERR_COUNT);
}*/
