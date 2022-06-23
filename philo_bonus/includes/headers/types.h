/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:04:44 by mgs               #+#    #+#             */
/*   Updated: 2022/06/23 23:20:37 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H

# define TYPES_H

# include "philosophers_bonus.h"

// typedef struct s_table	t_table;
// typedef struct s_philosopher
// {
// 	int						philo_id;
// 	pthread_t				philosopher;
// 	struct s_philosopher	*next_philo;
// 	struct s_philosopher	*prev_philo;
// 	long					last_meal;
// 	int						num_times_eat;
// 	t_table					*table;
// }	t_philosofer;

typedef struct s_table
{
	int 			philo_id;
	int				philos_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_num;
	sem_t			*sem_fork;
	sem_t			*sem_print;
	sem_t			*sem_death;
	long			t0;
	long			last_meal;
	int				num_times_eat;
	bool			someonedied;
	int				how_many_eats;
	// t_philosofer	*head;
}	t_table;

#endif