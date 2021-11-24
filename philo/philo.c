/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:41:03 by jobject           #+#    #+#             */
/*   Updated: 2021/11/24 21:36:44 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_if_alive(t_filo	*philo)
{
	int		i;
	t_game	*game;

	i = 0;
	game = philo->game;
	while (philo->args->num_eat > 0 || philo->args->num_eat == -1)
	{
		while (i < philo->args->number && !philo->dead)
		{
			if (get_current_time() - philo->update_time > philo->args->death)
			{
				print(philo, game + i, DIE);
				philo->dead = true;
			}
			usleep(100);
			i++;
		}
		if (philo->dead)
			break ;
		if (philo->args->num_eat != -1)
			philo->args->num_eat--;
	}
}

void	uninit(t_filo	*philo)
{
	int i;
	
	i = 0;
	while (i < philo->args->number)
		pthread_join(philo->game[i++].thread, NULL);
	i = 0;
	while (i < philo->args->number)
		pthread_mutex_destroy(&philo->forks[i++]);
	pthread_mutex_destroy(&philo->for_print);
}

void	*gaming(void	*philos)
{
	t_game	*game;
	t_filo	*philo;

	game = (t_game *) philos;
	philo = game->filo;
	if (game->id % 2)
		usleep(150000);
	while (!philo->dead)
	{
		print(philo, game, FORK);
		pthread_mutex_lock(&philo->forks[game->right]);
		pthread_mutex_lock(&philo->forks[game->left]);
		print(philo, game, EAT);
		usleep(philo->args->eat);
		pthread_mutex_unlock(&philo->forks[game->left]);
		pthread_mutex_unlock(&philo->forks[game->right]);
		if (!philo->args->num_eat)
			break ;
		print(philo, game, SLEEP);
		usleep(philo->args->sleep);
		print(philo, game, THINK);
	}
	return(NULL);
}