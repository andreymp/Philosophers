/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:36:13 by jobject           #+#    #+#             */
/*   Updated: 2021/11/23 18:31:51 by jobject          ###   ########.fr       */
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

# define FORK "%d %d has taken a fork\n"
# define EAT "%d %d  is eating\n"
# define SLEEP "%d %d  is sleeping\n"
# define THINK "%d %d  is thinking\n"
# define DIE "%d %d  is died\n"
# define MAX_THREADS 200

typedef pthread_mutex_t t_mutex;

typedef	struct s_args
{
	int	count;
	int	number;
	int	death;
	int	eat;
	int	sleep;
	int	num_eat;
}				t_args;

typedef struct s_philo
{
	t_args		*args;
	suseconds_t	time;
	pthread_t	thread[MAX_THREADS];
	t_mutex		mutex[MAX_THREADS];
}				t_filo;

int			ft_isdigit(int code);
int			ft_atoi(const char	*nptr);
suseconds_t	get_time(t_filo	*filo);
suseconds_t	get_current_time(void);
void		init_filo(t_filo	*filo);
void		*game(void	*filo);
t_args		*init_input(int argc, char	**argv);

#endif