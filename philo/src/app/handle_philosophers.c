/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:38:27 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/18 04:56:48 by sel-kham         ###   ########.fr       */
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
			if (ph->table->eat_num != -1 && ph->num_times_eat == ph->table->eat_num)
				return (NULL);
		}
		else
			sleeping(ph->table, ph);
		if (!(ph->philo_id % 2))
		{
			eating(ph->table, ph);
			if (ph->table->eat_num != -1 && ph->num_times_eat == ph->table->eat_num)
				return (NULL);
		}
		else
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
