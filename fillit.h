/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:11:53 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/09 12:03:14 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

# define BUFF_SIZE 20

typedef struct			s_tetri
{
	unsigned int		id;
	unsigned int		bin_value;
	unsigned char		value;
}						t_tetri;

typedef struct			s_cursor
{
	int					size;
	int					pos;
	int					check;
	int					form;
}						t_cursor;

unsigned int			ft_atobin(char *str);
int						ft_isfilled(char *result, t_tetri *tetri,
							t_cursor cursor);
void					ft_fillit(char *result, t_tetri *tetri,
							t_cursor cursor);
unsigned int			*ft_init_tab(void);
char					*ft_makesquare(unsigned int size);
t_list					*ft_filetolist(char *file);
int						ft_backtrack(char *result, t_cursor cursor,
							t_list *lst, int j);
t_tetri					*ft_newtetri(int id, char *value_t);
t_cursor				*ft_newcursor(int len);
void					ft_print_usage(void);
void					ft_print_error(void);
void					ft_print_error_toolong(int len);

#endif
