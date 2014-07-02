/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v2d_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:22:52 by gbersac           #+#    #+#             */
/*   Updated: 2014/05/09 18:32:48 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vector2d	ft_v2d_multiply(t_vector2d *vector, double factor)
{
	t_vector2d	to_return;

	to_return.x = vector->x * factor;
	to_return.y = vector->y * factor;
	return (to_return);
}
