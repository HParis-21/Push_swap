#include "push_swap.h"

int	sorted_list(t_list *lst)
{
	while (lst->next != NULL)
	{
		if (lst->val > lst->next->val)
			return (0);
		lst = lst->next;
	}
	return (1);
}

static void	sort_three(t_list **lst_A)
{
	if (get_val(*lst_A, 1) > get_val(*lst_A, 2) && \
		get_val(*lst_A, 1) < get_val(*lst_A, 3))
		manip_s(lst_A, 'a');
	else if (get_val(*lst_A, 1) > get_val(*lst_A, 2) && get_val(*lst_A, 1) > \
		get_val(*lst_A, 3) && get_val(*lst_A, 2) > get_val(*lst_A, 3))
	{
		manip_s(lst_A, 'a');
		manip_rr(lst_A, 'a');
	}
	else if (get_val(*lst_A, 1) < get_val(*lst_A, 2) && \
		get_val(*lst_A, 1) < get_val(*lst_A, 3))
	{
		manip_rr(lst_A, 'a');
		manip_s(lst_A, 'a');
	}
	if (get_val(*lst_A, 1) > get_val(*lst_A, 2) && get_val(*lst_A, 1) > \
		get_val(*lst_A, 3) && get_val(*lst_A, 2) < get_val(*lst_A, 3))
		manip_r(lst_A, 'a');
	if (get_val(*lst_A, 1) < get_val(*lst_A, 2) && \
		get_val(*lst_A, 1) > get_val(*lst_A, 3))
		manip_rr(lst_A, 'a');
}

void	mini_sort(t_list **lst_A, t_list **lst_B, int size)
{
	int	len_a;

	len_a = size;
	if (len_a > 3)
	{
		while (len_a != 3)
		{
			while ((*lst_A)->index != min_index(*lst_A))
			{
				if (find_ind(min_index(*lst_A), *lst_A) <= 3)
					manip_r(lst_A, 'a');
				else
					manip_rr(lst_A, 'a');
			}
			if (sorted_list(*lst_A) == 1 && *lst_B == NULL)
				break ;
			manip_pb(lst_A, lst_B, 1);
			len_a--;
		}
	}
	if (sorted_list(*lst_A) == 0)
		sort_three(lst_A);
	while (stack_size(*lst_B) != 0)
		manip_pa(lst_A, lst_B, 1);
}
