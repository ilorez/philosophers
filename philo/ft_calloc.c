/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:05:34 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/16 18:07:39 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.c"

void	ft_bzero(void *s, size_t n)
{
	memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	t;
	void	*ptr;

	if (size != 0 && (count > ((size_t)-1 / size)))
		return (NULL);
	t = count * size;
	ptr = malloc(t);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, t);
	return (ptr);
}


