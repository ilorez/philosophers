/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:32:40 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/26 13:34:51 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 5 && ac != 6)
		return (ft_print_syntax_error(av[0]));
	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (ft_perror(NULL, ERR_MALLOC_FAIL), ERR_MALLOC_FAIL);
  if (ft_init_data(data, ac, av) != 0)
    return (ft_free_data(data, data->err));
	data->err = ft_threads_creature(data); // TODO:[ ]: is it DONE
	return (ft_free_data(data, data->err));
}

/*
void	print_t_data(const t_data *data)
{
	int	i;

	if (!data)
	{
		printf("Data is NULL.\n");
		return ;
	}
	printf("t_data structure:\n");
	printf("  philo_num: %u\n", data->philo_num);
	printf("  max_eats: %u\n", data->max_eats);
	printf("  finish_count: %u\n", data->finish_count);
	printf("  tdie: %lu\n", data->tdie);
	printf("  teat: %lu\n", data->teat);
	printf("  tsleep: %lu\n", data->tsleep);
	printf("  tthink: %lu\n", data->tthink);
	printf("  the_start_time: %ld\n", data->start_time);
	printf("  is_done: %s\n", data->is_done ? "true" : "false");
	printf("  limited: %s\n", data->limited ? "true" : "false");
	printf("  Mutex Addresses:\n");
	printf("    lis_done: %p\n", (void *)&data->lis_done);
	printf("    lfinish_count: %p\n", (void *)&data->lfinish_count);
	printf("  Forks:\n");
	if (data->forks)
	{
		i = 0;
		while (i < data->philo_num)
		{
			printf("    forks[%d]: %p\n", i, (void *)&(data->forks)[i]);
			i++;
		}
		printf("    forks[%d]: NULL\n", i);
	}
	else
	{
		printf("    forks: NULL\n");
	}
}*/
