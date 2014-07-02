/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 16:38:31 by rfrey             #+#    #+#             */
/*   Updated: 2014/05/08 17:33:54 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "philo.h"

static void		set_phil(t_phil **phils, pthread_mutex_t **mut, int i)
{
	phils[i]->n = i;
	phils[i]->life = MAX_LIFE;
	phils[i]->state = REST;
	phils[i]->stick_left = mut[i];
	phils[i]->freeing_stick = 0;
	if (i == 6)
		phils[i]->stick_right = mut[0];
	else
		phils[i]->stick_right = mut[i + 1];
	if (i == 6)
		phils[i]->phil_right = phils[0];
	else
		phils[i]->phil_right = phils[i + 1];
}

static t_phil	**get_phil_tab(void)
{
	t_phil	**tab;
	int		i;

	if (!((tab = (t_phil**)malloc(sizeof(t_phil*) * 7))))
		return (NULL);
	i = 0;
	while (i < 7)
	{
		if (!((tab[i] = (t_phil*)malloc(sizeof(t_phil)))))
			return (NULL);
		++i;
	}
	return (tab);
}

t_phil			**init_phils(pthread_mutex_t **mut)
{
	t_phil	**phils;
	int		i;

	if (!((phils = get_phil_tab())))
		return (NULL);
	i = 0;
	while (i < 7)
	{
		set_phil(phils, mut, i);
		++i;
	}
	return (phils);
}

pthread_mutex_t	**init_mutex(void)
{
	pthread_mutex_t	**mut;
	int				i;

	i = 0;
	if (!((mut = (pthread_mutex_t**)malloc(sizeof(pthread_mutex_t*) * 7))))
		return (NULL);
	while (i < 7)
	{
		if (!((mut[i] = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t)))))
			return (NULL);
		if (pthread_mutex_init(mut[i], NULL))
			return (NULL);
		++i;
	}
	return (mut);
}

pthread_t		**init_threads(t_phil **phils)
{
	pthread_t		**th;
	int				i;

	i = 0;
	if (!((th = (pthread_t**)malloc(sizeof(pthread_t*) * 7))))
		return (NULL);
	while (i < 7)
	{
		if (!((th[i] = (pthread_t*)malloc(sizeof(pthread_t)))))
			return (NULL);
		++i;
	}
	i = 0;
	while (i < 7)
	{
		if (pthread_create(th[i], NULL, philo, phils[i]))
			return (NULL);
		++i;
	}
	return (th);
}
