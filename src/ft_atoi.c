/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/23 11:29:23 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"

static int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || \
			c == '\f' || c == '\r' || c == ' ');
}

static char	*skip_space(char *s)
{
	while (is_space(*s))
		++s;
	return (s);
}

static char	*skip_get_sign(char *s, int *sign)
{
	*sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			*sign *= -1;
		++s;
	}
	return (s);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *nptr)
{
	char	*s;
	int		ret;
	int		sign;

	if (!nptr)
		return (0);
	s = (char *)nptr;
	ret = 0;
	s = skip_space(s);
	s = skip_get_sign(s, &sign);
	while (ft_isdigit(*s))
	{
		ret = (ret * 10) + (*s - '0');
		++s;
	}
	return (ret * sign);
}
