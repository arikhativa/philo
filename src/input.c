/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:39:10 by yoav              #+#    #+#             */
/*   Updated: 2022/11/07 12:19:33 by yoav             ###   ########.fr       */
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
	i->philo = ft_atoi(av[1]);
	i->time_to_die = ft_atoi(av[2]);
	i->time_to_eat = ft_atoi(av[3]);
	i->time_to_sleep = ft_atoi(av[4]);
	if (6 == ac)
		i->meals_to_eat = ft_atoi(av[5]);
	else
		i->meals_to_eat = ERROR;
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
		%d\n\ttime_to_sleep: %d\n\tmeals_to_eat: %d\n", \
		i->philo, i->time_to_die, i->time_to_eat, i->time_to_sleep, \
		i->meals_to_eat);
}
