/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:59:05 by jobject           #+#    #+#             */
/*   Updated: 2021/11/23 20:20:26 by jobject          ###   ########.fr       */
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
		params->num_eat = 0;
	return (params);
}

void	init_threads(t_filo	*filo)
{
	int	i;

	i = 0;
	filo->time = get_current_time();
	while (i < filo->args->number)
		pthread_create(filo->thread[i++], NULL, game, (void *) filo);
	while (1)
	{
		// if (!char)
		// 	break ;
	}
}