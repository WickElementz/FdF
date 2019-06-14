/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 11:22:58 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 15:17:15 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*strdest;
	unsigned char	*strsrc;

	strdest = (unsigned char *)dest;
	strsrc = (unsigned char *)src;
	while (n > 0 && *strsrc != (unsigned char)c)
	{
		*strdest = *strsrc;
		strdest++;
		strsrc++;
		n--;
	}
	if (n > 0)
	{
		*strdest = *strsrc;
		strdest++;
		strsrc++;
		return ((void *)strdest);
	}
	else
		return (NULL);
}
