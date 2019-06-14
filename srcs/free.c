/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/07 13:37:27 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/14 18:59:27 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/FdF.h"

void error(void)
{
    ft_putstr("error\n");
    exit(1);
}

t_index	*free_index(t_index	*index)
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

t_env	*free_env(t_env *env)
{
	if (INDEX)
		free_index(INDEX);
//	free(env->ptr);
//	free(env->win);	
	free(env);
	return (NULL);
}

t_lst	*free_list(t_lst *list)
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