/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:38:27 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/17 01:00:03 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

void	*philosophers_handler(void *philo)
{
	t_philosofer	*ph;
	t_table			*table;

	ph = (t_philosofer *) philo;
	table = (t_table *)(ph->table);
	while (true)
	{
		pthread_mutex_lock(&(ph->fork));
		behaviour("has taken a fork", time_now(table), ph->philo_id);
		pthread_mutex_lock(&(ph->next_philo->fork));
		behaviour("has taken a fork", time_now(table), ph->philo_id);
		eating(table, ph);
		pthread_mutex_unlock(&(ph->fork));
		pthread_mutex_unlock(&(ph->next_philo->fork));
		if (table->eat_num != -1 && ph->num_times_eat == table->eat_num)
			break ;
		sleeping(table, ph);
		thinking(table, ph);
		if (table->time_to_die < timestamp_in_ms() - ph->last_meal)
		{
			behaviour("died", time_now(table), ph->philo_id);
			return (table);
		}
	}
	return (NULL);
}
