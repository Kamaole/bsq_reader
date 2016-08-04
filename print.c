/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 17:35:57 by mfernand          #+#    #+#             */
/*   Updated: 2016/08/03 17:35:58 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

char		get_char(t_bsq *bsq, int x, int y)
{
	if (bsq->num_grid[y][x] > 0)
	{
		if (is_big_square(bsq, x, y))
			return (bsq->square);
		else
			return (bsq->empty);
	}
	else
	{
		if (is_big_square(bsq, x, y))
			return (bsq->square);
		return (bsq->obstacle);
	}
}

int			is_big_square(t_bsq *bsq, int x, int y)
{
	if (x > (bsq->x_loc - bsq->max_size)
		&& y > (bsq->y_loc - bsq->max_size)
		&& x <= bsq->x_loc
		&& y <= bsq->y_loc)
		return (1);
	return (0);
}

void		print_result(t_bsq *bsq)
{
	int		x;
	int		y;

	y = 0;
	while (y < bsq->num_rows)
	{
		x = 0;
		while (x < bsq->num_cols)
		{
			ft_putchar(get_char(bsq, x, y));
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
