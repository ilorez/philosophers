/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:32:40 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/28 14:13:01 by znajdaou         ###   ########.fr       */
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
	data->err = ft_threads_creature(data);
	return (ft_free_data(data, data->err));
}
