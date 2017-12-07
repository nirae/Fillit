/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 19:56:11 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/07 14:09:22 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
	Permet de compter le nombre de case vides inutilisables en lignes type :
	AAABBB
	.A...C		--> 4 cases inutilisables
	DDDDCC
*/
static int		ft_emptyline(char *result, t_cursor cursor)
{
	int		i;
	int		j;
	int		emptysize;
	int		isempty;
	
	i = cursor.size + 1;
	j = cursor.size + 1;
	isempty = 0;
	while (i < cursor.check && i / j < cursor.size - 1)
	{
		emptysize = 0;
		while (result[i++] == '.' && emptysize < 4 &&
				result[i - j] != '.' && result[i + j] != '.')
			++emptysize;
		if (emptysize < 4)
			isempty = isempty + emptysize;
		++i;
	}
	return (isempty);
}

static void	ft_deleteit(char *result, t_cursor cursor, int j)
{	
	cursor.position = 0;
	while (result[cursor.position] != 0)
	{
		if (result[cursor.position] == 'A' + j)
			result[cursor.position] = '.';
		++cursor.position;
	}
}

static void	ft_fillit(char *result, t_tetri *tetri, t_cursor cursor)
{
	int				k;
	int				count;

	k = 0;
	count = 0;
	while (count < 4)
	{
		cursor.check = cursor.position + (k % 4);
		while (tetri->bin_value & (1 << k))
		{
			result[cursor.check++] = tetri->value;
			++count;
			++k;
		}
		while (!(tetri->bin_value & (1 << k)))
			++k;
		if (count > 0)
			cursor.position = cursor.position + cursor.size + 1;
	}
}

static int		ft_isfilled(char *result, t_tetri *tetri, t_cursor cursor)
{
	int				count;
	int				j;

	count = 0;
	j = 0;
	while (count < 4 && cursor.position <= (cursor.size * cursor.size) + cursor.size)
	{
		cursor.check = cursor.position + (j % 4);
		while (tetri->bin_value & (1 << j))
		{
			if (result[cursor.check++] == '.')
				++count;
			else
				return (0);
			++j;
		}
		while (!(tetri->bin_value & (1 << j)) && count < 4)
			++j;
		if (count > 0)
			cursor.position = cursor.position + cursor.size + 1;
	}
	if (count < 4)
		return (0);
	else
		return (1);
}

// Pareil que la foncton au dessus mais avec les colonnes
static int	ft_emptycol(char *result, t_cursor cursor)
{
	int		i;
	int		k;
	int		emptysize;
	int		isempty;

	i = 1;
	isempty = 0;
	while (i < cursor.check && i <= cursor.size)
	{
		k = i;
		emptysize = 0;
		while (result[k] == '.' && emptysize < 4 && result[k - 1] != '.'
				&& result[k + 1] != '.')
		{
			++emptysize;
			k = k + cursor.size + 1;
		}
		if (emptysize < 4)
			isempty = isempty + emptysize;
		++i;
	}
	return (isempty);
}
/*
int		ft_backtracking(char *result, t_cursor cursor, t_list *lst, int j)
{
	if (ft_lsti(lst, j) == NULL)
		return (1);
	if (ft_emptyline(result, cursor) + ft_emptycol(result, cursor)
			> (cursor.size * cursor.size) - (cursor.form * 4))
		return (0);
	while (!(ft_isfilled(result, ((t_tetri *)(ft_lsti(lst, j)->content)), cursor)) && result[cursor.position] != 0)
		++cursor.position;
	if (result[cursor.position] != 0)
	{
		ft_fillit(result, ((t_tetri *)(ft_lsti(lst, j)->content)), cursor);
		cursor.check = cursor.position;
		cursor.position = 0;
		if (ft_backtracking(result, cursor, lst, j + 1) == 1)
			return (1);
		cursor.position = cursor.check;
		ft_deleteit(result, cursor, j);
		++cursor.position;
		return (ft_backtracking(result, cursor, lst, j));
	}
	return (0);	
}
*/

int		ft_backtracking(char *result, t_cursor cursor, t_list *lst, int j)
{
	if (lst == NULL)
		return (1);
	if (ft_emptyline(result, cursor) + ft_emptycol(result, cursor)
			> (cursor.size * cursor.size) - (cursor.form * 4))
		return (0);
	while (!(ft_isfilled(result, ((t_tetri *)(lst->content)), cursor)) && result[cursor.position] != 0)
		++cursor.position;
	if (result[cursor.position] != 0)
	{
		ft_fillit(result, ((t_tetri *)(lst->content)), cursor);
		cursor.check = cursor.position;
		cursor.position = 0;
		if (ft_backtracking(result, cursor, lst->next, j + 1) == 1)
			return (1);
		cursor.position = cursor.check;
		ft_deleteit(result, cursor, j);
		++cursor.position;
		return (ft_backtracking(result, cursor, lst, j));
	}
	return (0);	
}
