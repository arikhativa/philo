/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/23 11:29:23 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	bzero(void *ptr, size_t size)
{
	memset(ptr, ZERO, size);
}

int	is_even(int n)
{
	return (0 == (n % 2));
}

int	is_digit(char c)
{
	return ('0' <= c && '9' >= c);
}
