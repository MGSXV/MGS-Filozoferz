/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behaviour_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:31:29 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/17 00:58:31 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

void	behaviour(char *action, int time, int philo_id)
{
	printf("%d %d %s\n", time, philo_id, action);
}

void	eating(t_table *table, t_philosofer *ph)
{
	behaviour("is eating", time_now(table), ph->philo_id);
	usleep(table->time_to_eat * 1000);
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