/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 10:19:01 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/08 13:36:30 by ndubouil         ###   ########.fr       */
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
