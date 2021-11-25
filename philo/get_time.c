/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:54:07 by jobject           #+#    #+#             */
/*   Updated: 2021/11/25 18:40:16 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_current_time(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000) + (tp.tv_usec / 1000));
}

long long	get_time(t_filo	*filo)
{
	return (get_current_time() - filo->time);
}

// void	ft_usleep(t_filo	*filo, long long time)
// {
// 	int time_cur;

// 	time_cur = get_current_time();
// 	while (!filo->dead)
// 	{
// 		if  (get_current_time() - time_cur >= time)
// 			break ;
// 		usleep(50);
// 	}
// }