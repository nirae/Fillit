/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atobin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:16:47 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/09 14:24:43 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_isvalid(char c)
{
	if (c != '\n' && c != '#' && c != '.')
		ft_print_error();
}

static void		ft_istetrivalid(int nbblocks, int n, int k)
{
	if (nbblocks != 4 || n != 4 || k != 16)
		ft_print_error();
}

unsigned int	ft_atobin(char *str)
{
	int				j;
	int				n;
	int				nbblocks;
	unsigned int	a;

	j = 0;
	a = 0;
	n = 0;
	nbblocks = 0;
	while (str[j] != 0)
	{
		ft_isvalid(str[j]);
		if (str[j] == '\n')
			n++;
		if (str[j] == '#')
		{
			a = a | (1 << (j - n));
			nbblocks++;
		}
		j++;
	}
	ft_istetrivalid(nbblocks, n, j - n);
	return (a);
}
