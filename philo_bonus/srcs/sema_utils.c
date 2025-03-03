/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sema_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:49:52 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/03 11:51:07 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_randname(void *sema)
{
	return (ft_itoa((long)ft_time_now() + (long)sema));
}

t_bool	ft_sem_open(t_sem *sema, int value, t_errno *err)
{
	sema->name = ft_randname(sema);
	if (!sema->name)
	{
		*err = ERR_MALLOC_FAIL;
		return (false);
	}
	sema->addr = sem_open(sema->name, O_CREAT | O_EXCL, 777, value);
	if (sema->addr == SEM_FAILED)
	{
		sema->addr = NULL;
		*err = ERR_SEM_OPEN;
		return (false);
	}
	return (true);
}

void	ft_free_t_sem(t_sem *sema)
{
	if (!sema)
		return ;
	if (sema->addr)
	{
		sem_close(sema->addr);
		if (sema->name)
			sem_unlink(sema->name);
	}
	if (sema->name)
		free(sema->name);
	return ;
}
