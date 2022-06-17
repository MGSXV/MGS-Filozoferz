/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgs <mgs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:38:27 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/17 18:44:03 by mgs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

void	*philosophers_handler(void *philo)
{
	t_philosofer	*ph;

	ph = (t_philosofer *) philo;
	while (true)
	{
		pthread_mutex_lock(&(ph->fork));
		behaviour("has taken a fork", time_now(ph->table), ph->philo_id);
		pthread_mutex_lock(&(ph->next_philo->fork));
		behaviour("has taken a fork", time_now(ph->table), ph->philo_id);
		eating(ph->table, ph);
		pthread_mutex_unlock(&(ph->fork));
		pthread_mutex_unlock(&(ph->next_philo->fork));
		if (ph->table->eat_num != -1 && ph->num_times_eat == ph->table->eat_num)
			break ;
		sleeping(ph->table, ph);
		thinking(ph->table, ph);
		if (ph->table->time_to_die < timestamp_in_ms() - ph->last_meal)
		{
			behaviour("died", time_now(ph->table), ph->philo_id);
			return (ph->table);
		}
	}
	return (NULL);
}
