/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgs <mgs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:24:18 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/20 11:53:34 by mgs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/headers/philosophers.h"

static bool	death_detector(t_table *table)
{
	t_philosofer	*ph;

	ph = table->head;
	while (1)
	{
		if (ph->table->time_to_die < time_now(ph->table) - ph->last_meal || \
			table->how_many_eats == table->philos_num)
		{
			behaviour(time_now(table), ph->philo_id, "died", table);
			return (false);
		}
		ph = ph->next_philo;
	}
	return (true);
}

int	main(int c, char **v)
{
	t_table			*table;

	if (!manage_inputs(c, v))
		return (2);
	table = malloc(sizeof(t_table));
	if (!table)
		return (2);
	if (!init_app(&table, c, v))
		return (2);
	if (!init_philosophers(table))
		return (2);
	if (!init_mutexes(&table))
		return (2);
	if (!create_threads(table))
		return (2);
	death_detector(table);
	join_threads(table);
	destroy_mutexes(&table);
	free_all(&table);
	return (0);
}
