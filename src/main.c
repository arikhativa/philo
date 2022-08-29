/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:06:37 by yoav              #+#    #+#             */
/*   Updated: 2022/08/29 12:32:00 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_error_code	err;
	t_table	*t;

	t = NULL;
	err = table_create(&t, 2);
	error_code_print(err);
	printf("%d\n", t->num_of_philo);
	table_destroy(t);
	return (SUCCESS);
}
