#include "push_swap.h"

int		my_atoi(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			exit(write(1, "Error\n", 6));
		i++;
	}
	return (ft_atoi(str));
}

int		check_error_parse(char **av, t_swap *swap, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		swap->pile1[i] = my_atoi(av[i + 1]);
		i++;
	}
	return (1);
}

void	print_list(t_swap swap)
{
	int a = 0;

	write(1, "Pile A		Pile B\n", 15);
	//printf("taille %d\n", swap.taille1);
	while(a < swap.taille1 || a < swap.taille2 )
	{
		if (a < swap.taille1 && a < swap.taille2)
			printf("%d		%d\n", swap.pile1[a], swap.pile2[a]);
		else if(a < swap.taille1)
			printf("%d\n", swap.pile1[a]);
		else if(a < swap.taille2)
			printf("		%d\n", swap.pile2[a]);
		a++;
	}
}

int	get_max(int *pile, int len)
{
	int i;
	int max;

	i = 0;
	max = pile[0];
	while(i < len)
	{
		if (pile[i] > max)
			max = pile[i];
		i++;
	}
	return (max);
}

int	get_min(int *pile, int len)
{
	int i;
	int min;

	i = 0;
	min = pile[0];
	while(i < len)
	{
		if (pile[i] < min)
			min = pile[i];
		i++;
	}
	return (min);
}

int		is_sorted(int *pile, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (pile[i] > pile[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_swap swap;

	swap.i = 0;
	swap.taille2 = 0;
	swap.taille1 = ac - 1;
	swap.pile1 = malloc(sizeof(int) * swap.taille1);
	if (!(check_error_parse(av, &swap, swap.taille1)))
		return(write(1, "Error\n", 6));
	if (swap.taille1 == 0)
		return(write(1, "Error\n", 6));
	if (is_sorted(swap.pile1, swap.taille1))
	{
		printf("score = %d\n", swap.i);
		exit(EXIT_SUCCESS);
	}
	if (swap.taille1 <= 3)
		sort_three(&swap, swap.pile1, swap.taille1, 1);
	else if (swap.taille1 <= 5)
		sort_five(&swap);
	else if(swap.taille1 < 50)
		sort_default(&swap);
	else if (swap.taille1 < 200)
		sort_all(&swap, 9);
	else
		sort_all(&swap, 11);
	//printf("score = %d\n", swap.i);
}