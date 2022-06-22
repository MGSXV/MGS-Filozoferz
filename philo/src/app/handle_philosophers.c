/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgs <mgs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:38:27 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/22 17:29:57 by mgs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

void	*philosophers_handler(void *philo)
{
	t_philosofer	*ph;

	ph = (t_philosofer *) philo;
	while (!(ph->table->someonedied))
	{
		if (ph->philo_id % 2)
		{
			eating(ph->table, ph);
			sleeping(ph->table, ph);
			thinking(ph->table, ph);
		}
		else
		{
			thinking(ph->table, ph);
			eating(ph->table, ph);
			sleeping(ph->table, ph);
		}
		if (ph->table->time_to_die < time_now(ph->table) - ph->last_meal)
		{
			ph->table->someonedied = true;
			return (NULL);
		}
		if (ph->table->how_many_eats == ph->table->philos_num)
			return (NULL);
	}
	return (ph->table);
}
