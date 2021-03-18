#include "push_swap.h"

void	ft_lstdelone_end(t_list **lst)
{
	t_list	*tmp;


	tmp = *lst;
	while ((tmp->next)->next)
		tmp = tmp->next;
	free((tmp->next)->next);
	tmp->next = NULL;
}

void	switch_first(t_list *lst, int a)
{
	t_list *tmp;
	int tmp2;

	if (lst == NULL || lst->next == NULL)
		return;
	tmp = lst;
	tmp = tmp->next;
	tmp2 = tmp->content;
	tmp->content = lst->content;
	lst->content = tmp2;
}

void	insert(t_list **src, t_list **dest, int a)
{
	if (a)
		printf("Pb\n");
	else
		printf("Pa\n");
	if (!*src)
		return;
	ft_lstadd_front(dest, ft_lstnew((*src)->content));
	ft_lstdelone(src);
}

void	get_up(t_list **lst, int a)
{
	int tmp;

	if (a)
		printf("Rb\n");
	else
		printf("Ra\n");
	if (!*lst)
		return;
	tmp = (*lst)->content;
	ft_lstdelone(lst);
	ft_lstadd_back(lst, ft_lstnew(tmp));
}

void	get_down(t_list **lst, int a)
{
	t_list *last;

	if (!*lst)
		return;
	last = ft_lstlast(*lst);
	ft_lstadd_front(lst, ft_lstnew(last->content));
	ft_lstdelone_end(lst);
}
