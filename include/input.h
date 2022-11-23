/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/23 11:29:23 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <stdlib.h>

# include "macros.h"
# include "ft_atoi.h"
# include "util.h"
# include "error_code.h"

typedef int	t_ms;

typedef struct s_input
{
	int		philo;
	t_ms	time_to_die;
	t_ms	time_to_eat;
	t_ms	time_to_sleep;
	int		meals_to_eat;
}	t_input;

t_error_code	input_create(t_input **ret);
t_error_code	input_validate(int ac, char **av);
t_error_code	input_init(t_input *i, int ac, char **av);
void			input_destroy(t_input **obj);
void			input_print(t_input *i);
t_error_code	input_validate_object(t_input *i);

#endif
