/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   file.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/19 13:25:44 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/27 16:35:21 by jominodi    ###    #+. /#+    ###.fr     */
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

void	choose_trace(t_env *env, t_index *index, t_index *up)
{
	int		start_x;
	int		start_y;

	start_x = (env->size_x / 2) - ((env->number_x - 1) * env->zoom / 2);
	start_y = (env->size_y / 2) - ((env->number_y - 1) * env->zoom / 2);
	env->x1 = start_x + (env->zoom * INDEX->co_x);
	env->y1 = start_y + (env->zoom * INDEX->co_y);
	if (INDEX->z == 0 && INDEX->next->z == 0)
	{
		dprintf(1, "x1: %d || y1: %d\nx2: %d || y2: %d\n\n", INDEX->co_x, INDEX->co_y, INDEX->next->co_x, up->co_y);
		check_bresenham(start_x + (env->zoom * INDEX->next->co_x), start_y + (env->zoom * up->co_y), env);
	}
//	else if (INDEX->z != 0 && INDEX->next->z == 0)
//	else if (INDEX->z == 0 && INDEX->next->z != 0)
//	else if (INDEX->z != 0 && INDEX->next->z != 0)
}

void	trace(t_env *env)
{

	t_env	*tmp;
	t_index *up;

	up = INDEX;
	tmp = env;
	while (INDEX->next)
	{

		if (INDEX->next && INDEX->co_x != env->number_x - 1)
			choose_trace(env, INDEX, INDEX->next);
	 	if (INDEX->next && INDEX->co_y != 0 && INDEX->co_y == INDEX->next->co_y)
		{
			choose_trace(env, INDEX, up);
		}
		if (INDEX->co_y != 0)
		up = up->next;
		INDEX = INDEX->next;
	}
	env = tmp; 
}