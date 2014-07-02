/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 20:42:40 by gbersac           #+#    #+#             */
/*   Updated: 2014/05/10 17:48:26 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

static double	pow_positiv(double nb, int base)
{
	int		i;
	double	to_return;

	i = 0;
	to_return = 1;
	while (i < base)
	{
		to_return *= nb;
		++i;
	}
	return (to_return);
}

double			ft_pow(double nb, int base)
{
	if (base == 0)
		return (1);
	if (base > 0)
		return (pow_positiv(nb, base));
	return (1 / pow_positiv(nb, -base));
}
