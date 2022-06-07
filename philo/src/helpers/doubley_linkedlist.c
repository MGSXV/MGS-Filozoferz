/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubley_linkedlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:10:27 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/07 11:26:52 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

t_philosofer	*ft_new_node(t_table **table)
{
	t_philosofer	*tmp_philo;

	tmp_philo = malloc(sizeof(t_philosofer *));
	if (!tmp_philo)
		return (NULL);
	tmp_philo->next_philo = NULL;
	tmp_philo->next_philo = NULL;
	tmp_philo->philo_id = -1;
	return (tmp_philo);
}
