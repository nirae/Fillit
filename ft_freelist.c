/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:26:23 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/14 12:06:19 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_freetetri(void *elem, size_t size)
{
	size = 0;
	ft_memdel((void **)&elem);
}

void			ft_freelist(t_list **lst)
{
	void	(*del)(void *elem, size_t size);

	del = &ft_freetetri;
	ft_lstdel(lst, del);
}
