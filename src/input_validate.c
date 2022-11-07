/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:39:10 by yoav              #+#    #+#             */
/*   Updated: 2022/11/07 12:30:07 by yoav             ###   ########.fr       */
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
		{
			return (ERROR_NON_DIGIT_ARG);
		}
		++i;
	}
	return (SUCCESS);
}