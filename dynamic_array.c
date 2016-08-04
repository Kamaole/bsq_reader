/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 17:35:45 by mfernand          #+#    #+#             */
/*   Updated: 2016/08/03 17:35:47 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			get_min(int **num_grid, int x, int y)
{
	int		smallest;

	smallest = num_grid[y - 1][x];
	if (num_grid[y - 1][x - 1] < smallest)
		smallest = num_grid[y - 1][x - 1];
	if (num_grid[y][x - 1] < smallest)
		smallest = num_grid[y][x - 1];
	return (smallest);
}

void		set_num(t_bsq *bsq, int i, int x, int y)
{
	if (bsq->grid[i] == bsq->obstacle)
		bsq->num_grid[y][x] = 0;
	else if (bsq->grid[i] == bsq->empty)
	{
		if (x == 0 || y == 0)
			bsq->num_grid[y][x] = 1;
		else
			bsq->num_grid[y][x] = get_min(bsq->num_grid, x, y) + 1;
		if (bsq->num_grid[y][x] > bsq->max_size)
		{
			bsq->x_loc = x;
			bsq->y_loc = y;
			bsq->max_size = bsq->num_grid[y][x];
		}
	}
}

void		set_first_row_col(t_bsq *bsq, int i, int x, int y)
{
	if (bsq->grid[i] == bsq->obstacle)
		bsq->num_grid[y][x] = 0;
	else
		bsq->num_grid[y][x] = 1;
}

void		init_num_grid(t_bsq *bsq)
{
	bsq->num_grid = (int **)malloc(sizeof(int *) * bsq->num_rows);
	bsq->num_grid[0] = (int *)malloc(sizeof(int) * bsq->num_cols);
}

void		set_num_grid(t_bsq *bsq, int i, int x, int y)
{
	if (x == 0 || y == 0)
		set_first_row_col(bsq, i, x, y);
	else
		set_num(bsq, i, x, y);
}

void		set_dynamic_array(t_bsq *bsq)
{
	int x;
	int y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	init_num_grid(bsq);
	while (bsq->grid[i])
	{
		if (bsq->grid[i] == '\n')
		{
			bsq->num_grid[y + 1] = (int *)malloc(sizeof(int) * bsq->num_cols);
			x = 0;
			y++;
		}
		else
		{
			set_num_grid(bsq, i, x, y);
			x++;
		}
		i++;
	}
}
