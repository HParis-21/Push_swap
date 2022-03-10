#include "push_swap.h"

void	*free_stack(t_list **arg)
{
	t_list	*tmp;
	t_list	*dubl;

	tmp = *arg;
	while (tmp)
	{
		dubl = tmp->next;
		free(tmp);
		tmp = dubl;
	}
	*arg = NULL;
	return (NULL);
}

void	creat_stack(t_list **arg, int val)
{
	t_list	*tmp;
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!(new))
	{
		free_stack(arg);
		return ;
	}
	new->val = val;
	new->keep_stack = 0;
	new->next = NULL;
	tmp = *arg;
	if (!tmp)
		*arg = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int	ft_error(void)
{
	write(2, "ERROR\n", 6);
	return (1);
}

int	stack_size(t_list *list)
{
	int	size;

	size = 0;
	while (list)
	{
		list = list->next;
		size++;
	}
	return (size);
}
