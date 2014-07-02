/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_point3d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 00:17:43 by gbersac           #+#    #+#             */
/*   Updated: 2013/12/19 21:17:21 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_point3d		ft_create_point3d(double x, double y, double z)
{
	t_point3d	to_return;

	to_return.x = x;
	to_return.y = y;
	to_return.z = z;
	return (to_return);
}
