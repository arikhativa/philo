/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:42:52 by yoav              #+#    #+#             */
/*   Updated: 2022/08/29 15:49:29 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_action.h"

void	print_action(long timestamp, int id, const char *msg)
{
	long	now;

	now = timer_get_now();
	printf("%ld %d %s\n", (now - timestamp), id, msg);
}
