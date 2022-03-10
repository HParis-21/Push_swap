#include "push_swap.h"

int	seq_elem(t_list *lst)
{
	t_list	*b;
	int		count;
	int		start;

	start = lst->index;
	b = lst->next;
	count = 1;
	while (b != NULL)
	{
		if (start < b->index)
		{
			count++;
			start = b->index;
		}
		b = b->next;
	}
	return (count);
}

int	ind_elem(t_list *lst, t_list *l_start)
{
	t_list	*b;
	int		count;
	int		start;

	b = lst->next;
	count = 1;
	start = lst->index;
	if (b == NULL)
		b = l_start;
	while (b != NULL)
	{
		if (b == lst)
			break ;
		if ((start + 1) == b->index)
		{
			count++;
			start = b->index;
		}
		b = b->next;
		if (b == NULL)
			b = l_start;
	}
	return (count);
}

void	one_mar_keep(t_list *lst)
{
	int	start;

	lst->keep_stack = 1;
	start = lst->index;
	lst = lst->next;
	while (lst != NULL)
	{
		if (start < lst->index)
		{
			lst->keep_stack = 1;
			start = lst->index;
		}
		lst = lst->next;
	}
}

void	two_mar_keep(t_list *lst, t_list *l_start)
{
	t_list	*b;
	int		start;

	lst->keep_stack = 1;
	b = lst->next;
	start = lst->index;
	if (b == NULL)
		b = l_start;
	while (b != NULL)
	{
		if (b == lst)
			break ;
		if ((start + 1) == b->index)
		{
			b->keep_stack = 1;
			start = b->index;
		}
		else
			b->keep_stack = 0;
		b = b->next;
		if (b == NULL)
			b = l_start;
	}
}

void	mark_keep(t_list **lst, t_stat *sist)
{
	t_list	*tmp;
	t_list	*a;

	a = *lst;
	tmp = get_list(*lst, a, sist->mark_up);
	if (sist->type_mark == 1)
		one_mar_keep(tmp);
	else
		two_mar_keep(tmp, *lst);
}
