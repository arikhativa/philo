/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:21:46 by yoav              #+#    #+#             */
/*   Updated: 2022/11/07 12:24:51 by yoav             ###   ########.fr       */
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

int	is_last_philo(int id, int num_of_philo)
{
	return (id == num_of_philo);
}

int	is_digit(char c)
{
	return ('0' <= c && '9' >= c);
}
