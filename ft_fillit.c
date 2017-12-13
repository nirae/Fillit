/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 08:33:02 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/13 19:33:51 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fillit(char *result, t_tetri *tetri, t_cursor cursor)
{
	int				k;
	int				count;

	k = 0;
	count = 0;
	while (count < 4)
	{
		cursor.check = cursor.pos + (k % 4);
		while (tetri->bin_value & (1 << k))
		{
			result[cursor.check++] = tetri->value;
			++count;
			++k;
		}
		while (!(tetri->bin_value & (1 << k)))
			++k;
		if (count > 0)
			cursor.pos = cursor.pos + cursor.size + 1;
	}
}
