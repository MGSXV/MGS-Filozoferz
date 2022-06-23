/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgs <mgs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:01:35 by mgs               #+#    #+#             */
/*   Updated: 2022/06/23 01:46:45 by mgs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/headers/philosophers_bonus.h"

int	main(int c, char **v)
{
	t_table	*table;

	if (!manage_inputs(c, v))
		return (2);
	table = malloc(sizeof(t_table));
	if (!table)
		return (2);
	if (!init_app(&table, c, v))
		return (2);
	if (!init_philosophers)
		return (2);
	free_all(&table);
	return (0);
}
