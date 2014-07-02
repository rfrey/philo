/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 00:54:33 by gbersac           #+#    #+#             */
/*   Updated: 2014/05/10 19:12:05 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw.h"

static int		calc_steep(t_pixel *px0, t_pixel *px1)
{
	return (ft_abs(px1->y - px0->y) > ft_abs(px1->x - px0->x));
}

static void		init_il(t_info_loop *il)
{
	il->steep = calc_steep(il->px0, il->px1);
	if (il->steep)
	{
		ft_set_point2d(il->px0, il->px0->y, il->px0->x);
		ft_set_point2d(il->px1, il->px1->y, il->px1->x);
	}
	il->deltax = ft_abs(il->px1->x - il->px0->x);
	il->deltay = ft_abs(il->px1->y - il->px0->y);
	il->y = il->px0->y;
	il->x = il->px0->x;
	il->error = il->deltax / 2;
	if (il->px0->x < il->px1->x)
		il->inc = 1;
	else
		il->inc = -1;
}

static void		print_loop(t_window *win, t_info_loop *il, int color)
{
	if (il->px0->y < il->px1->y)
		il->ystep = 1;
	else
		il->ystep = -1;
	while (il->x != il->px1->x)
	{
		if (il->steep)
		{
			ft_putpx(win, il->y, il->x, color);
		}
		else
		{
			ft_putpx(win, il->x, il->y, color);
		}
		il->error -= il->deltay;
		if (il->error < 0)
		{
			il->y += il->ystep;
			il->error += il->deltax;
		}
		il->x += il->inc;
	}
}

void			ft_putline(t_window *win, t_pixel *beg, t_pixel *end, int color)
{
	t_info_loop	*il;

	il = (t_info_loop*)malloc(sizeof(t_info_loop));
	il->px0 = (t_pixel*)malloc(sizeof(t_pixel));
	il->px1 = (t_pixel*)malloc(sizeof(t_pixel));
	ft_set_point2d(il->px0, beg->x, beg->y);
	ft_set_point2d(il->px1, end->x, end->y);
	init_il(il);
	print_loop(win, il, color);
	ft_putpx(win, end->x, end->y, color);
	free(il->px0);
	free(il->px1);
	free(il);
}
