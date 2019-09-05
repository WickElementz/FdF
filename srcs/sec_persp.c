/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sec_persp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/19 13:25:44 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 16:34:23 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Fonction traçant les droites horizontales / verticales
*/

void	second_trace(t_env *env, t_index *p1, t_index *p2)
{
	int		s_x;
	int		s_y;

	s_x = (env->size_x / 2) - ((env->len_x - 1) * env->zoom / 2) + env->move_x;
	s_y = (env->size_y / 2) - ((env->len_y - 1) * env->zoom / 2) + env->move_y;
	env->x1 = (((p1->x + p1->y) * env->zoom) - p1->z * env->h) + s_x;
	env->y1 = (((p1->y - p1->x) * env->zoom) - p1->z * env->h) / 2 + s_y;
	env->color = color_z(p1->z, p2->z, env);
	if (p1->z == 0 && p2->z == 0)
		choose_bresenham(((p2->x + p2->y) * env->zoom) + s_x,
				((p2->y - p2->x) * env->zoom) / 2 + s_y, env);
	else if (p1->z == 0 && p2->z != 0)
		choose_bresenham((((p2->x + p2->y) * env->zoom)) + s_x,
			(((p2->y - p2->x) * env->zoom) - (p2->z * env->h)) / 2 + s_y, env);
	env->x1 = (((p1->x + p1->y) * env->zoom)) + s_x;
	if (p1->z != 0 && p2->z == 0)
		choose_bresenham((((p2->x + p2->y) * env->zoom)) + s_x,
			(((p2->y - p2->x) * env->zoom) - (p2->z * env->h)) / 2 + s_y, env);
	else
		choose_bresenham((((p2->x + p2->y) * env->zoom)) + s_x,
			(((p2->y - p2->x) * env->zoom) - (p2->z * env->h)) / 2 + s_y, env);
}

/*
** Fonction qui sert a decider si on trace des droites horizontales / verticales
*/

void	second_seg(t_env *env)
{
	t_index *up;
	t_index *tmp;

	up = INDEX;
	tmp = INDEX;
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 1, 1150, BLUE_LEG, LEGEND);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 1, 1170, BLUE_LEG, EXIT);
	if (env->leg == 1)
		print_legend(env);
	while (INDEX->next)
	{
		if (INDEX->next && INDEX->x != env->len_x - 1)
			second_trace(env, INDEX, INDEX->next);
		if (INDEX->next && INDEX->y != 0)
			second_trace(env, INDEX, up);
		if (INDEX->y != 0)
			up = up->next;
		INDEX = INDEX->next;
	}
	INDEX = tmp;
}
