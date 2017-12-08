/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfilled.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 08:37:43 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/08 09:44:48 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Params : result string, struct of the tetriminos, struct of the cursor
** Return : 1 or 0
** Search if the tetriminos can be put here
*/
int		ft_isfilled(char *result, t_tetri *tetri, t_cursor cursor)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < 4 && cursor.pos <= (cursor.size * cursor.size) + cursor.size)
	{
		cursor.check = cursor.pos + (j % 4);
		while (tetri->bin_value & (1 << j))
		{
			if (result[cursor.check++] == '.')
				++i;
			else
				return (0);
			++j;
		}
		while (!(tetri->bin_value & (1 << j)) && i < 4)
			++j;
		if (i > 0)
			cursor.pos = cursor.pos + cursor.size + 1;
	}
	if (i < 4)
		return (0);
	else
		return (1);
}
