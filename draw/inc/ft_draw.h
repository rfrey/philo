/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 00:55:41 by gbersac           #+#    #+#             */
/*   Updated: 2014/05/10 19:12:58 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DRAW_H
# define FT_DRAW_H

# include <stdlib.h>
# include <ft_math.h>
# include <mlx.h>

# define K_ESC	65307

typedef t_point2d	t_pixel;

typedef struct	s_window
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_window;

typedef struct	s_info_loop
{
	int		deltax;
	int		deltay;
	int		y;
	int		x;
	int		error;
	int		steep;
	int		ystep;
	int		inc;
	t_pixel	*px0;
	t_pixel	*px1;
}				t_info_loop;

t_window		*ft_init_window(int x, int y, char *title);
int				ft_putpx(t_window *win, int x, int y, int color);
void			ft_putline(t_window *w, t_pixel *beg, t_pixel *end, int color);

#endif
