/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 15:22:50 by rfrey             #+#    #+#             */
/*   Updated: 2014/05/10 19:21:04 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <ft_draw.h>

/*
** Standard macros.
*/
# define MAX_LIFE 12
# define EAT_T 3
# define REST_T 1
# define THINK_T 1
# define TIMEOUT 60

/*
** Window macros.
*/
# define WIN_NAME	"philosophe"
# define WIN_HEIGHT	1000
# define WIN_WIDTH	1000
# define FONT_COLOR	0xFFFFFF

typedef enum		e_state
{
	EAT,
	REST,
	THINK,
	DEAD
}					t_state;

typedef struct		s_phil
{
	unsigned int	n;
	unsigned int	life;
	t_state			state;
	pthread_mutex_t	*stick_left;
	pthread_mutex_t	*stick_right;
	struct s_phil	*phil_right;
	int				freeing_stick;
}					t_phil;

typedef struct		s_env
{
	pthread_t		**th;
	pthread_mutex_t	**mut;
	t_phil			**phils;
	t_window		*win;
	int				end;
}					t_env;

pthread_mutex_t		**init_mutex(void);
t_phil				**init_phils(pthread_mutex_t **mut);
pthread_t			**init_threads(t_phil **phils);
void				*ft_unlock(pthread_mutex_t *mutex);

void				my_exit(t_env *env);

void				*philo(void *data);

void				action_eat(t_phil *phil);
int					action_think(t_phil *phil);
void				action_rest(t_phil *phil);

int					key_hook(int key_code, t_env *env);
int					expose_hook(t_env *env);
void				display(t_env *env);
void				display_sticks(t_window *win,
						t_phil *phil,
						int x_origin,
						int y_origin);

void				state(t_env *env, time_t *now, time_t *start);

void				destroy_mutex(pthread_mutex_t **mut);
void				free_threads(pthread_t **th);
void				free_phils(t_phil **phils);
void				kill_phils(t_phil **phils, pthread_t **th);

#endif
