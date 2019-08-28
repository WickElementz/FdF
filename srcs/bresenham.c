/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bresenham.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 15:06:36 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/28 16:46:45 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/FdF.h"

/*
** Bresenham pour la partie droite du tracé par rapport au point de départ
*/

void bresenham_1(int x2, int y2, t_env *env)
{
	int x;
	int y;
	int dx;
	int dy;

	x = env->x1;
	y = env->y1;
	dx = x2 - env->x1;
	dy = y2 - env->y1;
	env->e = 0.0;
	env->e1 = (float)dx / (float)dy;
	env->e2 = 1.0;
	while (y > y2)
	{
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, WHITE);
		env->e = env->e + env->e1;
		if (env->e < -0.5)
		{
			x++;
			env->e = env->e + env->e2;
		}
		y--;
	}
}

void bresenham_2(int x2, int y2, t_env *env)
{
	int x;
	int y;
	int dx;
	int dy;

	x = env->x1;
	y = env->y1;
	dx = x2 - env->x1;
	dy = y2 - env->y1;
	env->e = 0.0;
	env->e1 = (float)dy / (float)dx;
	env->e2 = 1.0;
	while (x < x2)
	{
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, BLUE);
		env->e = env->e + env->e1;
		if (env->e < -0.5)
		{
			y--;
			env->e = env->e + env->e2;
		}
		x++;
		;
	}
}

void bresenham_3(int x2, int y2, t_env *env)
{
	int x;
	int y;
	int dx;
	int dy;

	x = env->x1;
	y = env->y1;
	dx = x2 - env->x1;
	dy = y2 - env->y1;
	env->e = 0.0;
	env->e1 = (float)dy / (float)dx;
	env->e2 = -1.0;
	while (x < x2)
	{
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, ORANGE);
		env->e = env->e + env->e1;
		if (env->e > 0.5)
		{
			y++;
			env->e = env->e + env->e2;
		}
		x++;
	}
}

void bresenham_4(int x2, int y2, t_env *env)
{
	int x;
	int y;
	int dx;
	int dy;

	x = env->x1;
	y = env->y1;
	dx = x2 - env->x1;
	dy = y2 - env->y1;
	env->e = 0.0;
	env->e1 = (float)dx / (float)dy;
	env->e2 = -1.0;
	while (y < y2)
	{
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, GREEN);
		env->e = env->e + env->e1;
		if (env->e > 0.5)
		{
			x++;
			env->e = env->e + env->e2;
		}
		y++;
	}
}