/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:38:27 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/17 00:25:20 by sel-kham         ###   ########.fr       */
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
		behaviour("has taken a fork", timestamp_in_ms() - table->t0, ph->philo_id);
		if (ph->philo_id % 2)
			pthread_mutex_lock(&(ph->next_philo->fork));
		else
			pthread_mutex_lock(&(ph->prev_philo->fork));
		behaviour("has taken a fork", timestamp_in_ms() - table->t0, ph->philo_id);
		behaviour("is eating", timestamp_in_ms() - table->t0, ph->philo_id);
		usleep(table->time_to_eat * 1000);
		ph->last_meal = timestamp_in_ms();
		ph->num_times_eat++;
		pthread_mutex_unlock(&(ph->fork));
		behaviour("has put a fork", timestamp_in_ms() - table->t0, ph->philo_id);
		pthread_mutex_unlock(&(ph->next_philo->fork));
		behaviour("has put a fork", timestamp_in_ms() - table->t0, ph->philo_id);
		if (table->eat_num != -1 && ph->num_times_eat == table->eat_num)
			break ;
		behaviour("is sleeping", timestamp_in_ms() - table->t0, ph->philo_id);
		usleep(table->time_to_sleep * 1000);
		behaviour("is thinking", timestamp_in_ms() - table->t0, ph->philo_id);
		if (table->time_to_die < timestamp_in_ms() - ph->last_meal)
		{
			behaviour("died", timestamp_in_ms() - table->t0, ph->philo_id);
			return (table);
		}
	}
	return (NULL);
}
