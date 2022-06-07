/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:24:18 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/07 11:26:44 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/headers/philosophers.h"

int	main(int c, char **v)
{
	t_table	*table;

	if (!manage_inputs(c, v))
		return (0);
	table = malloc(sizeof(t_table *));
	if (!table)
		return (0);
	init_app(&table, c, v);
	return (0);
}
