/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:18:44 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/23 11:18:45 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <string.h>

# include "macros.h"

void	bzero(void *ptr, size_t size);
int		is_even(int n);
int		is_digit(char c);

#endif
