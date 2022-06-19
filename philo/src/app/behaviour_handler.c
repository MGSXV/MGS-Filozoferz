/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behaviour_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgs <mgs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:31:29 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/19 17:25:10 by mgs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

void	behaviour(long time, int philo_id, char *action)
{
	printf("%ld %d %s\n", time, philo_id, action);
}

void	eating(t_table *table, t_philosofer *ph)
{
	pthread_mutex_lock(&(table->forks[ph->philo_id - 1]));
	pthread_mutex_lock(&(table->forks[ph->philo_id - 1]));
	behaviour(time_now(ph->table), ph->philo_id, "has taken a fork");
	behaviour(time_now(ph->table), ph->philo_id, "has taken a fork");
	behaviour(time_now(table), ph->philo_id, "is eating");
	usleep(table->time_to_eat * 1000);
	pthread_mutex_unlock(&(table->forks[ph->philo_id - 1]));
	pthread_mutex_unlock(&(table->forks[ph->philo_id - 1]));
	ph->last_meal = timestamp_in_ms();
	ph->num_times_eat++;
}

void	sleeping(t_table *table, t_philosofer *ph)
{
	behaviour(time_now(table), ph->philo_id, "is sleeping");
	usleep(table->time_to_sleep * 1000);
}

void	thinking(t_table *table, t_philosofer *ph)
{
	behaviour(time_now(table), ph->philo_id, "is thinkin");
}
