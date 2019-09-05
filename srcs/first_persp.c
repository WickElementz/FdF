/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   first_persp.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/19 13:25:44 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 17:57:56 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Calcule le zoom + le deplacement de la map a chaque appui sur une touche
*/

void	find_zoom(t_env *env)
{
	if (env->len_x >= env->len_y)
		env->zoom = (env->size_x / 2) / (env->len_x - 1);
	else
		env->zoom = (env->size_y / 2) / (env->len_y - 1);
}

/*
** Calcul de la modification du relief si z != 0
*/

void	value_h(t_env *env, int s_x, int s_y)
{
	env->x1 = s_x + (env->zoom * INDEX->x - (INDEX->z * env->h));
	env->y1 = s_y + (env->zoom * INDEX->y - (INDEX->z * env->h));
}

int		color_z(int z1, int z2, t_env *env)
{
	if (z1 == 0 && z2 == 0)
		return (color(z1, z2, env));
	else if (z1 != 0 && z2 == 0)
		return (color((z1 + env->h), z2, env));
	else if (z1 == 0 && z2 != 0)
		return (color(z1, (z2 + env->h), env));
	else
		return (color((z1 + env->h), (z2 + env->h), env));
}

/*
** Fonction traçant les droites horizontales / verticales
*/

void	first_trace(t_env *env, t_index *p1, t_index *p2)
{
	int		s_x;
	int		s_y;

	s_x = (env->size_x / 2) - ((env->len_x - 1) * env->zoom / 2) + env->move_x;
	s_y = (env->size_y / 2) - ((env->len_y - 1) * env->zoom / 2) + env->move_y;
	env->x1 = s_x + (env->zoom * p1->x - (p1->z));
	env->y1 = s_y + (env->zoom * p1->y - (p1->z));
	if (p1->z != 0)
		value_h(env, s_x, s_y);
	env->color = color_z(p1->z, p2->z, env);
	if (p1->z == 0 && p2->z == 0)
		choose_bresenham(s_x + (env->zoom * p2->x),
							s_y + (env->zoom * p2->y), env);
	else if (p1->z != 0 && p2->z == 0)
		choose_bresenham(s_x + (env->zoom * p2->x),
							s_y + (env->zoom * p2->y), env);
	else if (p1->z == 0 && p2->z != 0)
		choose_bresenham(s_x + (env->zoom * p2->x) - (p2->z * env->h),
						s_y + (env->zoom * p2->y) - (p2->z * env->h), env);
	else
		choose_bresenham(s_x + (env->zoom * p2->x) - (p2->z * env->h),
						s_y + (env->zoom * p2->y) - (p2->z * env->h), env);
}

/*
** Fonction qui sert a decider si on trace des droites horizontales / verticales
*/

void	first_seg(t_env *env)
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
			first_trace(env, INDEX, INDEX->next);
		if (INDEX->next && INDEX->y != 0)
			first_trace(env, INDEX, up);
		if (INDEX->y != 0)
			up = up->next;
		INDEX = INDEX->next;
	}
	INDEX = tmp;
}
