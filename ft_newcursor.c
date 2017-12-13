/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newcursor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:46:10 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/13 18:48:01 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Params : lenght
** Return : struct of cursor
*/
t_cursor	*ft_newcursor(int len, t_list **lst)
{
	t_cursor	*result;

	if (!(result = ft_memalloc(sizeof(*result))))
		ft_error(lst);
	result->form = len;
	result->size = ft_sqrt(len * 4);
	result->pos = 0;
	result->check = 0;
	return (result);
}
