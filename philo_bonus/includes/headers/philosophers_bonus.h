/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgs <mgs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:01:50 by mgs               #+#    #+#             */
/*   Updated: 2022/06/23 00:04:21 by mgs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H

# define PHILOSOPHERS_BONUS_H

# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>
# include<pthread.h>
# include<unistd.h>
# include<sys/time.h>

# include "types.h"

// Helpers functions
int				ft_strncmp(char *s1, char *s2, size_t n);
int				ft_isdigit(int c);
int				ft_strlen(char *s);
int				ft_atoi(const char *str);
bool			ft_isnumber(char *str);
int				min_number(int a, int b);
int				max_number(int a, int b);
t_philosofer	*ft_new_node(int id);
void			*ft_add_node(t_table **table, t_philosofer *node);
void			free_all(t_table **table);
void			ft_usleep(long ms);

#endif