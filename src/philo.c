/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 21:50:28 by rfrey             #+#    #+#             */
/*   Updated: 2014/05/10 17:36:41 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include "libft.h"
#include "philo.h"

void	*ft_unlock(pthread_mutex_t *mutex)
{
	int	ret;

	ret = 0;
	ret = pthread_mutex_unlock(mutex);
	if (ret)
	{
		if (ret == EINVAL)
			ft_putendl("invalid mutex error");
		else if (ret == EPERM)
			ft_putendl("mutex is not hold by thread");
		else
			ft_putendl("unknow mutex error");
		return (NULL);
	}
	return (mutex);
}

void	*philo(void *data)
{
	t_phil			*phil;

	phil = (t_phil*)data;
	while (phil->life > 0)
	{
		action_rest(phil);
		while (pthread_mutex_trylock(phil->stick_left))
		{
			usleep(10000);
			if (phil->life == 0)
			{
				phil->state = DEAD;
				return (void*)(phil);
			}
		}
		if (action_think(phil))
			continue ;
		action_eat(phil);
		ft_unlock(phil->stick_left);
		ft_unlock(phil->stick_right);
	}
	phil->state = DEAD;
	return (void*)(phil);
}
