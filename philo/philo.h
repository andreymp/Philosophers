/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:36:13 by jobject           #+#    #+#             */
/*   Updated: 2021/11/24 20:42:09 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdbool.h>
 
# define FORK "%d %d has taken a fork\n"
# define EAT "%d %d  is eating\n"
# define SLEEP "%d %d  is sleeping\n"
# define THINK "%d %d  is thinking\n"
# define DIE "%d %d  is died\n"

# define MAX_THREADS 200

typedef pthread_mutex_t t_mutex;

struct	s_filo;

typedef	struct s_args
{
	int		count;
	int		number;
	int		death;
	int		eat;
	int		sleep;
	int		num_eat;
}				t_args;

typedef struct	s_game
{
	int				id;
	unsigned int	left;
	unsigned int	right;
	struct s_filo	*filo;
	pthread_t		thread;
}				t_game;

typedef struct s_filo
{
	t_args		*args;
	t_game		game[MAX_THREADS];
	suseconds_t	time;
	suseconds_t	update_time;
	t_mutex		forks[MAX_THREADS];
	t_mutex		for_print;
	bool		dead;
}				t_filo;

int			ft_isdigit(int code);
int			ft_atoi(const char	*nptr);
suseconds_t	get_time(t_filo	*filo);
suseconds_t	get_current_time(void);
void		init_filo(t_filo	*filo);
void		*gaming(void	*filo);
t_args		*init_input(int argc, char	**argv);
int			init_threads(t_filo	*filo);
void		check_if_alive(t_filo	*philo);
void		uninit(t_filo	*philo);
void		print(t_filo	*philo, t_game	*game, char	*str);

#endif