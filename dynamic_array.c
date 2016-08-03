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

void		set_dynamic_array(t_bsq *bsq)
{
	int		i;
	int		x;
	int		y;
	int		past_first;

	bsq->num_grid = (int **)malloc(sizeof(int *) * bsq->num_rows);
	i = 0;
	x = 0;
	y = 0;
	past_first = 0;
	while (bsq->grid[i])
	{
		if (bsq->grid[i] == '\n')
		{
			bsq->num_grid[y] = (int *)malloc(sizeof(int) * (bsq->num_cols + 1));
			x = 0;
			y++;
		}
		else
		{
			if (x == 0 || y == 0)
			{
				if (bsq->grid[i] == bsq->empty)
				{
					bsq->num_grid[y][x] = 1;
				}
			}
			else
			{
				if (bsq->grid[i] == bsq->empty)
				{
					bsq->num_grid[y][x] = get_min(bsq->num_grid, x, y) + 1;
				}
			}
			if (bsq->grid[i] == bsq->obstacle)
			{
				bsq->num_grid[y][x] = 0;
			}
			if (bsq->num_grid[y][x] > bsq->max_size)
			{
				bsq->x_loc = x;
				bsq->y_loc = y;
				bsq->max_size = bsq->num_grid[y][x];
			}
			x++;
		}
		i++;
	}
}
