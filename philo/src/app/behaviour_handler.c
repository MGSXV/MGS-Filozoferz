/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behaviour_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgs <mgs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:31:29 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/19 17:12:33 by mgs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

void	behaviour(long time, int philo_id, char *action)
{
	printf("%d %d %s\n", time, philo_id, action);
}

void	eating(t_table *table, t_philosofer *ph)
{
	pthread_mutex_lock(&(ph->fork));
	behaviour("has taken a fork", time_now(ph->table), ph->philo_id);
	pthread_mutex_lock(&(ph->next_philo->fork));
	behaviour("has taken a fork", time_now(ph->table), ph->philo_id);
	behaviour("is eating", time_now(table), ph->philo_id);
	usleep(table->time_to_eat * 1000);
	pthread_mutex_unlock(&(ph->fork));
	pthread_mutex_unlock(&(ph->next_philo->fork));
	ph->last_meal = timestamp_in_ms();
	ph->num_times_eat++;
}

void	sleeping(t_table *table, t_philosofer *ph)
{
	behaviour("is sleeping", time_now(table), ph->philo_id);
	usleep(table->time_to_sleep * 1000);
}

void	thinking(t_table *table, t_philosofer *ph)
{
	behaviour("is thinking", time_now(table), ph->philo_id);
}
