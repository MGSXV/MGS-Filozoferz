/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behaviour_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:31:29 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/19 21:23:01 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

void	behaviour(long time, int philo_id, char *action, t_table *table)
{
	pthread_mutex_lock(&(table)->print_locker);
	printf("%ld %d %s\n", time, philo_id, action);
	pthread_mutex_unlock(&(table)->print_locker);
}

void	eating(t_table *table, t_philosofer *ph)
{
	int	min;
	int	max;

	min = min_number(ph->philo_id, ph->next_philo->philo_id);
	max = max_number(ph->philo_id, ph->next_philo->philo_id);
	pthread_mutex_lock(&(table->forks[min - 1]));
	behaviour(time_now(ph->table), ph->philo_id, "has taken a fork", table);
	pthread_mutex_lock(&(table->forks[max - 1]));
	behaviour(time_now(ph->table), ph->philo_id, "has taken a fork", table);
	behaviour(time_now(table), ph->philo_id, "is eating", table);
	ph->last_meal = time_now(table);
	usleep(table->time_to_eat * 1000);
	ph->num_times_eat++;
	if (ph->num_times_eat == table->eat_num)
		table->how_many_eats++;
	pthread_mutex_unlock(&(table->forks[min - 1]));
	pthread_mutex_unlock(&(table->forks[max - 1]));
}

void	sleeping(t_table *table, t_philosofer *ph)
{
	behaviour(time_now(table), ph->philo_id, "is sleeping", table);
	usleep(table->time_to_sleep * 1000);
}

void	thinking(t_table *table, t_philosofer *ph)
{
	behaviour(time_now(table), ph->philo_id, "is thinkin", table);
}
