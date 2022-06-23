/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:36:55 by mgs               #+#    #+#             */
/*   Updated: 2022/06/23 16:27:08 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers_bonus.h"

void	ft_usleep(long ms)
{
	long	stamp;

	stamp = timestamp_in_ms();
	while (timestamp_in_ms() - stamp < ms)
		usleep(50);
}
