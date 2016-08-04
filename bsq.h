/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 17:36:11 by mfernand          #+#    #+#             */
/*   Updated: 2016/08/03 17:36:13 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include <time.h> //Delete

# define BUF_SIZE 16384

typedef struct	s_bsq
{
	int			num_rows;
	int			num_cols;
	char		empty;
	char		obstacle;
	char		square;
	char		*grid;
	int			**num_grid;
	int			max_size;
	int			x_loc;
	int			y_loc;
}				t_bsq;

void			bsq(t_bsq *bsq);

t_bsq			*get_file_input(char *file_name);
t_bsq			*get_std_input(void);
t_bsq			*get_input(int fd);
void			set_grid(t_bsq *bsq, char *first_buf, int info_len, int fd);
void			set_num_cols(t_bsq *bsq, char *first_buf, int info_len);
void			set_num_rows(t_bsq *bsq, char *first_buf, int info_len);
void			set_grid_marks(t_bsq *bsq, char *first_buf, int info_len);
int				first_row_len(char *first_buf);

void			set_dynamic_array(t_bsq *bsq);
void			set_num_grid(t_bsq *bsq, int i, int x, int y);
void			init_num_grid(t_bsq *bsq);
void			set_first_row_col(t_bsq *bsq, int i, int x, int y);
void			set_num(t_bsq *bsq, int i, int x, int y);
int				get_min(int **num_grid, int x, int y);

void			print_result(t_bsq *bsq);
int				is_big_square(t_bsq *t_bsq, int x, int y);
char			get_char(t_bsq *bsq, int x, int y);
void			ft_putchar(char c);
void			ft_putstr(char *str);

#endif
