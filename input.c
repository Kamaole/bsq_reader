/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 17:35:25 by mfernand          #+#    #+#             */
/*   Updated: 2016/08/03 17:35:26 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			first_row_len(char *first_buf)
{
	int		i;

	i = 0;
	while (first_buf[i] && first_buf[i] != '\n')
		i++;
	return (i);
}

void		set_grid_marks(t_bsq *bsq, char *first_buf, int info_len)
{
	bsq->square = first_buf[info_len - 1];
	bsq->obstacle = first_buf[info_len - 2];
	bsq->empty = first_buf[info_len - 3];
}

void		set_num_rows(t_bsq *bsq, char *first_buf, int info_len)
{
	int		i;
	int		tens;

	i = info_len - 4;
	tens = 1;
	while (i >= 0)
	{
		bsq->num_rows += (first_buf[i] - '0') * tens;
		tens *= 10;
		i--;
	}
}

void		set_num_cols(t_bsq *bsq, char *first_buf, int info_len)
{
	bsq->num_cols = 0;
	while (first_buf[(bsq->num_cols + 1) + info_len] != '\n'
		&& first_buf[bsq->num_cols + info_len])
		bsq->num_cols++;
}

void		set_grid(t_bsq *bsq, char *first_buf, int info_len, int fd)
{
	int		i;
	int		j;
	int		size;
	int		bytes_read;

	size = sizeof(char) * (bsq->num_rows * (bsq->num_cols + 1));
	bsq->grid = (char *)malloc(size);
	i = info_len + 1;
	j = 0;
	while (first_buf[i + j])
	{
		bsq->grid[j] = first_buf[i + j];
		j++;
	}
	while ((bytes_read = read(fd, bsq->grid + j, BUF_SIZE)))
	{
		j += bytes_read;
	}
	bsq->grid[j] = 0;
	if (j != bsq->num_rows * (bsq->num_cols + 1))
		ft_putstr("ERROR\n");
}

t_bsq		*get_input(int fd)
{
	t_bsq	*bsq;
	int		bytes_read;
	int		info_len;
	char	*first_buf;

	bsq = (t_bsq *)malloc(sizeof(t_bsq));
	bsq->x_loc = 0;
	bsq->y_loc = 0;
	bsq->max_size = 0;
	first_buf = malloc(BUF_SIZE + 1);
	bytes_read = read(fd, first_buf, BUF_SIZE);
	first_buf[bytes_read] = 0;
	info_len = first_row_len(first_buf);
	set_grid_marks(bsq, first_buf, info_len);
	set_num_rows(bsq, first_buf, info_len);
	set_num_cols(bsq, first_buf, info_len);
	set_grid(bsq, first_buf, info_len, fd);
	return (bsq);
}

t_bsq		*get_file_input(char *file_name)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	return (get_input(fd));
}

t_bsq		*get_std_input(void)
{
	int		fd;

	fd = 0;
	return (get_input(fd));
}
