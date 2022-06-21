/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgs <mgs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:36:55 by mgs               #+#    #+#             */
/*   Updated: 2022/06/21 14:38:58 by mgs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

void	ft_usleep(long ms)
{
	long	stamp;

	stamp = timestamp_in_ms();
	while (timestamp_in_ms() - stamp < ms)
		usleep(50);
}