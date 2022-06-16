/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgs <mgs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:36:59 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/16 18:34:09 by mgs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

void	create_threads(t_table *table)
{
	int				i;
	t_philosofer	*tmp;

	i = -1;
	tmp = table->head;
	while (++i < table->philos_num)
	{
		pthread_create(&(tmp->philosopher), NULL, philosophers_handler, (void *) tmp);
		tmp = tmp->next_philo;
	}
}

void	join_threads(t_table *table)
{
	int	i;
	t_philosofer	*tmp;

	i = -1;
	tmp = table->head;
	while (++i < table->philos_num)
	{
		pthread_join(tmp->philosopher, NULL);
		tmp = tmp->next_philo;
	}
}

// void	init_mutexes(t_table **table)
// {
	
// }
