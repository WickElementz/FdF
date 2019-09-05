/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/05 16:42:26 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 17:54:37 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Fichier pour les messages d'erreurs
*/

void	err_arg(void)
{
	ft_putstr("usage: ./fdf input_file\n");
	exit(1);
}

void	err_invalid_file(t_lst *lst, t_env *env)
{
	ft_putstr("Invalid file\n");
	free_list(lst);
	free_env(env);
	exit(1);
}

void	err_open(void)
{
	ft_putstr("this file doesn't exist\n");
	exit(1);
}

void	err_read(void)
{
	ft_putstr("this file / folder can't be read\n");
	exit(1);
}
