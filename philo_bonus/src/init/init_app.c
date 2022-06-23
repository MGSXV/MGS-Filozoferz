/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:00:57 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/23 16:39:19 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers_bonus.h"

bool	init_app(t_table **table, int c, char **v)
{
	if (!ft_atoi(v[1]) || !ft_atoi(v[2]) || !ft_atoi(v[3]) || !ft_atoi(v[4]))
		return (false);
	(*table)->philos_num = ft_atoi(v[1]);
	(*table)->time_to_die = ft_atoi(v[2]);
	(*table)->time_to_eat = ft_atoi(v[3]);
	(*table)->time_to_sleep = ft_atoi(v[4]);
	if (c == 6)
	{
		if (!ft_atoi(v[5]))
			return (false);
		(*table)->eat_num = ft_atoi(v[5]);
	}
	else
		(*table)->eat_num = -1;
	// (*table)->head = NULL;
	(*table)->t0 = time_now(*table);
	(*table)->someonedied = false;
	(*table)->how_many_eats = 0;
	return (true);
}

bool	init_philosophers(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philos_num)
		if (!ft_add_node(&table, ft_new_node(i + 1)))
			return (false);
	return (true);
}
