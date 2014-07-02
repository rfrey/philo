/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 19:13:12 by gbersac           #+#    #+#             */
/*   Updated: 2014/05/10 17:36:55 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "libft.h"

static t_point2d	*get_positions(void)
{
	static t_point2d	tab[7] =

	{{0, 1},
	{0.78, 0.62},
	{0.97, -0.22},
	{0.43, -0.9},
	{-0.44, -0.9},
	{-0.97, -0.23},
	{-0.78, 0.61}};
	return (tab);
}

void				display_description(t_window *win,
									t_phil *phil,
									int x_origin,
									int y_origin)
{
	char		*flag;
	char		*str;
	char		*nbr;
	int			color;

	flag = "";
	if (phil->state == EAT)
		flag = "Eat(";
	else if (phil->state == REST)
		flag = "Rest(";
	else if (phil->state == THINK)
		flag = "Think(";
	nbr = ft_itoa(phil->life);
	flag = ft_strcup(flag, nbr);
	str = ft_strcup(flag, ")");
	color = FONT_COLOR;
	if (phil->life <= MAX_LIFE / 5)
		color = 0XFF0000;
	else if (phil->life >= MAX_LIFE / 2)
		color = 0X00FF00;
	mlx_string_put(win->mlx, win->win, x_origin, y_origin,
			color, str);
	free(flag);
	free(nbr);
	free(str);
}

void				display_phils(t_env *env)
{
	int			i;
	int			x_origin;
	int			y_origin;
	t_point2d	*tab;

	i = 0;
	tab = get_positions();
	while (i < 7)
	{
		x_origin = tab[i].x * 100 + WIN_WIDTH / 2;
		y_origin = tab[i].y * 100 + WIN_HEIGHT / 2;
		display_description(env->win, env->phils[i], x_origin, y_origin);
		display_sticks(env->win, env->phils[i], x_origin, y_origin);
		++i;
	}
}

void				display(t_env *env)
{
	char			*str;
	char			*nbr;
	static time_t	last_refresh = 0;
	static time_t	start = 0;
	time_t			now;

	if (env->end == 1)
		my_exit(env);
	if (env->end)
		return ;
	time(&now);
	if (start == 0)
		start = time(&last_refresh);
	mlx_clear_window(env->win->mlx, env->win->win);
	if (!env->end && now - last_refresh)
	{
		state(env, &now, &start);
		last_refresh = now;
	}
	nbr = ft_itoa((int)(TIMEOUT - (now - start)));
	str = ft_strcup("REMAINING TIME :", nbr);
	free(nbr);
	mlx_string_put(env->win->mlx, env->win->win, 10, 15, FONT_COLOR, str);
	free(str);
	display_phils(env);
}
