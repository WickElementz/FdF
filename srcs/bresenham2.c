/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bresenham2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/18 15:44:26 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/27 16:35:23 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/FdF.h"

/*
** Bresenham pour la partie Gauche du tracé par rapport au point de départ
** Bresenham 5 = Blanc
** Bresenham 6 = Bleu
** Bresenham 7 = Orange
** Bresenham 8 = Vert
** Rajout de Bresenham_line qui permet de tracer les lignes droites 
** ( qui ne sont pas prises en compte par Bresenham)
** Bresenham Line = Vert Foncé
*/

void bresenham_5(int x2, int y2, t_env *env)
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
	while (y < y2)
	{
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, WHITE);
		env->e = env->e + env->e1;
		if (env->e < 0.5)
		{
			x--;
			env->e = env->e + env->e2;
		}
		y++;
	}
}

void bresenham_6(int x2, int y2, t_env *env)
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
	while (x > x2)
	{
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, BLUE);
		env->e = env->e + env->e1;
		if (env->e < 0.5)
		{
			y++;
			env->e = env->e + env->e2;
		}
		x--;
		;
	}
}

void bresenham_7(int x2, int y2, t_env *env)
{
	int x;
	int y;
	int dx;
	int dy;

	x = env->x1;
	y = env->y1;
	dy = y2 - env->y1;
	dx = x2 - env->x1;
	env->e = 0.0;
	env->e1 = (float)dy / (float)dx;
	env->e2 = -1.0;
	while (x > x2)
	{
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, ORANGE);
		env->e = env->e + env->e1;
		if (env->e > 0.5)
		{
			y--;
			env->e = env->e + env->e2;
		}
		x--;
	}
}

void bresenham_8(int x2, int y2, t_env *env)
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
	while (y > y2)
	{
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, GREEN);
		env->e = env->e + env->e1;
		if (env->e > 0.5)
		{
			x--;
			env->e = env->e + env->e2;
		}
		y--;
	}
}

void bresenham_line(int x2, int y2, t_env *env)
{
	int x;
	int y;

	x = env->x1;
	y = env->y1;
	if (y == y2)
	{
		while (x < x2)
			mlx_pixel_put(env->mlx_ptr, env->win_ptr, x++, y, DARKGREEN);
		while (x > x2)
			mlx_pixel_put(env->mlx_ptr, env->win_ptr, x--, y, DARKGREEN);
	}
	else if (x == x2)
	{
		while (y < y2)
			mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y++, DARKGREEN);
		while (y > y2)
			mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y--, DARKGREEN);
	}
}