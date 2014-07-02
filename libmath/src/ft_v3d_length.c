/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v3d_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 20:26:04 by gbersac           #+#    #+#             */
/*   Updated: 2014/05/10 18:15:11 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

double		ft_v3d_length(t_vector3d *v)
{
	return (ft_sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}