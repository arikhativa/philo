/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/23 11:29:23 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

# include <stdlib.h>

# include "timer.h"
# include "philo.h"
# include "fork.h"
# include "error_code.h"

typedef struct s_table
{
	int				num_of_philo;
	t_philo			**philo_list;
	t_fork			**fork_list;
	t_input			*i;
	t_m_value		*simulation_is_on;
	pthread_mutex_t	print_mutex;
}	t_table;

// table
t_error_code	table_create(t_table **ret, t_input	*i);
void			table_destroy(t_table *t);

// fork_list
void			table_fork_list_free(t_fork **list, int size);
t_error_code	table_fork_list_init(t_table *t, int num_of_philo);
t_fork			*table_get_left_fork_by_philo(t_fork **fork_list, int i);
t_fork			*table_get_right_fork_by_philo(t_fork **fork_list, \
	int i, int num_of_philo);

// philo_list
void			table_philo_list_free(t_philo **list, int size);
t_error_code	table_philo_list_init(t_table *t, t_input	*input);
void			table_philo_list_stop(t_philo **list, int size);
int				table_philo_list_is_dead(t_philo **list, int size);
int				table_philo_list_is_done(t_philo **list, int size);

// simulation
t_error_code	table_start_simulation(t_table *t);
t_error_code	stop_list(t_philo **list, int size);
t_error_code	table_stop_simulation(t_table *t);
void			table_monitor_simulation(t_table *t);

#endif
