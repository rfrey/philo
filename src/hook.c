/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 18:04:30 by gbersac           #+#    #+#             */
/*   Updated: 2014/05/10 17:29:53 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

int				expose_hook(t_env *env)
{
	display(env);
	usleep(40000);
	return (0);
}

int				key_hook(int key_code, t_env *env)
{
	if (key_code == K_ESC && env->end)
	{
		mlx_destroy_window(env->win->mlx, env->win->win);
		destroy_mutex(env->mut);
		free_threads(env->th);
		free_phils(env->phils);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
