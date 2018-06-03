/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:30:00 by alefebvr          #+#    #+#             */
/*   Updated: 2017/12/18 15:43:39 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 2
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

int		ft_valid_trois(char *tab);
char	*ft_get_tab(char **argv);
void	ft_double(char *tab);
char	*ft_get_last_tab(int nb);
int		ft_get_nb_diese(char *tab);
void	ft_final_tab(char **tetri, char *tab);
int		*ft_tetri_position(char *tetri, char *tab);
void	ft_fill_tab(char *ftab, char *tetri, int place, int *pos);
int		ft_get_nb_tetri(char **tetri);
char	*ft_next_tab(char *ftab, int i);
int		ft_is_placeable(char *ftab, int *pos);
int		ft_back(char *ftab, char *tetri);
int		ft_back2(char letter, char *ftab, int *pos);

#endif
