/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_event.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/02 13:31:04 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/02 18:33:57 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	move_map(int key, t_env *env)
{
	if (key == 13)
		env->move_y -= 10;
	if (key == 1)
		env->move_y += 10;
	if (key == 0)
		env->move_x -= 10;
	if (key == 2)
		env->move_x += 10;
}

void	reset_first_map(t_env *env)
{
	env->move_y = 0;
	env->move_x = 0;
	env->swc = 1;
	env->h = 0;
	find_zoom(env);
	choose_first_seg(env);
}

int		choose_color(int height, int swc)
{
	const unsigned int color_tab[12] = {
		RED_0, BLUE_0, YELLOW_0, GREEN_0,
		RED_1, BLUE_1, YELLOW_1, GREEN_1,
		RED_2, BLUE_2, YELLOW_2, GREEN_2
	};
	
	return (color_tab[height * 4 + swc - 1]);
}

int		color(int z1, int z2, t_env *env)
{
	if (z1 == 0 && z2 == 0)
		return (choose_color(0, env->swc));
	else if (z1 > 40 || z2 > 40 || z1 < -40 || z2 < -40)
		return (choose_color(2, env->swc));
	else
		return (choose_color(1, env->swc));
}
