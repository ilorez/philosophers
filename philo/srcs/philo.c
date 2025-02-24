/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:32:40 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/24 18:31:22 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_t_data(const t_data *data)
{
    if (!data)
    {
        printf("Data is NULL.\n");
        return;
    }
    
    printf("t_data structure:\n");
    printf("  philo_num: %u\n", data->philo_num);
    printf("  max_eats: %u\n", data->max_eats);
    printf("  finish_count: %u\n", data->finish_count);
    printf("  tdie: %u\n", data->tdie);
    printf("  teat: %u\n", data->teat);
    printf("  tsleep: %u\n", data->tsleep);
    printf("  tthink: %u\n", data->tthink);
    printf("  the_start_time: %ld\n", data->the_start_time);
    printf("  is_done: %s\n", data->is_done ? "true" : "false");
    printf("  limited: %s\n", data->limited ? "true" : "false");
    
    printf("  Mutex Addresses:\n");
    printf("    lis_done: %p\n", (void*)&data->lis_done);
    printf("    lfinish_count: %p\n", (void*)&data->lfinish_count);
    printf("  Forks:\n");
    if (data->forks)
    {
        int i = 0;
        while ((data->forks)[i] != NULL)
        {
            printf("    forks[%d]: %p\n", i, (void*)(data->forks)[i]);
            i++;
        }
        printf("    forks[%d]: NULL\n", i);
    }
    else
    {
        printf("    forks: NULL\n");
    }
}

int main(int ac, char **av)
{
  t_data *data;

  if (ac != 5 && ac != 6 )
    return (ft_print_syntax_error(av[0])); // TODO:[X]: is it DONE
  data = NULL;
  data = ft_init_data(data, ac, av); // TODO:[ ]: is it DONE
  if (!data)
    return (EXIT_FAILURE);
  // print data test // TODO: REMOVE ME
  print_t_data(data);
  return (0);
  if (!ft_create_threads(data)) // TODO:[ ]: is it DONE
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
