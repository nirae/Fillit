/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atobin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:16:47 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/08 18:36:52 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		if (str[j] != '\n' && str[j] != '#' && str[j] != '.')
			ft_print_error();
		if (str[j] == '\n')
			n++;
		if (str[j] == '#')
		{	
			a = a | (1 << (j - n));
			nbblocks++;
		}
		j++;
	}
	if (nbblocks != 4 || n > 5)
		ft_print_error();
	return (a);
}
