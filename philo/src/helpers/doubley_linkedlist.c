/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubley_linkedlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:10:27 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/16 21:37:01 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

t_philosofer	*ft_new_node(int philo_id)
{
	t_philosofer	*tmp_philo;

	tmp_philo = malloc(sizeof(t_philosofer));
	if (!tmp_philo)
		return (NULL);
	tmp_philo->next_philo = NULL;
	tmp_philo->prev_philo = NULL;
	tmp_philo->philo_id = philo_id;
	return (tmp_philo);
}

void	ft_add_node(t_table **table, t_philosofer *node)
{
	t_philosofer	*tmp;

	tmp = NULL;
	if (!node)
		return ;
	if (!((*table)->head))
	{
		(*table)->head = node;
		(*table)->head->next_philo = (*table)->head;
		(*table)->head->prev_philo = (*table)->head;
		(*table)->head->table = (void *)(*table);
	}
	else
	{
		tmp = (*table)->head->prev_philo;
		(*table)->head->prev_philo = node;
		node->next_philo = (*table)->head;
		node->prev_philo = tmp;
		tmp->next_philo = node;
		node->table = (void *)(*table);
	}
}	
