/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:01:35 by mgs               #+#    #+#             */
/*   Updated: 2022/06/23 16:44:11 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/headers/philosophers_bonus.h"

void	routing(t_table *table, int i)
{
	
}

int	main(int c, char **v)
{
	t_table	*table;
	int		i;
	int		pid;

	if (!manage_inputs(c, v))
		return (2);
	table = malloc(sizeof(t_table));
	if (!table)
		return (2);
	if (!init_app(&table, c, v))
		return (2);
	i = -1;
	while (++i < table->philos_num)
	{
		pid = fork();
		if (pid = -1)
			exit(EXIT_FAILURE);
		if (!pid)
		{
			routing(table, i);
			exit(EXIT_SUCCESS);
		}
	}
	// if (!init_philosophers(table))
	// 	return (2);
	// free_all(&table);
	return (0);
}
