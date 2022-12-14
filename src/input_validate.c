/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/12/08 10:07:35 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static int	check_digit(char *s)
{
	while (*s)
	{
		if (!is_digit(*s))
			return (ERROR);
		++s;
	}
	return (SUCCESS);
}

t_error_code	input_validate(int ac, char **av)
{
	int	i;

	if (MIN_ARG > ac)
		return (ERROR_MISSING_ARG);
	else if (MAX_ARG < ac)
		return (ERROR_TOO_MANY_ARG);
	i = 1;
	while (i < ac)
	{
		if (SUCCESS != check_digit(av[i]))
			return (ERROR_NON_DIGIT_ARG);
		++i;
	}
	return (SUCCESS);
}

static t_error_code	check_field(int f)
{
	if (0 == f)
		return (ERROR);
	return (SUCCESS);
}

t_error_code	input_validate_object(t_input *i)
{
	t_error_code	err;

	err = SUCCESS;
	err += check_field(i->meals_to_eat);
	err += check_field(i->time_to_sleep);
	err += check_field(i->time_to_die);
	err += check_field(i->time_to_eat);
	if (SUCCESS == err && 1 == i->philo)
	{
		printf("%ld %d %s\n", (long)i->time_to_die, 1, "died");
		return (ERROR_ONE_PHILO);
	}
	err += check_field(i->philo);
	if (SUCCESS != err)
		return (ERROR);
	return (SUCCESS);
}
