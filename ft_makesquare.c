/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makesquare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:28:55 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/09 11:50:49 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Params : size of the square
** Return : string contain the empty result square ready for fillit
*/
char	*ft_makesquare(unsigned int size)
{
	char			*result;
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	if (!(result = ft_strnew((size * size) + size)))
		return (NULL);
	i = 0;
	j = 0;
	while (j < size)
	{
		count = 0;
		while (count++ < size)
			result[i++] = '.';
		result[i++] = '\n';
		j++;
	}
	return (result);
}
