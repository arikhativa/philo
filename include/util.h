/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:23:04 by yoav              #+#    #+#             */
/*   Updated: 2022/11/07 12:21:15 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <string.h>

# include "macros.h"

void	bzero(void *ptr, size_t size);
int		is_even(int n);
int		is_digit(char c);
int		is_last_philo(int id, int num_of_philo);

#endif
