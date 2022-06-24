/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:04:44 by mgs               #+#    #+#             */
/*   Updated: 2022/06/24 04:16:49 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H

# define TYPES_H

# include "philosophers_bonus.h"

typedef struct s_table
{
	int				philo_id;
	int				philos_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_num;
	sem_t			*sem_fork;
	sem_t			*sem_print;
	sem_t			*sem_death;
	sem_t			*sem_full;
	long			t0;
	long			last_meal;
	int				num_times_eat;
	bool			someonedied;
	int				how_many_eats;
	pid_t			*pids;
}	t_table;

#endif