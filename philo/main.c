/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:36:15 by jobject           #+#    #+#             */
/*   Updated: 2021/11/26 21:09:20 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check(int argc,	char	**argv)
{
	int	i;
	int	j;

	if (argc != 5 && argc != 6)
		return (0);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			if (!ft_isdigit(argv[i][j++]))
				return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char	**argv)
{
	t_filo	filo;

	if (!check(argc, argv) || *argv[1] == '0')
	{
		printf("ERROR: Invalid arguments\n");
		return (1);
	}
	filo.args = init_input(argc, argv);
	if (init_threads(&filo))
		return (1);
	free(filo.args);
	return (0);
}
