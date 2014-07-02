/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 15:17:38 by rfrey             #+#    #+#             */
/*   Updated: 2014/05/10 16:39:07 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_draw.h>
#include "libft.h"
#include "philo.h"

int				main(void)
{
	t_env			env;

	if (!((env.mut = init_mutex())))
	{
		ft_putendl("Error when initializing mutex.");
		return (1);
	}
	if (!((env.phils = init_phils(env.mut))))
	{
		ft_putendl("Error when initializing phils.");
		return (1);
	}
	if (!((env.th = init_threads(env.phils))))
	{
		ft_putendl("Error when initializing threads.");
		return (1);
	}
	env.end = 0;
	env.win = ft_init_window(WIN_HEIGHT, WIN_WIDTH, WIN_NAME);
	mlx_key_hook(env.win->win, key_hook, &env);
	mlx_expose_hook(env.win->win, expose_hook, &env);
	mlx_loop_hook(env.win->mlx, expose_hook, &env);
	mlx_loop(env.win->mlx);
	return (0);
}
