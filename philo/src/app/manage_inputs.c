/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:52:03 by sel-kham          #+#    #+#             */
/*   Updated: 2022/05/21 16:03:13 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

bool	manage_inputs(int c, char **inputs)
{
	if (c == 2 && !ft_strncmp(inputs[1], "--help", ft_strlen("--help")))
	{
		ft_printf("\"philosophers\" requires 4 to 5 passed as fllows:\n\
$> ./philo arg1 arg2 arg3 arg4 arg5 ...\n");
		return (false);
	}
	if (c != 5 && c !=6)
	{
		ft_printf("Invalid number of arguments!\n\
Try \"--help\" for more information.\n");
		return (false);
	}
	else
	{
		
	}
	return (true);
}

