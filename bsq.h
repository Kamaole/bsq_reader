#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // Delete
# include <time.h> // KiLlllLL MEeeEeeee

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

/* input.c */
t_bsq			*get_file_input(char *file_name);
t_bsq			*get_std_input(void);
t_bsq			*get_input(int fd);
void			set_grid(t_bsq *bsq, char *first_buf, int info_len, int fd);
void			set_num_cols(t_bsq *bsq, char *first_buf, int info_len);
void			set_num_rows(t_bsq *bsq, char *first_buf, int info_len);
void			set_grid_marks(t_bsq *bsq, char *first_buf, int info_len);
int				first_row_len(char *first_buf);

/* dynamic_array.c */
void			set_dynamic_array(t_bsq *bsq);
int				get_min(int **num_grid, int x, int y);

/* print.c */
void			print_result(t_bsq *bsq);
int				is_big_square(t_bsq *t_bsq, int x, int y);
char			get_char(t_bsq *bsq, int x, int y);

#endif
