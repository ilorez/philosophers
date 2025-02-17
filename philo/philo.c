/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:32:40 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/16 18:04:14 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
  t_data *data;
  t_bool status;

  if (ac < 5)
    ft_print_syntax_error(av[0]);

  // init data
  data = ft_init_data(data, ac, av);
  if (!data)
    return (ft_print_error());
  // create threads
  if (!ft_create_threads(data))
    return (ft_print_error());
  // waiting threads to finish by join them one by one
  // remember you can't use exit it's forbidden
  ft_join_threads(data);
  return (EXIT_SUCCESS);
}
