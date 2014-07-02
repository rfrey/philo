/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 17:27:54 by rfrey             #+#    #+#             */
/*   Updated: 2014/05/10 17:34:20 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	phil_life(t_phil **phils)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		--(phils[i]->life);
		if (phils[i]->life == 0)
			return (i + 1);
		++i;
	}
	return (0);
}

static int	life_loss(t_env *env)
{
	int	n;

	if ((n = phil_life(env->phils)))
	{
		mlx_string_put(env->win->mlx, env->win->win, 500, 150,
			FONT_COLOR, "One philosoph died :'(");
		env->end = 1;
		return (n);
	}
	return (0);
}

static int	time_count(t_env *env, time_t *now, time_t *start)
{
	if (*now - *start >= TIMEOUT)
	{
		mlx_string_put(env->win->mlx, env->win->win, 500 - 50, 100,
			FONT_COLOR, "Now, it is time... To DAAAAAAAANCE!!!");
		env->end = 1;
		return (1);
	}
	return (0);
}

void		state(t_env *env, time_t *now, time_t *start)
{
	time_count(env, now, start);
	life_loss(env);
}
