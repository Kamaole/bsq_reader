#include "bsq.h"

void		bsq(t_bsq *bsq)
{
	printf("%d\n", bsq->num_rows);
	printf("%d\n", bsq->num_cols);
	printf("%c\n", bsq->empty);
	printf("%c\n", bsq->obstacle);
	printf("%c\n", bsq->square);
}
