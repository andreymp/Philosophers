/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:41:03 by jobject           #+#    #+#             */
/*   Updated: 2021/11/26 20:41:18 by jobject          ###   ########.fr       */
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
			if ((get_current_time() - game[i].update_time) > philo->args->death)
			{
				print(philo, game + i, DIE);
				philo->dead = true;
			}
			i++;
			usleep(100);
		}
		if (philo->dead)
			break ;
		i = 0;
		while (i < philo->args->number
			&& game[i].times_to_eat >= philo->args->num_eat)
			i++;
		if (i == philo->args->number && philo->args->num_eat != -1)
			philo->args->num_eat = 0;
	}
}

void	uninit(t_filo	*philo)
{
	int	i;

	i = 0;
	while (i < philo->args->number)
		pthread_join(philo->game[i++].thread, NULL);
	i = 0;
	while (i < philo->args->number)
		pthread_mutex_destroy(&philo->forks[i++]);
	pthread_mutex_destroy(&philo->for_print);
}

static int	for_one(t_filo	*philo, t_game	*game)
{
	if (philo->args->number == 1)
	{
		pthread_mutex_unlock(&philo->forks[game->right]);
		return (1);
	}
	return (0);
}

static void	sleep_and_eat(t_game	*game, t_filo	*philo)
{
	print(philo, game, SLEEP);
	ft_usleep(philo->args->sleep);
	print(philo, game, THINK);
}

void	*gaming(void	*philos)
{
	t_game	*game;
	t_filo	*philo;

	game = (t_game *) philos;
	philo = game->filo;
	skip(game->id);
	while (!philo->dead)
	{
		pthread_mutex_lock(&philo->forks[game->right]);
		print(philo, game, FORK);
		if (for_one(philo, game))
			break ;
		pthread_mutex_lock(&philo->forks[game->left]);
		print(philo, game, FORK);
		print(philo, game, EAT);
		game->update_time = get_current_time();
		ft_usleep(philo->args->eat);
		pthread_mutex_unlock(&philo->forks[game->left]);
		pthread_mutex_unlock(&philo->forks[game->right]);
		game->times_to_eat++;
		if (!philo->args->num_eat)
			break ;
		sleep_and_eat(game, philo);
	}
	return (NULL);
}
