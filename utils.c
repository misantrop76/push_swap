#include "push_swap.h"

void	switch_first(t_swap *swap, int a)
{
	int tmp;

	if (a == 1)
	{
		if (swap->taille1 <= 1)
			return;
		write(1, "sa\n", 3);
		tmp = swap->pile1[0];
		swap->pile1[0] = swap->pile1[1];
		swap->pile1[1] = tmp;
	}
	else
	{
		if (swap->taille2 <= 1)
			return;
		write(1, "sa\n", 3);
		tmp = swap->pile2[0];
		swap->pile2[0] = swap->pile2[1];
		swap->pile2[1] = tmp;
	}
	swap->i++;
}

int	*del_first(int *pile, int *len)
{
	int i = 0;
	int *new;

	if (*len <= 1)
	{
		if (*len != 0)
			*len = *len - 1;
		return (pile);
	}
	new = malloc(sizeof(int) * (*len - 1));
	while (i < (*len - 1))
	{
		new[i] = pile[i + 1];
		i++;
	}
	*len = *len - 1;
	return (new);

}

int		*add_one(int *pile, int len, int newi)
{
	int *new;
	int i;

	i = 0;
	new = malloc(sizeof(int) * (len + 1));
	new[0] = newi;
	while (i < len)
	{
		new[i + 1] = pile[i];
		i++;
	}
	return (new);
}

void	insert_pa(t_swap *swap)
{
	int i = 0;
	int *tmp1;
	int *tmp2;
	
	if (swap->taille2 == 0)
		return ;
	swap->i = swap->i + 1;
	tmp1 = swap->pile1;
	tmp2 = swap->pile2;
	swap->pile1 = add_one(swap->pile1, swap->taille1, swap->pile2[0]);
	swap->pile2 = del_first(swap->pile2, &swap->taille2);
	swap->taille1++;
	//if(tmp1)
	//	free(tmp1);
	//if (tmp2)
	//	free(tmp2);
	write(1, "pb\n", 3);
}

void	insert_pb(t_swap *swap)
{
	int i = 0;
	int *tmp1;
	int *tmp2;

	if (swap->taille1 == 0)
		return ;
	swap->i = swap->i + 1;
	tmp1 = swap->pile1;
	tmp2 = swap->pile2;
	swap->pile2 = add_one(swap->pile2, swap->taille2, swap->pile1[0]);
	swap->pile1 = del_first(swap->pile1, &swap->taille1);
	swap->taille2++;
	//if(tmp1)
	//	free(tmp1);
	//if (tmp2)
	//	free(tmp2);
	write(1, "pb\n", 3);
}

void	get_up(int *pile, int len, int j, int *a)
{
	int tmp;
	int i = 0;

	*a = *a + 1;	
	if (len <= 1)
		return;
	tmp = pile[0];
	while (i < len)
	{
		pile[i] = pile[i + 1];
		i++;
	}
	pile[len - 1] = tmp;
	if (j == 1)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	get_down(int *pile, int len, int j, int *a)
{
	int tmp;
	int i = len - 1;

	if (len <= 1)
		return;
	tmp = pile[len - 1];
	i++;
	while (i > 0)
	{
		pile[i] = pile[i - 1];
		i--;
	}
	pile[0] = tmp;
	if (j == 1)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
	*a = *a + 1;
}
