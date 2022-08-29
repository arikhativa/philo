/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:37:38 by yoav              #+#    #+#             */
/*   Updated: 2022/08/29 12:23:33 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

# include <stdlib.h>

# include "philo.h"
# include "fork.h"
# include "error_code.h"

typedef struct s_table
{
	int		num_of_philo;
	t_philo	**philo_list;
	t_fork	**fork_list;
}	t_table;

t_error_code	table_create(t_table **ret, int num_of_philo);
void			table_destroy(t_table *t);

#endif
