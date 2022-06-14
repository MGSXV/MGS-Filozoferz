/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:29:02 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/14 01:46:56 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

void	ft_error(char *err_msg)
{
	printf("%s", err_msg);
}

void	free_all(t_table **table)
{
	t_philosofer	*tmp;
	int				i;

	if (table && *table)
	{
		if ((*table)->head)
		{
			i = -1;
			tmp = (*table)->head;
			while (++i < (*table)->philos_num)
			{
				printf("%p\n", tmp);
				(*table)->head = (*table)->head->next_philo;
				free(tmp);
				tmp = (*table)->head;
			}
			// free((*table)->head);
		}
		free(*table);
	}
}