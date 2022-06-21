/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgs <mgs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:38:27 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/20 14:01:16 by mgs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

void	*philosophers_handler(void *philo)
{
	t_philosofer	*ph;

	ph = (t_philosofer *) philo;
	while (!(ph->table->someonedied))
	{
		eating(ph->table, ph);
		sleeping(ph->table, ph);
		thinking(ph->table, ph);
		if (ph->table->time_to_die < time_now(ph->table) - ph->last_meal || \
			ph->table->how_many_eats == ph->table->philos_num)
		{
			ph->table->someonedied = true;
			ph->is_dead = 1;
			behaviour(time_now(ph->table), ph->philo_id, "died", ph->table);
			return (NULL);
		}
	}
	return (ph->table);
}
