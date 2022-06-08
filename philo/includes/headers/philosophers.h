/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:26:47 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/08 19:55:35 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H
# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>
# include<pthread.h>

# include "types.h"

// Helpers functions
int				ft_strncmp(char *s1, char *s2, size_t n);
int				ft_isdigit(int c);
int				ft_strlen(char *s);
int				ft_atoi(const char *str);
bool			ft_isnumber(char *str);
t_philosofer	*ft_new_node(int id);
void			ft_add_node(t_table **table, t_philosofer *node);

// App functions
bool			manage_inputs(int c, char **inputs);
// Init functions
void			init_app(t_table **table, int c, char **v);
void			init_philosophers(t_table *table);

#endif