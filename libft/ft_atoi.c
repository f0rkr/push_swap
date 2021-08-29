/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:45:02 by mashad            #+#    #+#             */
/*   Updated: 2021/08/29 08:30:40 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int	ft_check(unsigned long pt, int s)
{
	long long n;

	n = (long long) pt * s;
	if (pt > 9223372036854775807 && s == -1)
		return (0);
	else if (n > 2147483647 || n < -2147483648)
		return (OVERFLOW);
	return (pt * s);
}

int	ft_atoi(const char *str)
{
	unsigned long long int	j;
	unsigned long long int	t_p;
	int						tt;

	tt = 1;
	j = 0;
	t_p = 0;
	while (*str >= 8 && *str <= 32)
	{
		if (*str == 27)
			return (0);
		str++;
	}
	if (*str == '-')
	{
		tt = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*(str + j) >= 48 && *(str + j) <= 57)
		t_p = t_p * 10 + (unsigned long long int)(*(str + j++) - '0');
	return (ft_check(t_p, tt));
}
