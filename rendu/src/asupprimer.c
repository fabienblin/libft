
//////////////////////////////////////////
// ATTENTION A NE PAS RENDRE CE FICHIER //
//////////////////////////////////////////

#include <stdio.h>
#include "ft_printf.h"

void	puttformat(t_format *f)
{
	int i = 0;
	
	while (f)
	{
		printf("format[%d] : \"%s\"\n", i, f->tostring);
		printf("\ttype : %c\n",f->type);
		printf("\tsize : %d\n",f->size);
		printf("\tpreci : %d\n",f->preci);
		printf("\twidth : %d\n",f->width);
		printf("\tflags : \"%s\"\n",f->flags);
		printf("\tlen : %d\n",f->len);
		printf("\n");
		f = f->next;
		i++;
	}
}