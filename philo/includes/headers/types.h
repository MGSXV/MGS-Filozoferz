/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:45:27 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/19 21:22:42 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H

# define TYPES_H

# include "philosophers.h"

typedef struct s_table	t_table;
typedef struct s_philosopher
{
	int						philo_id;
	pthread_t				philosopher;
	struct s_philosopher	*next_philo;
	struct s_philosopher	*prev_philo;
	bool					is_dead;
	long					last_meal;
	int						num_times_eat;
	t_table					*table;
}	t_philosofer;

typedef struct s_table
{
	int				philos_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_num;
	long			t0;
	bool			someonedied;
	int				how_many_eats;
	pthread_mutex_t	print_locker;
	pthread_mutex_t	*forks;
	t_philosofer	*head;
}	t_table;

#endif