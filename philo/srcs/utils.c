/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:57:19 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/20 18:46:56 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_free_lst(void **lst)
{
  void **org;

  if (!lst)
         return ;
  org = lst;
  while (*lst)
    free(*lst++);
  free(org);
  return ;
}

time_t ft_time_now()
{
  time_t mills;
  struct timeval tv;

  gettimeofday(&tv, NULL); 
  mills = (time_t)tv.tv_sec * 1000 + (time_t)tv.tv_usec / 1000;
  return mills;
}


