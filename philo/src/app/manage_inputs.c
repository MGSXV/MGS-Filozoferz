/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:52:03 by sel-kham          #+#    #+#             */
/*   Updated: 2022/05/24 18:09:48 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

bool	ft_isnumber(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	manage_inputs(int c, char **inputs)
{
	int	i;

	i = 0;
	if (c == 2 && !ft_strncmp(inputs[1], "--help", ft_strlen("--help")))
	{
		printf("\"philosophers\" requires 4 to 5 arguments passed as fllows:\n\
$> ./philo arg1 arg2 arg3 arg4 arg5 ...\n\
All arguments should be positive intigers!\n");
		return (false);
	}
	if (c != 5 && c != 6)
	{
		printf("Invalid number of arguments!\n\
Try \"--help\" for more information.\n");
		return (false);
	}
	else
	{
		while (++i < c)
		{
			if (!ft_isnumber(inputs[i]))
			{
				printf("Arguments error!\nTry \"--help\" \
flag for more information.\n");
				return (false);
			}
		}
	}
	return (true);
}
