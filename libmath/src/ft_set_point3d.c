/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_point3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 00:17:43 by gbersac           #+#    #+#             */
/*   Updated: 2013/12/19 21:09:56 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

void		ft_set_point3d(t_point3d *pt, double x, double y, double z)
{
	pt->x = x;
	pt->y = y;
	pt->z = z;
}
