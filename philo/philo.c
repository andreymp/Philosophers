/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:41:03 by jobject           #+#    #+#             */
/*   Updated: 2021/11/25 20:03:51 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_if_alive(t_filo	*philo, t_game	*game)
{
	int		i;

	while (philo->args->num_eat > 0 || philo->args->num_eat == -1)
	{
		i = 0;
		while (i < philo->args->number && !philo->dead)
		{
			if (get_current_time() - game[i].filo->update_time > philo->args->death)
			{
				print(philo, game + i, DIE);
				philo->dead = true;
			}
			i++;
			usleep(100);
		}
		if (i < philo->args->number)
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
		usleep(15000);
	while (!philo->dead)
	{
		pthread_mutex_lock(&philo->forks[game->right]);
		print(philo, game, FORK);
		pthread_mutex_lock(&philo->forks[game->left]);
		print(philo, game, FORK);
		print(philo, game, EAT);
		usleep(philo->args->eat * 1000);
		philo->update_time = get_current_time();
		pthread_mutex_unlock(&philo->forks[game->left]);
		pthread_mutex_unlock(&philo->forks[game->right]);
		if (!philo->args->num_eat)
			break ;
		print(philo, game, SLEEP);
		usleep(philo->args->sleep * 1000);
		print(philo, game, THINK);
	}
	return(NULL);
}