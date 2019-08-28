/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   file.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/19 13:25:44 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/28 16:46:45 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/FdF.h"

void    find_zoom(t_env *env)
{
	if (env->number_x >= env->number_y)
		env->zoom = (env->size_x - 800) / (env->number_x - 1);
	else
		env->zoom = (env->size_y - 600) / (env->number_y - 1);
}

/*
** Fonction traçant les droites horizontales / verticales
*/

void	choose_trace(t_env *env, t_index *index, t_index *up)
{
	int		start_x;
	int		start_y;

	start_x = (env->size_x / 2) - ((env->number_x - 1) * env->zoom / 2);
	start_y = (env->size_y / 2) - ((env->number_y - 1) * env->zoom / 2);
	env->x1 = start_x + (env->zoom * INDEX->x - index->z);
	env->y1 = start_y + (env->zoom * INDEX->y - index->z);
	if (INDEX->z == 0 && up->z == 0)
		check_bresenham(start_x + (env->zoom * up->x), start_y + (env->zoom * up->y), env);
	else if (INDEX->z != 0 && up->z == 0)
		check_bresenham(start_x + (env->zoom * up->x), start_y + (env->zoom * up->y), env);
	else if (INDEX->z == 0 && up->z != 0)
		check_bresenham(start_x + (env->zoom * up->x) - up->z, start_y + (env->zoom * up->y) - up->z, env);
	else
		check_bresenham(start_x + (env->zoom * up->x) - up->z, start_y + (env->zoom * up->y) - up->z, env);
}

/*
** Fonction qui sert a decider si on trace des droites horizontales / verticales
*/

void	trace(t_env *env)
{

	t_env	*tmp;
	t_index *up;

	up = INDEX;
	tmp = env;
	while (INDEX->next)
	{

		if (INDEX->next && INDEX->x != env->number_x - 1)
			choose_trace(env, INDEX, INDEX->next);
	 	if (INDEX->next && INDEX->y != 0)
			choose_trace(env, INDEX, up);
		if (INDEX->y != 0)
			up = up->next;
		INDEX = INDEX->next;
	}
	env = tmp; 
}