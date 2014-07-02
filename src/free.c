/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 16:56:31 by rfrey             #+#    #+#             */
/*   Updated: 2014/05/10 17:15:02 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "philo.h"
#include "libft.h"

void		destroy_mutex(pthread_mutex_t **mut)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		pthread_mutex_destroy(mut[i]);
		free(mut[i]);
		++i;
	}
	free(mut);
}

void		free_threads(pthread_t **th)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		free(th[i]);
		++i;
	}
	free(th);
}

void		free_phils(t_phil **phils)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		free(phils[i]);
		++i;
	}
	free(phils);
}

void		kill_phils(t_phil **phils, pthread_t **th)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		phils[i]->life = 0;
		++i;
	}
	i = 0;
	while (i < 7)
	{
		pthread_join(*(th[i]), NULL);
		++i;
	}
	++th;
}

void		my_exit(t_env *env)
{
	ft_putstr("Kill threads. Plesse wait... ");
	kill_phils(env->phils, env->th);
	ft_putendl("Done !");
	ft_putendl("Press ESC to quit.");
	env->end = -1;
}
