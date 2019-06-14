/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sqrt.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 10:09:32 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 11:28:43 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

int		ft_sqrt(int nb)
{
	int		rac;
	int		sqrt;

	rac = 1;
	sqrt = 0;
	while (rac <= nb / 2)
	{
		sqrt = rac * rac;
		if (sqrt == nb)
			return (rac);
		rac = rac + 1;
	}
	return (0);
}
