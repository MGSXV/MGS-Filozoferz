/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgs <mgs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:27:37 by mgs               #+#    #+#             */
/*   Updated: 2022/06/19 17:29:47 by mgs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

int	min_number(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	max_number(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}
