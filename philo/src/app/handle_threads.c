/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:36:59 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/13 22:41:26 by sel-kham         ###   ########.fr       */
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
		pthread_create(&(tmp->philosopher), NULL, philosophers_handler, (void *) table);
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
