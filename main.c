#include "bsq.h"

int		main(int ac, char **av)
{
	int		i;
	char	*input;
	clock_t start, end;

	start = clock();

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			input = get_file_input(av[i]);
			i++;
		}
	}
	else
	{
		input = get_std_input();
	}

	end = clock();
	printf( "Number of seconds: %f\n", (end-start)/(double)CLOCKS_PER_SEC );
	bsq(input);
}
