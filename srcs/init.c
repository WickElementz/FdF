/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 16:35:56 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/28 16:46:47 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/FdF.h"

/*
** Fichier servant à initialiser les listes chainées / structures contenu dans le FdF.h
*/

t_lst   *init_lst(void)
{
    t_lst   *lst;
    if (!(lst = (t_lst *)malloc(sizeof(t_lst))))
        return (NULL);
    lst->s = NULL;
    lst->next = NULL;
    return (lst);
}

t_index *init_index(void)
{
    t_index *index;

    if (!(index = (t_index *)malloc(sizeof(t_index))))
        return (NULL);
    index->z = 0;
    index->x = 0;
    index->y = 0;
    index->next = NULL;
    return (index);
}

t_env   *init_env(void)
{
    t_env   *env;

    if (!(env = malloc(sizeof(t_env))))
        return (NULL);
    env->x1 = 0;
	env->y1 = 0;
    env->number_x = 0;
    env->number_y = 0;
    env->size_x = 1800;
	env->size_y = 1200;
    INDEX = init_index();
    return (env);
}