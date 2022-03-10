#include "push_swap.h"

void	manip_s(t_list **lst, char name)
{
	t_list	*tm_p;
	t_list	*tm_d;

	tm_p = *lst;
	if (tm_p && tm_p->next)
	{
		tm_d = tm_p->next;
		tm_p->next = tm_d->next;
		tm_d->next = tm_p;
		*lst = tm_d;
	}
	if (name == 'a')
		write(1, "sa\n", 3);
	else if (name == 'b')
		write(1, "sb\n", 3);
}

void	manip_r(t_list **lst, char name)
{
	t_list	*list;
	t_list	*dubl;

	list = *lst;
	dubl = *lst;
	if (list != NULL)
	{
		if ((*lst)->next)
			(*lst) = (*lst)->next;
		else
			return ;
		while (list->next)
			list = list->next;
		dubl->next = NULL;
		list->next = dubl;
		if (name == 'a')
			write(1, "ra\n", 3);
		else if (name == 'b')
			write(1, "rb\n", 3);
	}
}

void	manip_rr(t_list **lst, char name)
{
	t_list	*dubl;
	t_list	*tmp;

	if (!(*lst) || !((*lst)->next))
		return ;
	tmp = *lst;
	dubl = tmp;
	while (dubl->next)
		dubl = dubl->next;
	dubl->next = tmp;
	while (tmp->next != dubl)
		tmp = tmp->next;
	tmp->next = NULL;
	*lst = dubl;
	if (name == 'a')
		write(1, "rra\n", 4);
	else if (name == 'b')
		write(1, "rrb\n", 4);
}

void	manip_pa(t_list **lst_A, t_list **lst_B, int f)
{
	t_list	*new_a;

	if ((*lst_B))
	{
		new_a = (*lst_B);
		(*lst_B) = (*lst_B)->next;
		new_a->next = *lst_A;
		*lst_A = new_a;
	}
	if (f)
		write(1, "pa\n", 3);
}

void	manip_pb(t_list **lst_A, t_list **lst_B, int f)
{
	t_list	*new_a;

	if ((*lst_A))
	{
		new_a = (*lst_A);
		(*lst_A) = (*lst_A)->next;
		new_a->next = *lst_B;
		*lst_B = new_a;
	}
	if (f)
		write(1, "pb\n", 3);
}
