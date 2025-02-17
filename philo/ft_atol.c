/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:52:50 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/17 14:55:14 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	_ft_max_as_signe(int signe)
{
	if (signe == 1)
		return (LLONG_MAX);
	return (LLONG_MIN);
}

/*
 * ft_atol,
 * function converts the initial portion of the string
 * pointed to by nptr to intis function
 *
 * @return: long long integer
 * on case of overflow return LLONG_MAX or LLONG_MIN dependent on signe
 *
 * */
long long	ft_atol(const char *nptr)
{
	size_t					i;
	int						signe;
	unsigned long long int	re;

	i = 0;
	signe = 1;
	re = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			signe = -1;
	while (ft_isdigit(nptr[i]))
	{
		if (re > (unsigned long long int)((LLONG_MAX - (nptr[i] - 48)) / 10))
			return (_ft_max_as_signe(signe));
		re = re * 10 + (nptr[i++] - 48);
	}
	return (re * signe);
}
