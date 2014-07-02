/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 23:39:01 by gbersac           #+#    #+#             */
/*   Updated: 2014/05/10 18:28:26 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_point2d
{
	double	x;
	double	y;
}					t_point2d;

typedef struct		s_point3d
{
	double	x;
	double	y;
	double	z;
}					t_point3d;

typedef t_point2d	t_vector2d;
typedef t_point3d	t_vector3d;

int					ft_abs(int n);
double				ft_pow(double nb, int base);
double				ft_sqrt(double x);

t_point2d			ft_create_point2d(double x, double y);
void				ft_set_point2d(t_point2d *pt, double x, double y);

t_point3d			ft_create_point3d(double x, double y, double z);
void				ft_set_point3d(t_point3d *pt, double x, double y, double z);

t_point2d			ft_plan_o_proj(t_point3d *pt, t_vector3d *direction);

void				ft_pt_to_px(t_point2d *pt);

double				ft_v2d_length(t_vector2d *pt);
double				ft_v3d_length(t_vector3d *pt);

t_vector2d			ft_v2d_divide(t_vector2d *pt, double d);
t_vector3d			ft_v3d_divide(t_vector3d *pt, double d);

t_vector2d			ft_v2d_multiply(t_vector2d *pt, double d);

t_vector2d			ft_v2d_vunit(t_vector2d *d);
t_vector3d			ft_v3d_vunit(t_vector3d *d);

#endif
