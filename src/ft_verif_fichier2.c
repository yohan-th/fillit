/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_verif_fichier2.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 15:26:32 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 17:54:43 by evella      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

#define BUF_SIZE 700

int		ft_verif_fichier2(char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	int		a;

	a = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buf, BUF_SIZE)) || buf[a])
	{
		buf[ret] = '\0';
		a++;
		if (ft_verif_string(buf, 0, 0, 1) != 1)
			return (0);
	}
	if (close(fd) == -1)
		return (0);
	return (1);
}
