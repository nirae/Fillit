/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:41:37 by ndelest           #+#    #+#             */
/*   Updated: 2017/12/09 12:31:21 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_istetri(char *tetri)
{
	int		i;
	int		isvalid;

	i = 0;
	isvalid = 1;
	while (tetri[i] != 0)
	{
		if (tetri[i] == '#')
		{
			isvalid = 0;
			if (i != 0 && tetri[i - 1] == '#')
				isvalid = 1;
			if (isvalid != 1 && i > 5 && tetri[i - 5] == '#')
				isvalid = 1;
			if (isvalid != 1 && i < 15 && tetri[i + 5] == '#')
				isvalid = 1;
			if (isvalid != 1 && i < 18 && tetri[i + 1] == '#')
				isvalid = 1;
		}
		if (isvalid == 0)
			ft_print_error();
		i++;
	}
}