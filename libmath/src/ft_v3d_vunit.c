/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v3d_vunit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 20:34:47 by gbersac           #+#    #+#             */
/*   Updated: 2014/05/10 18:15:40 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vector3d	ft_v3d_vunit(t_vector3d *v)
{
	double length;

	length = ft_v3d_length(v);
	if (0 < length)
		return (ft_v3d_divide(v, length));
	return (*v);
}
