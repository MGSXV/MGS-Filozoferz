/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgs <mgs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:38:27 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/19 17:08:46 by mgs              ###   ########.fr       */
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
		if (ph->table->time_to_die < timestamp_in_ms() - ph->last_meal)
		{
			ph->table->someonedied = true;
			behaviour("died", time_now(ph->table), ph->philo_id);
			return (NULL);
		}
	}
	return (ph->table);
}
