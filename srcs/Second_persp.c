/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Second_persp.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/19 13:25:44 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/02 16:54:10 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/FdF.h"

/*
** Fonction traçant les droites horizontales / verticales
*/

void	choose_second_trace(t_env *env, t_index *p1, t_index *p2)
{
	int		s_x;
	int		s_y;

	s_x = (env->size_x / 2) - ((env->len_x - 1) * env->zoom / 2) + env->move_x;
	s_y = (env->size_y / 2) - ((env->len_y - 1) * env->zoom / 2) + env->move_y;
	env->x1 = s_x + (env->zoom * INDEX->x - p1->z);
	env->y1 = s_y + (env->zoom * INDEX->y - p1->z);
	if (INDEX->z == 0 && p2->z == 0)
		choose_bresenham(s_x + (env->zoom * p2->x),
							s_y + (env->zoom * p2->y), env);
	else if (INDEX->z != 0 && p2->z == 0)
		choose_bresenham(s_x + (env->zoom * p2->x),
							s_y + (env->zoom * p2->y), env);
	else if (INDEX->z == 0 && p2->z != 0)
		choose_bresenham(s_x + (env->zoom * p2->x) - p2->z,
							s_y + (env->zoom * p2->y) - p2->z, env);
	else
		choose_bresenham(s_x + (env->zoom * p2->x) - p2->z,
							s_y + (env->zoom * p2->y) - p2->z, env);
}

/*
** Fonction qui sert a decider si on trace des droites horizontales / verticales
*/

void	choose_second_seg(t_env *env)
{
	t_index *up;
	t_index *tmp;

	up = INDEX;
	tmp = INDEX;
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	while (INDEX->next)
	{
		if (INDEX->next && INDEX->x != env->len_x - 1)
			choose_second_trace(env, INDEX, INDEX->next);
		if (INDEX->next && INDEX->y != 0)
			choose_second_trace(env, INDEX, up);
		if (INDEX->y != 0)
			up = up->next;
		INDEX = INDEX->next;
	}
	INDEX = tmp;
}
