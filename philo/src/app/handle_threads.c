/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgs <mgs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:36:59 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/17 18:49:41 by mgs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

bool	create_threads(t_table *table)
{
	int				i;
	t_philosofer	*tmp;

	i = -1;
	tmp = table->head;
	while (++i < table->philos_num)
	{
		tmp->last_meal = timestamp_in_ms();
		if (pthread_create(&(tmp->philosopher), NULL,
				philosophers_handler, (void *) tmp))
			return (false);
		tmp = tmp->next_philo;
	}
	return (true);
}

bool	join_threads(t_table *table)
{
	int				i;
	t_philosofer	*tmp;

	i = -1;
	tmp = table->head;
	while (++i < table->philos_num)
	{
		if (pthread_join(tmp->philosopher, NULL))
			return (false);
		tmp = tmp->next_philo;
	}
	return (true);
}

bool	init_mutexes(t_table **table)
{
	t_philosofer	*tmp;
	int				i;

	i = -1;
	tmp = (*table)->head;
	while (++i < (*table)->philos_num && tmp)
	{
		if (pthread_mutex_init(&(tmp->fork), NULL))
			return (false);
		tmp = tmp->next_philo;
	}
	return (table);
}

bool	destroy_mutexes(t_table **table)
{
	t_philosofer	*tmp;
	int				i;

	i = -1;
	tmp = (*table)->head;
	while (++i < (*table)->philos_num && tmp)
	{
		if (pthread_mutex_destroy(&(tmp->fork)))
			return (false);
		tmp = tmp->next_philo;
	}
	return (true);
}
