/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:32:40 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/03 12:38:26 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_t_data(const t_data *data);

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
	ft_philos_creature(data);
	return (ft_free_data(data, data->err));
}

/*
void	print_t_data(const t_data *data)
{
  int value;

  value = 99;
	if (!data)
	{
		printf("Data is NULL.\n");
		return ;
	}
	printf("t_data structure:\n");
	printf("  philo_num: %u\n", data->philo_num);
	printf("  max_eats: %u\n", data->max_eats);
	printf("  tdie: %lu\n", data->tdie);
	printf("  teat: %lu\n", data->teat);
	printf("  tsleep: %lu\n", data->tsleep);
	printf("  tthink: %lu\n", data->tthink);
	printf("  the_start_time: %ld\n", data->start_time);
	printf("  limited: %s\n", data->limited ? "true" : "false");
  sem_getvalue(data->forks.addr, &value);
  printf("  forks sema value is: %d\n", value);
  sem_getvalue(data->die.addr, &value);
  printf("  die sema value is: %d\n", value);
  sem_getvalue(data->write.addr, &value);
  printf("  print sema value is: %d\n", value);
}
*/
