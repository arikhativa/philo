/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:39:10 by yoav              #+#    #+#             */
/*   Updated: 2022/11/03 15:01:34 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

t_error_code	input_create(t_input **ret)
{
	t_input	*i;

	i = malloc(sizeof(t_input));
	if (!i)
		return (ALLOCATION_ERROR);
	*ret = i;
	return (SUCCESS);
}

t_error_code	input_init(t_input *i, int ac, char **av)
{
	if (MIN_ARG > ac)
		return (ERROR_MISSING_ARG);
	else if (MAX_ARG < ac)
		return (ERROR_TOO_MANY_ARG);
	i->philo = ft_atoi(av[1]);
	i->time_to_die = ft_atoi(av[2]);
	i->time_to_eat = ft_atoi(av[3]);
	i->time_to_sleep = ft_atoi(av[4]);
	if (6 == ac)
		i->should_eat = ft_atoi(av[5]);
	else
		i->should_eat = ERROR;
	return (SUCCESS);
}

void	input_destroy(t_input **obj)
{
	t_input	*i;
	
	i = *obj;
	free(i);
	*obj = NULL;
}

void	input_print(t_input *i)
{
	printf("input:\n\tphilo: %d\n\ttime_to_die: %d\n\ttime_to_eat: \
		%d\n\ttime_to_sleep: %d\n\tshould_eat: %d\n", \
		i->philo, i->time_to_die, i->time_to_eat, i->time_to_sleep, \
		i->should_eat);
}