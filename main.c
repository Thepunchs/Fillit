/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:34:22 by alefebvr          #+#    #+#             */
/*   Updated: 2017/12/17 16:41:27 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*tab;

	if (argc == 2)
	{
		if (!(tab = ft_get_tab(argv)))
		{
			ft_putstr("error\n");
			return (0);
		}
		if (!(ft_valid_trois(tab)))
		{
			ft_putstr("error\n");
			return (0);
		}
		ft_double(tab);
	}
	else
		ft_putstr("usage: ./fillit <valid_file>");
	return (0);
}
