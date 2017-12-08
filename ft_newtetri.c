/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:50:10 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/08 09:54:51 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 ** Params : binary value of the tetriminos
 ** Return : the binary value of the tetriminos formated for put in square
 **			0 if not mached with one of the reference tetriminos
 */
static unsigned int		ft_check_tetri(unsigned int bin_value)
{
	unsigned int	*reftab;
	int				i;

	i = 0;
	reftab = NULL;
	reftab = ft_init_tab();
	while (i < 19)
	{
		if (bin_value % reftab[i] == 0)
			return (reftab[i]);
		i++;
	}
	return (0);
}

/*
 ** Params : id of the tetriminos, string of the value
 ** Return : struct of one tetriminos for put in list
 ** 			NULL if fail
 */
t_tetri		*ft_newtetri(int id, char *value_t)
{
	t_tetri		*result;

	if (!(result = ft_memalloc(sizeof(*result))))
		return (NULL);
	result->id = id;
	result->value = id + 'A';
	result->bin_value = ft_check_tetri(ft_atobin(value_t));
	if (result->bin_value == 0)
		return (NULL);
	return (result);
}
