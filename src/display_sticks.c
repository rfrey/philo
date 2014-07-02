/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sticks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 15:43:50 by gbersac           #+#    #+#             */
/*   Updated: 2014/05/09 19:55:12 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void			stick_available(t_window *win, t_point2d *beg)
{
	t_point2d	end;

	end.x = beg->x + 15;
	end.y = beg->y + 15;
	ft_pt_to_px(&end);
	ft_putline(win, beg, &end, FONT_COLOR);
}

static void			stick_eat(t_window *win, t_point2d *beg)
{
	t_point2d	end;

	end.x = beg->x - 15;
	end.y = beg->y + 15;
	ft_pt_to_px(&end);
	ft_putline(win, beg, &end, FONT_COLOR);
	end.x = beg->x + 15;
	ft_pt_to_px(&end);
	ft_putline(win, beg, &end, FONT_COLOR);
}

static void			stick_think(t_window *win, t_point2d *beg)
{
	t_point2d	end;

	end.x = beg->x;
	end.y = beg->y + 15;
	ft_pt_to_px(&end);
	ft_putline(win, beg, &end, FONT_COLOR);
}

static int			is_stick_available(pthread_mutex_t *stick)
{
	if (!pthread_mutex_trylock(stick))
	{
		pthread_mutex_unlock(stick);
		return (1);
	}
	return (0);
}

void				display_sticks(t_window *win,
						t_phil *phil,
						int x_origin,
						int y_origin)
{
	int			available_left;
	t_point2d	begin_display;

	available_left = is_stick_available(phil->stick_left);
	ft_set_point2d(&begin_display, x_origin - 5, y_origin + 5);
	ft_pt_to_px(&begin_display);
	if (available_left)
		stick_available(win, &begin_display);
	else if (phil->state == EAT)
		stick_eat(win, &begin_display);
	else if (phil->state == THINK)
		stick_think(win, &begin_display);
}
