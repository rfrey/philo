/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v2d_vunit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 20:34:47 by gbersac           #+#    #+#             */
/*   Updated: 2014/05/10 18:14:51 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vector2d	ft_v2d_vunit(t_vector2d *v)
{
	double	length;

	length = ft_v2d_length(v);
	if (0 < length)
		return (ft_v2d_divide(v, length));
	return (*v);
}
