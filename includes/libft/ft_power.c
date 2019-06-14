/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_power.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 14:16:37 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 09:51:35 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

int		ft_power(int nb, int exp)
{
	int	res;

	if (exp == 0)
		return (1);
	res = ft_power(nb, exp / 2);
	if (exp % 2 == 0)
		return (res * res);
	else
	{
		if (exp > 0)
			return (nb * res * res);
		else
			return (res * res) / nb;
	}
}
