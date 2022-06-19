/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgs <mgs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:24:18 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/19 17:25:53 by mgs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/headers/philosophers.h"

void	print_philo(t_table *table)
{
	t_philosofer	*tmp;
	int				i;

	i = -1;
	tmp = table->head;
	printf("***********************************\n");
	printf("philos_num: %d\n", table->philos_num);
	printf("eat_num: %d\n", table->eat_num);
	printf("time_to_die: %d\n", table->time_to_die);
	printf("time_to_eat: %d\n", table->time_to_eat);
	printf("time_to_sleep: %d\n", table->time_to_sleep);
	while (++i < table->philos_num)
	{
		printf("Philosopher ID: %d\n", tmp->philo_id);
		tmp = tmp->next_philo;
	}
}

int	main(int c, char **v)
{
	t_table			*table;

	if (!manage_inputs(c, v))
		return (2);
	table = malloc(sizeof(t_table));
	if (!table)
		return (2);
	init_app(&table, c, v);
	if (!init_philosophers(table))
		return (2);
	if (!init_mutexes(&table))
		return (2);
	if (!create_threads(table))
		return (2);
	if (!join_threads(table))
		return (2);
	if (!destroy_mutexes(&table))
		return (2);
	return (0);
}
