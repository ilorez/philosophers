/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:32:40 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/20 19:28:13 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int main(int ac, char **av)
{
  t_data *data;

  if (ac != 5 && ac != 6 )
    return (ft_print_syntax_error(av[0]));
  data = NULL;
  data = ft_init_data(data, ac, av);
  if (!data)
    return (EXIT_FAILURE);
  // create threads
  if (!ft_create_threads(data))
    return (EXIT_FAILURE);
  // waiting threads to finish by join them one by one
  // remember you can't use exit it's forbidden
  return (EXIT_SUCCESS);
}
