/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_array.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 15:22:47 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 17:52:28 by evella      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_readarray(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		while (*array)
		{
			ft_putstr(*array++);
			write(1, "\n", 1);
		}
		i++;
	}
}

void	ft_filldotarray(char **array, int size)
{
	int i;
	int n;

	i = 0;
	while (i < size)
	{
		n = 0;
		while (n < size)
			array[i][n++] = '.';
		i++;
	}
}

char	**ft_dimarray(int size)
{
	int		i;
	char	**array;

	i = 0;
	if (!(array = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	array[size] = NULL;
	while (i < size)
	{
		if (!(array[i++] = ft_strnew(size)))
			return (NULL);
	}
	ft_filldotarray(array, size);
	return (array);
}

int		ft_calc_size(int nbr_tetri, t_cord **tetri)
{
	int sizemin;
	int i;
	int n;

	i = 0;
	sizemin = 0;
	while (i < nbr_tetri)
	{
		n = -1;
		while (++n < 4)
		{
			if (tetri[i][n].x > sizemin)
				sizemin = tetri[i][n].x + 1;
			if (tetri[i][n].y > sizemin)
				sizemin = tetri[i][n].y + 1;
		}
		i++;
	}
	while (sizemin * sizemin < nbr_tetri * 4)
		sizemin++;
	return (sizemin);
}
