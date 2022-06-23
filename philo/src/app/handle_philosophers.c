/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:38:27 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/23 16:06:30 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

static void	est(t_philosofer *ph)
{
	eating(ph->table, ph);
	sleeping(ph->table, ph);
	thinking(ph->table, ph);
}

static void	tes(t_philosofer *ph)
{
	thinking(ph->table, ph);
	eating(ph->table, ph);
	sleeping(ph->table, ph);
}

void	*philosophers_handler(void *philo)
{
	t_philosofer	*ph;

	ph = (t_philosofer *) philo;
	while (!(ph->table->someonedied))
	{
		if (ph->philo_id % 2)
			est(ph);
		else
			tes(ph);
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
