/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgs <mgs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:14:57 by mgs               #+#    #+#             */
/*   Updated: 2022/06/16 18:18:01 by mgs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

long	timestamp_in_ms()
{
	struct timeval	now;
	
	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000LL + now.tv_usec / 1000LL);
}