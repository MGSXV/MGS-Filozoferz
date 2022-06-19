/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:26:47 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/19 21:19:26 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H
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

// App functions
bool			manage_inputs(int c, char **inputs);
bool			create_threads(t_table *table);
bool			join_threads(t_table *table);
bool			init_mutexes(t_table **table);
bool			destroy_mutexes(t_table **table);
void			*philosophers_handler(void *philo);
long			timestamp_in_ms(void);
long			time_now(t_table *table);
void			behaviour(long time, int philo_id, char *action, t_table *table);
void			eating(t_table *table, t_philosofer *ph);
void			sleeping(t_table *table, t_philosofer *ph);
void			thinking(t_table *table, t_philosofer *ph);

// Init functions
bool			init_app(t_table **table, int c, char **v);
bool			init_philosophers(t_table *table);

#endif