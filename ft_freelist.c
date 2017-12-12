/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:26:23 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/12 14:24:51 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_freetetri(void *elem, size_t size)
{
	size = 0;
	free(elem);
	elem = NULL;
}

void			ft_freelist(t_list **lst)
{
	void	(*del)(void *elem, size_t size);
	del = &ft_freetetri;
	ft_lstdel(&lst, del);
}
