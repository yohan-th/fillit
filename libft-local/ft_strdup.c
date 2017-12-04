/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: evella <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:22:55 by evella       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 18:22:58 by evella      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		a;
	char	*pt;

	a = 0;
	while (src[a])
		a++;
	pt = (char *)malloc((a + 1) * sizeof(char));
	if (!pt)
		return (NULL);
	a = 0;
	while (src[a])
	{
		pt[a] = src[a];
		a++;
	}
	pt[a] = '\0';
	return (pt);
}
