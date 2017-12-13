/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makesquare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:28:55 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/13 18:54:59 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Params : size of the square
** Return : string contain the empty result square ready for fillit
*/
char	*ft_makesquare(t_cursor *cursor, t_list **lst)
{
	char			*result;
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;
	unsigned int	size;

	size = cursor->size;
	if (!(result = ft_strnew((size * size) + size)))
	{
		free(cursor);
		ft_error(lst);
	}
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
