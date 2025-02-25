/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:30:43 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/25 10:10:17 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*udst;
	const unsigned char	*usrc;

	if (dst == src)
		return (dst);
	udst = (unsigned char *)dst;
	usrc = (const unsigned char *)src;
	i = -1;
	while (++i < n)
		*(udst + i) = *(usrc + i);
	return (dst);
}
