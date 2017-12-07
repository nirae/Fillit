/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:11:53 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/07 11:31:03 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef struct			s_tetri
{
	unsigned int		id;
	unsigned int		bin_value;
	unsigned char		value;
}						t_tetri;

typedef struct			s_cursor
{
	int					size;
	int					position;
	int					check;
	int					form;
}						t_cursor;

unsigned int			ft_atobin(char *str);
int						ft_backtracking(char *result, t_cursor cursor, t_list *lst, int j);
//int						ft_backtracking(char *result, t_cursor cursor, t_list *lst);

#endif
