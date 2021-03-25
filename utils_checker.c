#include "push_swap.h"

void	switch_first(t_swap *swap, int a)
{
	int	tmp;

	if (a == 1)
	{
		if (swap->taille1 <= 1)
			return ;
		tmp = swap->pile1[0];
		swap->pile1[0] = swap->pile1[1];
		swap->pile1[1] = tmp;
	}
	else
	{
		if (swap->taille2 <= 1)
			return ;
		tmp = swap->pile2[0];
		swap->pile2[0] = swap->pile2[1];
		swap->pile2[1] = tmp;
	}
}

void	free_pile(t_swap *swap, int **New1, int **New2)
{
	if (swap->pile1)
		free(swap->pile1);
	swap->pile1 = NULL;
	if (swap->pile2)
		free(swap->pile2);
	swap->pile2 = NULL;
	swap->pile1 = *New1;
	swap->pile2 = *New2;
}

void	insert_pa(t_swap *swap)
{
	int		i;
	int		*New1;
	int		*New2;

	i = 0;
	if (swap->taille2 == 0)
		return ;
	New1 = malloc(sizeof(int) * swap->taille1 + 1);
	New2 = malloc(sizeof(int) * swap->taille2 - 1);
	New1[0] = swap->pile2[0];
	while (i < swap->taille1)
	{
		New1[i + 1] = swap->pile1[i];
		i++;
	}
	i = 0;
	while (i < swap->taille2 - 1)
	{
		New2[i] = swap->pile2[i + 1];
		i++;
	}
	free_pile(swap, &New1, &New2);
	swap->taille1++;
	swap->taille2--;
}

void	insert_pb(t_swap *swap)
{
	int		i;
	int		*New1;
	int		*New2;

	i = 0;
	if (swap->taille1 == 0)
		return ;
	New1 = malloc(sizeof(int) * swap->taille1 - 1);
	New2 = malloc(sizeof(int) * swap->taille2 + 1);
	New2[0] = swap->pile1[0];
	while (i < swap->taille2)
	{
		New2[i + 1] = swap->pile2[i];
		i++;
	}
	i = 0;
	while (i < swap->taille1 - 1)
	{
		New1[i] = swap->pile1[i + 1];
		i++;
	}
	free_pile(swap, &New1, &New2);
	swap->taille1--;
	swap->taille2++;
}
