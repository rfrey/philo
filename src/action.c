/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 18:42:19 by rfrey             #+#    #+#             */
/*   Updated: 2014/05/10 19:20:07 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include "philo.h"

void	action_eat(t_phil *phil)
{
	int	eat_t;

	eat_t = EAT_T;
	phil->state = EAT;
	usleep(eat_t * 1000000);
	if (phil->life)
		phil->life = MAX_LIFE;
}

void	action_rest(t_phil *phil)
{
	int	rest_t;

	rest_t = REST_T;
	phil->state = REST;
	usleep(rest_t * 1000000);
}

int		action_think(t_phil *phil)
{
	int				ret;
	time_t			start;
	time_t			now;

	time(&start);
	while ((ret = pthread_mutex_trylock(phil->stick_right)))
	{
		if (phil->life == 0)
			return (1);
		phil->state = THINK;
		if (phil->phil_right->state == THINK)
			phil->phil_right->freeing_stick = 1;
		else if (phil->freeing_stick)
		{
			phil->freeing_stick = 0;
			ft_unlock(phil->stick_left);
			return (0);
		}
	}
	while (time(&now) - start < THINK_T)
	{
	}
	return (ret);
}
