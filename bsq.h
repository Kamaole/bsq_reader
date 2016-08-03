#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // Delete
# include <time.h> // Delete

# define BUF_SIZE 131072

void		bsq(char *input);

int			get_info_length(char *buf);
void		set_num_of_cols(char *buf);
void		set_num_of_rows(char *buf, int len);

char		*get_file_input(char *file_name);
char		*get_std_input(void);

char		*str_concat(char *s1, char *s2);
int			ft_strlen(char *str);
char		*ft_strcat(char *dest, char *src);

#endif