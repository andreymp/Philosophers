/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:54:07 by jobject           #+#    #+#             */
/*   Updated: 2021/11/26 20:18:16 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000) + (tp.tv_usec / 1000));
}

long	get_time(t_filo	*filo)
{
	return (get_current_time() - filo->time);
}

void	ft_usleep(long time)
{
	long	beg;

	beg = get_current_time();
	while (get_current_time() - beg < time)
		usleep(time / 10);
}
