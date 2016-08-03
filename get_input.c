#include "bsq.h"

int			g_rows = 0;
int			g_cols = 0;

void		set_num_of_rows(char *buf, int len)
{
	int i;
	int j;

	i = len - 4;
	j = 1;
	while(i >= 0)
	{
		g_rows += (buf[i] - '0') * j;
		j *= 10;
		i--;
	}
}

void		set_num_of_cols(char *buf)
{
	int i;
	int cols;
	int rows;

	i = 0;
	cols = 0;
	rows = 0;
	while (rows < 2)
	{
		if (buf[i] == '\n')
			rows++;
		else if (rows == 1)
			cols++;
		i++;
	}
	g_cols = cols;
}

int			get_info_length(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\n')
	{
		i++;
	}
	return (i);
}

char		*get_file_input(char *file_name)
{
	int		fd;
	int		bytes_read;
	char	buf[BUF_SIZE];
	char	*input;
	int		len;

	fd = open(file_name, O_RDONLY);
	bytes_read = read(0, buf, BUF_SIZE);
	buf[bytes_read] = '\0';
	len = get_info_length(buf);
	set_num_of_rows(buf, len);
	set_num_of_cols(buf);
	input = (char *)malloc(sizeof(char) * (g_cols * g_rows + 1));
	input = ft_strcat(input, buf);
	while ((bytes_read = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		input = str_concat(input, buf);
	}
	return (input);
}

char		*get_std_input(void)
{
	int		bytes_read;
	char	buf[BUF_SIZE];
	char	*input;
	int		len;

	bytes_read = read(0, buf, BUF_SIZE);
	buf[bytes_read] = '\0';
	len = get_info_length(buf);
	set_num_of_rows(buf, len);
	set_num_of_cols(buf);
	input = (char *)malloc(sizeof(char) * (g_cols * g_rows + 1));
	input = ft_strcat(input, buf);
	while ((bytes_read = read(0, buf, BUF_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		input = ft_strcat(input, buf);
	}
	return (input);	
}
