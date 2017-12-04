/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 17:17:11 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 18:11:15 by evella      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "../libft-local/libft.h"

typedef struct		s_coord
{
	int		x;
	int		y;
	char	val;
	int		i;
}					t_cord;

int					ft_movetetri(t_cord *tetri, char **array);
void				ft_leftup_tetri(t_cord *tetri);
int					ft_btking(char **array, t_cord **tetri, int nbr_tetri,
								int count);
void				ft_readarray(char **array);
void				ft_error(void);
int					ft_resol(char *str);
char				*ft_read_file(char *file);
int					ft_nbrchar(char *str, char c);
t_cord				**ft_get_info_tetri(char *str, int nbr_tetri);
int					ft_calc_size(int nbr_tetri, t_cord **tetri);
char				**ft_dimarray(int size);
int					ft_read(void);
int					ft_verif_fichier(char **argv);
int					ft_verif_fichier2(char **argv);
int					ft_verif_tetri(char c);
int					ft_verif_string(char *str, int a, int b, int c);
#endif
