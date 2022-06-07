/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:45:27 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/07 10:57:44 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H

# define TYPES_H

typedef struct s_philosophers
{
	int	philos_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat_num;
}	t_philo_info;

typedef struct s_philosopher
{
	int						philo_id;
	struct s_philosopher	*next_philo;
	struct s_philosopher	*prev_philo;
	t_philo_info			*info;
}	t_philosofer;

#endif