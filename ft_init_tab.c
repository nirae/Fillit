/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:24:50 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/08 09:43:29 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Params : nothing
** Return : tab of all the valid tetriminos
*/
unsigned int	*ft_init_tab(void)
{
	unsigned int	*tab;

	if (!(tab = ft_memalloc(sizeof(unsigned int) * 19)))
		return (NULL);
	tab[0] = 15;
	tab[1] = 99;
	tab[2] = 306;
	tab[3] = 54;
	tab[4] = 561;
	tab[5] = 275;
	tab[6] = 547;
	tab[7] = 71;
	tab[8] = 116;
	tab[9] = 23;
	tab[10] = 113;
	tab[11] = 785;
	tab[12] = 802;
	tab[13] = 39;
	tab[14] = 562;
	tab[15] = 114;
	tab[16] = 305;
	tab[17] = 4369;
	tab[18] = 51;

	return (tab);
}
