/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:54:49 by znajdaou          #+#    #+#             */
/*   Updated: 2025/03/03 11:32:18 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	_ft_count_digits(long nbr)
{
	size_t	i;

	i = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static void	_ft_stock(long nbr, size_t *i, char *result)
{
	long	mod;

	if (nbr > 9)
		_ft_stock(nbr / 10, i, result);
	mod = nbr % 10 + 48;
	result[*i] = mod;
	(*i)++;
}

char	*ft_itoa(long n)
{
	size_t	malloc_s;
	int		signe;
	char	*result;
	size_t	i;

	i = 0;
	signe = 1;
	malloc_s = 1;
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (n < 0)
	{
		signe = -1;
		malloc_s += 1;
		n = -n;
	}
	malloc_s += _ft_count_digits(n);
	result = ft_calloc(sizeof(char), malloc_s);
	if (!result)
		return (NULL);
	if (signe == -1)
		result[i++] = '-';
	_ft_stock(n, &i, result);
	result[malloc_s - 1] = '\0';
	return (result);
}
