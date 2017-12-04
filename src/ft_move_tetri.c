/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move_tetri.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 15:39:46 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 17:53:23 by evella      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_mostleft(t_cord *tetri)
{
	int most_left;
	int i;

	i = 0;
	most_left = tetri[0].x;
	while (i < 4)
	{
		if (tetri[i].x < most_left)
			most_left = tetri[i].x;
		i++;
	}
	return (most_left);
}

int		ft_getsize(char **array)
{
	int size;

	size = 0;
	while (array[0][size])
		size++;
	return (size);
}

int		ft_tetri_down(t_cord *tetri, int sizemax)
{
	int down_max;
	int i;
	int down;

	down = 0;
	i = 0;
	down_max = 0;
	while (i < 4)
	{
		if (tetri[i].y + 1 > sizemax)
			down_max = 1;
		if (tetri[i++].x + 1 > sizemax)
			down = 1;
	}
	if (down == 1 && down_max == 1)
	{
		ft_leftup_tetri(tetri);
		return (2);
	}
	return (down);
}

int		ft_movetetri(t_cord *tetri, char **array)
{
	int i;
	int down;
	int most_left;
	int sizemax;

	sizemax = ft_getsize(array) - 1;
	i = 0;
	down = ft_tetri_down(tetri, sizemax);
	if (down == 2)
		return (0);
	most_left = ft_mostleft(tetri);
	i = 0;
	while (i < 4)
	{
		if (down == 1)
		{
			tetri[i].y += 1;
			tetri[i].x -= most_left;
		}
		else
			tetri[i].x += 1;
		i++;
	}
	return (1);
}
