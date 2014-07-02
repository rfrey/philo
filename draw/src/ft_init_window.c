/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 01:00:34 by gbersac           #+#    #+#             */
/*   Updated: 2014/05/10 17:41:34 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw.h"

t_window	*ft_init_window(int x, int y, char *title)
{
	t_window	*to_return;

	to_return = (t_window *)malloc(sizeof(t_window));
	to_return->mlx = mlx_init();
	to_return->win = mlx_new_image(to_return->mlx, x, y);
	to_return->win = mlx_new_window(to_return->mlx, x, y, title);
	return (to_return);
}
