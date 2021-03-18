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
			exit(0);
		i++;
	}
	return (ft_atoi(str));
}

void	print_list(t_list *pile1, t_list *pile2)
{
	t_list *tmp1;
	t_list *tmp2;

	tmp1 = pile1;
	tmp2 = pile2;
	printf("Pile1		Pile2\n");
	while(tmp1 || tmp2)
	{
		if (tmp1 && tmp2)
			printf("%d		%d\n", tmp1->content, tmp2->content);
		else if (tmp1)
			printf("%d\n", tmp1->content);
		else if (tmp2)
			printf("		%d\n", tmp2->content);
		if (tmp1)
			tmp1 = tmp1->next;
		if (tmp2)
			tmp2 = tmp2->next;
	}
}

int		check_error_parse(char **av, t_list **pile1, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_lstadd_back(pile1, ft_lstnew(my_atoi(av[i + 1])));
		i++;
	}
	return (1);
}

int	get_min(t_list *lst)
{
	int i;
	t_list *tmp;

	tmp = lst;
	i = lst->content;
	while (tmp)
	{
		if (tmp->content < i)
			i = tmp->content;
		tmp = tmp->next;
	}
	return (i);
}
int main(int ac, char **av)
{
	t_swap swap;
	t_list *pile1;
	t_list *pile2;
	t_list *tmp;
	int i;

	if (ac < 2)
		return (write(1, "Error\n", 7));
	swap.n = ac - 1;
	if (!(check_error_parse(av, &pile1, swap.n)))
		return(write(1, "Error\n", 6));
	while (pile1)
	{
		i = get_min(pile1);
		while (pile1->content != i)
			get_up(&pile1, 0);
		insert(&pile1, &pile2, 0);
	}
	while (pile2)
		insert(&pile2, &pile1, 1);
	print_list(pile1, pile2);
}