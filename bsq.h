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
	int			max_size;
	char		empty;
	char		obstacle;
	char		square;
	char		*grid;
	char		**num_grid;
}				t_bsq;

void			bsq(t_bsq *bsq);

t_bsq			*get_file_input(char *file_name);
t_bsq			*get_std_input(void);

#endif
