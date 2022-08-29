/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:06:37 by yoav              #+#    #+#             */
/*   Updated: 2022/08/29 13:20:54 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_error_code	err;
	t_table			*t;

	err = table_create(&t, 2);
	if (SUCCESS != err)
	{
		error_code_print(err);
		return (err);
	}
	table_start_simulation(t);
	sleep(2);
	table_stop_simulation(t);
	table_destroy(t);
	return (SUCCESS);
}
