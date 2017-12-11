/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_btking.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 17:16:47 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 18:42:38 by ythollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** On echappe a 131000 iteration pour escape avant d'ateindre le stack size.
** I know.
*/

int		ft_isfree(char **array, t_cord *tetri)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (!(array[tetri[i].y][tetri[i].x] == '.'))
			return (0);
		i++;
	}
	return (1);
}

void	ft_writearray(char **array, t_cord *tetri)
{
	int i;

	i = 0;
	while (i < 4)
	{
		array[tetri[i].y][tetri[i].x] = tetri[i].val;
		i++;
	}
}

void	ft_unwritearray(char **array, t_cord *tetri)
{
	int i;

	i = 0;
	while (i < 4)
	{
		array[tetri[i].y][tetri[i].x] = '.';
		i++;
	}
}

int		ft_btking(char **array, t_cord **tetri, int nbr_tetri, int count)
{
	if (tetri[0][0].i++ > 131000)
		tetri[0][0].i = 0;
	if (tetri[0][0].i == 0)
		return (0);
	if (count == nbr_tetri)
		return (1);
	while (ft_isfree(array, tetri[count]) == 0)
	{
		if (ft_movetetri(tetri[count], array) == 0)
		{
			ft_leftup_tetri(tetri[count]);
			ft_unwritearray(array, tetri[count - 1]);
			if (ft_movetetri(tetri[count - 1], array) == 0)
			{
				if (count - 2 == -1)
					return (0);
				ft_unwritearray(array, tetri[count - 2]);
				ft_movetetri(tetri[count - 2], array);
				return (ft_btking(array, tetri, nbr_tetri, (count - 2)));
			}
			return (ft_btking(array, tetri, nbr_tetri, (count - 1)));
		}
	}
	ft_writearray(array, tetri[count]);
	return (ft_btking(array, tetri, nbr_tetri, (count + 1)));
}
