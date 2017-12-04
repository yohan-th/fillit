/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_resol.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 17:17:05 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 17:53:47 by evella      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_reset_tetri(t_cord **tetri, int nbr_tetri)
{
	int i;

	i = 0;
	while (i < nbr_tetri)
		ft_leftup_tetri(tetri[i++]);
}

int		ft_resol(char *str)
{
	char	**array;
	t_cord	**tetri;
	int		nbr_tetri;
	int		size_array;
	int		count;

	nbr_tetri = ft_nbrchar(str, '#') / 4;
	tetri = ft_get_info_tetri(str, nbr_tetri);
	size_array = ft_calc_size(nbr_tetri, tetri);
	array = ft_dimarray(size_array);
	count = 0;
	tetri[0][0].i = 0;
	while (ft_btking(array, tetri, nbr_tetri, count) == 0)
	{
		tetri[0][0].i = 0;
		free(array);
		ft_reset_tetri(tetri, nbr_tetri);
		array = ft_dimarray(++size_array);
	}
	ft_readarray(array);
	return (1);
}
