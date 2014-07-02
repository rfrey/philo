/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v3d_divide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 20:45:21 by gbersac           #+#    #+#             */
/*   Updated: 2013/12/19 20:59:45 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vector3d	ft_v3d_divide(t_vector3d *v, double divisor)
{
	t_vector3d r;

	r.x = (v->x / divisor);
	r.y = (v->y / divisor);
	r.z = (v->z / divisor);
	return (r);
}
