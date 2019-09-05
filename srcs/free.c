/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/07 13:37:27 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 16:48:49 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Free notre liste chainée contenant notre fichier
*/

t_index		*free_index(t_index *index)
{
	if (index)
		free_index(index->next);
	if (index)
	{
		index->next = NULL;
		free(index);
	}
	return (NULL);
}

/*
** Free notre liste chainée contenant notre index du fichier
*/

t_env		*free_env(t_env *env)
{
	if (INDEX)
		free_index(INDEX);
	free(env);
	return (NULL);
}

/*
** Free notre variable d'environnement
*/

t_lst		*free_list(t_lst *list)
{
	if (list->next)
		free_list(list->next);
	if (list)
	{
		free(list->s);
		free(list);
	}
	return (NULL);
}
