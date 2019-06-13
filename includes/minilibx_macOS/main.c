/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 11:35:50 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 12:06:19 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int     deal_key(int key, void *param)
{
    ft_putchar('X');
    return (0);
}

int     main(void)
{
    void    *ptr;
    void    *win;

    ptr = mlx_init();
    win = mlx_new_window(ptr, 500, 500, "test");
    mlx_pixel_put(ptr, win, 250, 250, 0xFFFFFF);
    mlx_key_hook(win, deal_key, (void *)0);
    mlx_loop(ptr);
}