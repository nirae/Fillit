/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 10:19:01 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/14 12:02:57 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_usage(void)
{
	ft_putstr("usage: ./fillit file\n");
}

void	ft_print_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	ft_error(t_list **lst)
{
	ft_freelist(lst);
	ft_print_error();
}
