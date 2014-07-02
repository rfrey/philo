/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v2d_divide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 20:45:21 by gbersac           #+#    #+#             */
/*   Updated: 2014/05/10 17:50:20 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vector2d	ft_v2d_divide(t_vector2d *v, double divisor)
{
	t_vector2d	r;

	r.x = v->x / divisor;
	r.y = v->y / divisor;
	return (r);
}
