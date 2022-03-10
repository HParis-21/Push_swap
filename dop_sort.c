#include "push_swap.h"

int	max_index(t_list *lst)
{
	int	max_index;

	max_index = 0;
	while (lst != NULL)
	{
		if (lst->index > max_index)
			max_index = lst->index;
		lst = lst->next;
	}
	return (max_index);
}

int	min_index(t_list *lst)
{
	int	min_index;

	min_index = lst->index;
	while (lst != NULL)
	{
		if (lst->index < min_index)
			min_index = lst->index;
		lst = lst->next;
	}
	return (min_index);
}

int	find_ind(int num_ind, t_list *lst)
{
	int	i;

	i = 1;
	while (lst->index != num_ind)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	find_el_a(t_list *lst_A, int ind_b)
{
	int	diff;
	int	index;

	diff = 0;
	index = 0;
	if (ind_b > max_index(lst_A) || ind_b < min_index(lst_A))
		index = min_index(lst_A);
	else
	{
		diff = max_index(lst_A) - ind_b;
		index = max_index(lst_A);
		while (lst_A != NULL)
		{
			if (lst_A->index - ind_b < diff && lst_A->index - ind_b > 0)
			{
				diff = lst_A->index - ind_b;
				index = lst_A->index;
			}
			lst_A = lst_A->next;
		}
	}
	return (index);
}

int	fals_keep_stack(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->keep_stack == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
