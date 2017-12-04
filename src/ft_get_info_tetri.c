/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_info_tetri.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:48:59 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 17:53:11 by evella      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_get_most_left_tetri(t_cord *tetri)
{
	int most_left;
	int i;

	i = 0;
	most_left = tetri[0].x;
	while (i < 4)
	{
		if (tetri[i++].x < most_left)
			most_left = tetri[i].x;
	}
	return (most_left);
}

void	ft_leftup_tetri(t_cord *tetri)
{
	int i;
	int up;
	int left;

	i = 0;
	up = 5;
	left = 5;
	while (i < 4)
	{
		if (tetri[i].x < up)
			up = tetri[i].x;
		if (tetri[i].y < left)
			left = tetri[i].y;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		tetri[i].x -= up;
		tetri[i].y -= left;
		i++;
	}
}

t_cord	*ft_fill_tetri(char *str, int i, int num_tetri)
{
	t_cord	*coord;
	int		count;
	int		x;
	int		y;

	coord = (t_cord *)malloc(sizeof(t_cord) * 4);
	count = 0;
	y = 0;
	x = 0;
	while (str[i] && count < 4)
	{
		if (str[i++] == '#')
		{
			coord[count].x = x;
			coord[count].y = y;
			coord[count++].val = num_tetri + 65;
		}
		x++;
		if (str[i] == '\n')
			y++;
		if (str[i] == '\n')
			x = -1;
	}
	return (coord);
}

t_cord	**ft_get_info_tetri(char *str, int nbr_tetri)
{
	t_cord	**coord;
	int		tetri;

	if (!(coord = (t_cord **)malloc(sizeof(t_cord *) * nbr_tetri)))
		return (NULL);
	tetri = 0;
	while (tetri < nbr_tetri)
	{
		if (!(coord[tetri] = ft_fill_tetri(str, 21 * tetri, tetri)))
			return (NULL);
		ft_leftup_tetri(coord[tetri]);
		tetri++;
	}
	return (coord);
}
