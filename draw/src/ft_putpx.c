/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 00:58:27 by gbersac           #+#    #+#             */
/*   Updated: 2013/12/16 22:14:55 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw.h"

int			ft_putpx(t_window *win, int x, int y, int color)
{
	int		ret;

	ret = mlx_pixel_put(win->mlx, win->win, x, y, color);
	return (ret);
}
