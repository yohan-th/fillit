/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 15:27:20 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 15:22:36 by ythollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

int		main(int argc, char **argv)
{
	int		a;
	char	*file;
	char	*boom = "ready ?";

	*boom = '!';
	a = 2;
	if (a != argc)
	{
		ft_putstr("usage: 1 fichier en parametre. ./a.out sample.fillit");
		exit(0);
	}
	if (ft_verif_fichier(argv) == 0 || ft_verif_fichier2(argv) == 0)
		ft_error();
	else
	{
		file = ft_read_file(argv[1]);
		ft_resol(file);
	}
	return (0);
}
