/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:00:57 by sel-kham          #+#    #+#             */
/*   Updated: 2022/05/24 17:51:56 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

void	init_app(t_philosophers *ph, char **v, char c)
{
	if (c == 5)
	{
		ph->philos_num = ft_atoi(v[1]);
		ph->time_to_die = ft_atoi(v[2]);
		ph->time_to_eat = ft_atoi(v[3]);
		ph->time_to_sleep = ft_atoi(v[4]);
	}
	if (c == 6)
		ph->eat_num = ft_atoi(v[5]);
}
