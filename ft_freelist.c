/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:26:23 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/11 13:51:34 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_freetetri(t_list *elem, size_t size)
{
	size = 0;
	free(elem);
}

void	ft_freelist(t_list **lst)
{
	void	(*del)(t_list *elem, size_t size);
	del = &ft_freetetri;
	//ft_lstiter(*lst, f);
	ft_lstdel(lst, del());
}
