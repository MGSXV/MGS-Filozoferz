/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:36:59 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/16 23:19:05 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

void	*create_threads(t_table *table)
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
			return (NULL);
		tmp = tmp->next_philo;
	}
	return (table);
}

void	*join_threads(t_table *table)
{
	int				i;
	t_philosofer	*tmp;

	i = -1;
	tmp = table->head;
	while (++i < table->philos_num)
	{
		if (pthread_join(tmp->philosopher, NULL))
			return (NULL);
		tmp = tmp->next_philo;
	}
	return (table);
}

void	*init_mutexes(t_table **table)
{
	t_philosofer	*tmp;
	int				i;

	i = -1;
	tmp = (*table)->head;
	while (++i < (*table)->philos_num && tmp)
	{
		if (pthread_mutex_init(&(tmp->fork), NULL))
			return (NULL);
		tmp = tmp->next_philo;
	}
	return (table);
}

void	*destroy_mutexes(t_table **table)
{
	t_philosofer	*tmp;
	int				i;

	i = -1;
	tmp = (*table)->head;
	while (++i < (*table)->philos_num && tmp)
	{
		if (pthread_mutex_destroy(&(tmp->fork)))
			return (NULL);
		tmp = tmp->next_philo;
	}
	return (table);
}
