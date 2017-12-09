/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:41:37 by ndelest           #+#    #+#             */
/*   Updated: 2017/12/09 14:12:54 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_wrongdiagonal(char *tetri, int i)
{
	if (tetri[i - 6] == '#' && (tetri[i - 1] == '#' || tetri[i - 5] == '#'))
		return (1);
	if (tetri[i - 4] == '#' && (tetri[i + 1] == '#' || tetri[i - 5] == '#'))
		return (1);
	if (tetri[i + 4] == '#' && (tetri[i - 1] == '#' || tetri[i + 5] == '#'))
		return (1);
	if (tetri[i + 6] == '#' && (tetri[i + 1] == '#' || tetri[i + 5] == '#'))
		return (1);
	return (0);
}

/*static int		ft_isnotalone(char *tetri, int i)
{
	if (i != 0 && tetri[i - 1] == '#')
		return (1);
	if (i > 5 && tetri[i - 5] == '#')
		return (1);
	if (i < 15 && tetri[i + 5] == '#')
		return (1);
	if (i < 18 && tetri[i + 1] == '#')
		return (1);
	return (0);
}*/

void			ft_istetri(char *tetri)
{
	int		i;

	i = 0;
	while (tetri[i] != 0)
	{
		if (tetri[i] == '#')
		{
//			if (!ft_isnotalone(tetri, i))
//				ft_print_error();
			if (i > 5 && i < 18 && (tetri[i - 6] == '#' || tetri[i - 4] == '#' 
						|| tetri[i + 4] == '#' || tetri[i + 6] == '#'))
			{
				if (!ft_wrongdiagonal(tetri, i))
					ft_print_error();
			}
		}
		i++;
	}
}