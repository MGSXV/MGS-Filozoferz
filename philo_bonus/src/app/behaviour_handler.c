/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behaviour_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:48:45 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/24 04:17:23 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers_bonus.h"

void	behaviour(long time, int philo_id, char *action, t_table *table)
{
	sem_wait(table->sem_print);
	if (!table->someonedied)
		printf("%ld %d %s\n", time, philo_id, action);
	sem_post(table->sem_print);
}

void	eating(t_table *table)
{
	sem_wait(table->sem_fork);
	behaviour(time_now(table), table->philo_id, "has taken a fork", table);
	sem_wait(table->sem_fork);
	behaviour(time_now(table), table->philo_id, "has taken a fork", table);
	behaviour(time_now(table), table->philo_id, "is eating", table);
	table->last_meal = time_now(table);
	table->num_times_eat++;
	ft_usleep(table->time_to_eat);
	sem_post(table->sem_fork);
	sem_post(table->sem_fork);
}

void	sleeping(t_table *table)
{
	ft_usleep(table->time_to_sleep);
	behaviour(time_now(table), table->philo_id, "is sleeping", table);
}

void	thinking(t_table *table)
{
	behaviour(time_now(table), table->philo_id, "is thinking", table);
}
