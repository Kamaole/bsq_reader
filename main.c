#include "bsq.h"

int		main(int ac, char **av)
{
	int		i;
	t_bsq	*input;
	clock_t start, end; // Delete

	start = clock(); // DeLeTE

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			input = get_file_input(av[i]);
			bsq(input);
			i++;
		}
	}
	else
	{
		input = get_std_input();
		bsq(input);
	}
	end = clock(); // PLS DELETEEE!!
	printf("\nNumber of seconds: %f\n", (end-start)/(double)CLOCKS_PER_SEC); // JUST KILL ME!!!
	return (0);
}
