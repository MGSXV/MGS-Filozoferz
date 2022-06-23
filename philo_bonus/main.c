/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:01:35 by mgs               #+#    #+#             */
/*   Updated: 2022/06/24 00:45:07 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/headers/philosophers_bonus.h"

void	hold_main(t_table *table, pid_t *pids)
{
	int	i;

	i = -1;
	if (table->eat_num == -1)
	{
		sem_wait(table->sem_death);
		sem_wait(table->sem_death);
		while (++i < table->philos_num)
			kill(pids[i], SIGINT);
	}
	else if (table->eat_num)
	{
		while (++i < table->philos_num)
			waitpid(pids[i], 0, 0);
	}
}

static void	forking(t_table *table, pid_t *pids)
{
	int		i;

	i = -1;
	while (++i < table->philos_num)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			exit(EXIT_FAILURE);
		if (pids[i] == 0)
		{
			routing(table, i);
			exit(EXIT_SUCCESS);
		}
	}
}

int	main(int c, char **v)
{
	t_table	*table;
	pid_t	*pids;

	if (!manage_inputs(c, v))
		return (2);
	table = malloc(sizeof(t_table));
	if (!table)
		return (2);
	pids = malloc(sizeof(pid_t) * table->philos_num);
	if (!pids)
		return (2);
	if (!init_app(&table, c, v))
		return (2);
	init_sem(&table);
	forking(table, pids);
	hold_main(table, pids);
	return (0);
}
