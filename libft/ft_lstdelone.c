#include "libft.h"
#include <stdio.h>

void	ft_lstdelone(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	free(tmp);
	tmp = NULL;
}
