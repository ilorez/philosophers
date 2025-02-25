/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:51:57 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/25 10:52:48 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "t_errno.h"

static void	_ft_create_err_list(t_errno_msg lst[ERR_COUNT])
{
	t_errno_msg	err_msgs[ERR_COUNT];

	err_msgs[ERR_SUCCESS] = (t_errno_msg){ERR_SUCCESS, "OK\n"};
	err_msgs[ERR_INVALID_ARG] = (t_errno_msg){ERR_INVALID_ARG,
		"invalid argument\n"};
	err_msgs[ERR_EMPTY_ARG] = (t_errno_msg){ERR_EMPTY_ARG, "Empty argumnet\n"};
	err_msgs[ERR_MALLOC_FAIL] = (t_errno_msg){ERR_MALLOC_FAIL,
		"an allocation failed\n"};
	err_msgs[ERR_MUTEX_INIT] = (t_errno_msg){ERR_MUTEX_INIT,
		"mutex init field\n"};
	err_msgs[ERR_ARG_RANGE_INT] = (t_errno_msg){ERR_ARG_RANGE_INT,
		"invalid argument out of range int\n"};
	err_msgs[ERR_ARG_RANGE] = (t_errno_msg){ERR_ARG_RANGE,
		"invalid argument out of range\n"};
	err_msgs[ERR_UNKNOWN] = (t_errno_msg){ERR_UNKNOWN,
		"Unknown error occurred\n"};
	ft_memcpy(lst, err_msgs, sizeof(t_errno_msg) * ERR_COUNT);
}

void	ft_strerr(t_errno error_code)
{
	t_errno_msg	err_msgs[ERR_COUNT];

	_ft_create_err_list(err_msgs);
	if (error_code < 0 || error_code >= ERR_COUNT)
		error_code = ERR_UNKNOWN;
	ft_putstr_fd(err_msgs[error_code].message, STDERR_FILENO);
}

void	ft_perror(char *msg, t_errno error_code)
{
	t_errno_msg	err_msgs[ERR_COUNT];

	_ft_create_err_list(err_msgs);
	if (error_code < 0 || error_code >= ERR_COUNT)
		error_code = ERR_UNKNOWN;
	if (!msg || !*msg)
		ft_putstr_fd("Error", STDERR_FILENO);
	else
		ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(err_msgs[error_code].message, STDERR_FILENO);
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
