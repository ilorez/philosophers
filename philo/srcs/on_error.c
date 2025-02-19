/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:29:28 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/19 15:04:00 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *ft_on_error(char *err_msg)
{
  ft_putstr_fd(err_msg, STDERR_FILENO);
  return (NULL);
}

void *ft_free_data_error(t_data *data, char *err_msg)
{
  if (!data)
    return (NULL);
  if (data->forks)
    ft_free_lst(data->forks);
  free(data);
  ft_putstr_fd(err_msg, STDERR_FILENO);
  return (NULL);
}

int ft_print_syntax_error(char *program)
{
  printf("./%s <*number_of_philosophers> <*time_to_die> \
          <*time_to_eat> <time_to_sleep> \
          [number_of_times_each_philosopher_must_eat] \
          ", program);
  return (EXIT_FAILURE);
}
