/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   FdF.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 13:35:57 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/13 17:13:13 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./GNL/get_next_line.h"
# include "minilibx_macOS/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct        s_lst
{
    struct s_lst    *next;
    char            *s;
}                    t_lst;

typedef struct      s_env
{
    struct s_env   *next;
    void            *ptr;
    void            *win;
    int             num;
    int             co_x;
    int             co_y;
}                   t_env;

int                 check(t_lst *list);

#endif