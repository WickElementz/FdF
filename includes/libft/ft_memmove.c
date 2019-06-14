/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 09:41:14 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 16:58:30 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*strsrc;
	unsigned char	*strdest;

	strsrc = (unsigned char *)src;
	strdest = (unsigned char *)dest;
	if (strsrc < strdest)
	{
		strsrc = strsrc + n - 1;
		strdest = strdest + n - 1;
		while (n > 0)
		{
			*strdest-- = *strsrc--;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			*strdest++ = *strsrc++;
			n--;
		}
	}
	return (dest);
}
