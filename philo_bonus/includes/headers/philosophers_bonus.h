/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:01:50 by mgs               #+#    #+#             */
/*   Updated: 2022/06/23 23:29:24 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H

# define PHILOSOPHERS_BONUS_H

# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>
# include<pthread.h>
# include<unistd.h>
# include<semaphore.h>
# include<signal.h>
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
void			free_all(t_table **table);
void			ft_usleep(long ms);

// App functions
bool			manage_inputs(int c, char **inputs);
long			timestamp_in_ms(void);
long			time_now(t_table *table);
void			init_sem(t_table **table);
void			behaviour(long time, int philo_id, char *action, t_table *table);
void			eating(t_table *table);
void			sleeping(t_table *table);
void			thinking(t_table *table);
void			routing(t_table *table, int i);

// Init functions
bool			init_app(t_table **table, int c, char **v);

#endif