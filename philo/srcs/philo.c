/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:32:40 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/19 15:04:02 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int main(int ac, char **av)
{
  t_data *data;
  t_bool status;

  if (ac != 5 || ac != 6 )
    return (ft_print_syntax_error(av[0]));

  // init data
  data = ft_init_data(data, ac, av);
  if (!data)
    return (EXIT_FAILER);
  // create threads
  if (!ft_create_threads(data))
    return (ft_free_data_error(data, "Error: create thread error\n"));
  // waiting threads to finish by join them one by one
  // remember you can't use exit it's forbidden
  if (!ft_join_threads(data));
    return (ft_free_data_error(data, "Error: joining threads error\n"));

  return (EXIT_SUCCESS);
}
