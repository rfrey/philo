/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_point2d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 23:23:32 by gbersac           #+#    #+#             */
/*   Updated: 2013/12/19 21:16:45 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_point2d		ft_create_point2d(double x, double y)
{
	t_point2d	to_return;

	to_return.x = x;
	to_return.y = y;
	return (to_return);
}
