/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:21:46 by yoav              #+#    #+#             */
/*   Updated: 2022/08/25 11:23:40 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	bzero(void *ptr, size_t size)
{
	memset(ptr, ZERO, size);
}
