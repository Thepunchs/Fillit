/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:21:20 by alefebvr          #+#    #+#             */
/*   Updated: 2017/12/15 14:19:45 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_get_tab(char **argv)
{
	int			fd;
	int			ret;
	char		buf[BUF_SIZE + 1];
	char		*tab;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read(fd, buf, BUF_SIZE);
	tab = ft_strdup(buf);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tab = ft_strjoin(tab, buf);
	}
	close(fd);
	return (tab);
}

int		ft_back2(char letter, char *ftab, int *pos)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (k < 4 && ftab[i])
	{
		if (ftab[i + pos[0]] == letter && ftab[i + pos[1]] == letter &&
				ftab[i + pos[2]] == letter && ftab[i + pos[3]] == letter)
		{
			ftab[i + pos[0]] = '.';
			ftab[i + pos[1]] = '.';
			ftab[i + pos[2]] = '.';
			ftab[i + pos[3]] = '.';
			k = 5;
		}
		i++;
	}
	return (i);
}

int		*ft_tetri_position(char *tetri, char *tab)
{
	int *pos;
	int k;
	int i;
	int p;
	int x;

	x = 0;
	p = 0;
	while (tab[p] != '\n')
		p++;
	i = 0;
	k = 0;
	pos = ft_memalloc(4);
	while (tetri[i])
	{
		if (tetri[i] == '\n')
			x++;
		if (tetri[i] != '.' && tetri[i] != '\n' && tetri[i] != '\0')
		{
			pos[k++] = i + (x * (p - 3)) - x;
		}
		i++;
	}
	return (pos);
}
