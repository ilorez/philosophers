/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:57:19 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/19 16:49:08 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void ft_show_state_msg(unsigned int time, int pid, char *status);
{
  printf("%u %d %s\n", time, pid, status);
  return ;
}

void ft_free_lst(void **lst)
{
  if (!lst)
         return ;
  while (*lst)
    free(*lst++);
  free(lst);
  return ;
}


