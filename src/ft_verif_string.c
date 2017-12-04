/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_verif_string.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 15:26:44 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 17:55:02 by evella      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_ccblocs(char *str, int a, int c, int count)
{
	while (str[a])
	{
		while (count <= 21)
		{
			if (str[a] == '#')
			{
				if (str[a + 1] == '#')
					c++;
				if (str[a - 1] == '#')
					c++;
				if (str[a + 5] == '#' && count <= 15)
					c++;
				if (str[a - 5] == '#' && count >= 5)
					c++;
			}
			a++;
			count++;
		}
		count = 1;
		if (c < 6 || c > 10)
			return (0);
		c = 0;
	}
	return (1);
}

int		ft_tblocs(char *str)
{
	int a;
	int c;
	int max;

	a = 0;
	c = 0;
	max = 0;
	while (str[a])
	{
		c++;
		if (c == 21)
			c = 0;
		a++;
		max++;
	}
	if ((c == 20 || c == 0) && max <= 546)
		return (1);
	else
		return (0);
}

int		ft_cblocs(char *str)
{
	int comp_diez;
	int comp_point;
	int c;

	comp_diez = 0;
	comp_point = 0;
	c = 1;
	while (*str)
	{
		while (c <= 21)
		{
			if (*str == '#')
				comp_diez++;
			if (*str == '.')
				comp_point++;
			if (comp_diez > 4 || comp_point > 12)
				return (0);
			str++;
			c++;
		}
		comp_diez = 0;
		comp_point = 0;
		c = 1;
	}
	return (1);
}

int		ft_verif_string(char *str, int a, int b, int c)
{
	while (str[a])
	{
		while (c <= 21)
		{
			if (c < 21 && str[a] == '\n' && str[a - 1] == '\n')
				return (0);
			if (str[a] == '\n')
				b++;
			if (b > 5)
				return (0);
			a++;
			c++;
		}
		c = 1;
		b = 0;
	}
	if (str[a - 1] == '\n' && str[a - 2] == '\n')
		return (0);
	if (ft_cblocs(str) == 1 && ft_tblocs(str) == 1
		&& ft_ccblocs(str, 0, 0, 1) == 1)
		return (1);
	return (0);
}
