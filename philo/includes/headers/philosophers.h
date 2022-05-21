/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:26:47 by sel-kham          #+#    #+#             */
/*   Updated: 2022/05/21 15:55:22 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

#include "../ft_printf/ft_printf.h"

// Helpers functions
int	ft_strncmp(const char *s1, const char *s2, size_t n);

// Managing inputs functions
bool	manage_inputs(int c, char **inputs);