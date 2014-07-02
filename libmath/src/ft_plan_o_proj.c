/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plan_o_proj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 00:17:43 by gbersac           #+#    #+#             */
/*   Updated: 2014/05/10 17:47:33 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_point2d			ft_plan_o_proj(t_point3d *pt, t_vector3d *direction)
{
	double		k;
	t_point2d	to_return;

	if (pt->z == 0)
	{
		ft_set_point2d(&to_return, pt->x, pt->y);
		ft_pt_to_px(&to_return);
		return (to_return);
	}
	k = -(pt->z / direction->z);
	to_return.x = (int)((k * direction->x) + pt->x);
	to_return.y = (int)((k * direction->y) + pt->y);
	ft_pt_to_px(&to_return);
	return (to_return);
}
