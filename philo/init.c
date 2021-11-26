/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:59:05 by jobject           #+#    #+#             */
/*   Updated: 2021/11/26 19:46:22 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	*init_input(int argc, char	**argv)
{
	t_args	*params;

	params = (t_args *) malloc(sizeof(t_args));
	params->count = argc;
	params->number = ft_atoi(argv[1]);
	params->death = ft_atoi(argv[2]);
	params->eat = ft_atoi(argv[3]);
	params->sleep = ft_atoi(argv[4]);
	if (params->count == 6)
		params->num_eat = ft_atoi(argv[5]);
	else
		params->num_eat = -1;
	return (params);
}

static void	mutex_init(t_filo	*philo)
{
	int	i;

	i = 0;
	while (i < philo->args->number)
		pthread_mutex_init(&(philo->forks[i++]), NULL);
	pthread_mutex_init(&philo->for_print, NULL);
}

static void	init_philo(t_game	*game, int number)
{
	int	i;

	i = 0;
	while (i < number)
	{
		game[i].id = i;
		game[i].right = i;
		game[i].left = (i + 1) % number;
		i++;
	}
}

int	init_threads(t_filo	*filo)
{
	int		i;
	t_game	*game;

	i = 0;
	game = filo->game;
	mutex_init(filo);
	init_philo(game, filo->args->number);
	filo->dead = false;
	filo->time = get_current_time();
	while (i < filo->args->number)
	{	
		game[i].filo = filo;
		game[i].times_to_eat = 0;
		if (pthread_create(&game[i].thread, NULL, gaming, (void *) &game[i]))
			return (1);
		game[i].update_time = get_current_time();
		i++;
	}
	check_if_alive(game->filo, game);
	uninit(filo);
	return (0);
}
