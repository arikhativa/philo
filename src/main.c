/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:06:37 by yoav              #+#    #+#             */
/*   Updated: 2022/11/07 11:47:18 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av)
{
	t_error_code	err;
	t_table			*t;
	t_input			*i;

	err = input_create(&i);
	if (SUCCESS != err)
		return (error_code_print(err));
	err = input_init(i, ac, av);
	if (SUCCESS != err)
		return (error_code_print(err));
	err = table_create(&t, i);
	if (SUCCESS != err)
		return (error_code_print(err));
	table_start_simulation(t);
	table_monitor_simulation(t);
	table_stop_simulation(t);
	table_destroy(t);
	input_destroy(&i);
	return (SUCCESS);
}
