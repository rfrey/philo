/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 21:29:10 by gbersac           #+#    #+#             */
/*   Updated: 2014/05/10 17:49:38 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

static double	pow_10(size_t pw)
{
	return (ft_pow(10, pw));
}

static int		search_digit(double nb,
								double to_return,
								int puiss10,
								int *end)
{
	int		digit;
	double	interm_result;

	digit = 0;
	interm_result = nb - 1;
	while ((interm_result - nb) <= 0 && digit < 10)
	{
		++digit;
		interm_result = ft_pow(to_return + (digit * pow_10(puiss10)), 2);
		if (interm_result == nb)
		{
			*end = 1;
			return (digit);
		}
	}
	--digit;
	return (digit);
}

static void		init_puiss10(int *puiss10, double nb)
{
	(*puiss10) = 0;
	while (pow_10((*puiss10)) <= nb)
	{
		++(*puiss10);
	}
	--(*puiss10);
}

double			ft_sqrt(double nb)
{
	double	to_return;
	int		digit;
	int		puiss10;
	int		i;
	int		end;

	if (nb < 0)
		return (-1);
	init_puiss10(&puiss10, nb);
	to_return = 0;
	i = 0;
	end = 0;
	while (i < 16)
	{
		digit = search_digit(nb, to_return, puiss10, &end);
		if (end)
		{
			to_return += digit * pow_10(puiss10);
			return (to_return);
		}
		to_return += digit * pow_10(puiss10);
		--puiss10;
		++i;
	}
	return (to_return);
}
