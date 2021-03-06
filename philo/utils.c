/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:41:25 by jobject           #+#    #+#             */
/*   Updated: 2021/11/26 20:42:20 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int code)
{
	if (code >= '0' && code <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char	*nptr)
{
	char	*str;
	int		i;
	int		sign;
	int		res;

	str = (char *) nptr;
	i = 0;
	res = 0;
	sign = 1;
	while (str + i && (*(str + i) == '\n' || *(str + i) == '\t'
			|| *(str + i) == '\v' || *(str + i) == '\f' || *(str + i) == '\r'
			|| *(str + i) == ' '))
		i++;
	if (*(str + i) == '-')
		sign *= -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		res = res * 10 + (*(str + i) - 48);
		i++;
	}
	return (res * sign);
}

void	print(t_filo	*philo, t_game	*game, char	*str)
{
	if (!philo->dead)
	{
		pthread_mutex_lock(&philo->for_print);
		printf(str, get_time(philo), game->id + 1);
		pthread_mutex_unlock(&philo->for_print);
	}
}

void	skip(int n)
{
	if (n % 2)
		usleep(150);
}
