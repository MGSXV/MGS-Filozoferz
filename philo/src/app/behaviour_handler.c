/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behaviour_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgs <mgs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:31:29 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/19 18:13:55 by mgs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

void	behaviour(long time, int philo_id, char *action)
{
	printf("%ld %d %s\n", time, philo_id, action);
}

void	eating(t_table *table, t_philosofer *ph)
{
	int	min;
	int	max;

	min = min_number(ph->philo_id, ph->next_philo->philo_id);
	max = max_number(ph->philo_id, ph->next_philo->philo_id);
	pthread_mutex_lock(&(table->forks[min - 1]));
	pthread_mutex_lock(&(table->forks[max - 1]));
	behaviour(time_now(ph->table), ph->philo_id, "has taken a fork");
	behaviour(time_now(ph->table), ph->philo_id, "has taken a fork");
	behaviour(time_now(table), ph->philo_id, "is eating");
	ph->last_meal = time_now(table);
	usleep(table->time_to_eat * 1000);
	ph->num_times_eat++;
	pthread_mutex_unlock(&(table->forks[min - 1]));
	pthread_mutex_unlock(&(table->forks[max - 1]));
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
