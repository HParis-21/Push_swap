#include "push_swap.h"

static void	use_cmd_rr(t_list **lst_A, t_list **lst_B, t_stat *sist)
{
	int		el_a;
	int		start_b;
	int		steps_b;
	int		steps_a;

	start_b = best_step_pa(*lst_A, *lst_B, sist);
	el_a = find_el_a(*lst_A, start_b);
	steps_b = find_ind(start_b, *lst_B) - 1;
	steps_a = find_ind(el_a, *lst_A) - 1;
	if (sist->b_size >= sist->a_size && steps_a > steps_b)
		steps_a = steps_a - steps_b;
	else if (sist->b_size >= sist->a_size && steps_a <= steps_b)
		steps_a = 0;
	if (sist->a_size > sist->b_size && steps_b > steps_a)
		steps_b = steps_b - steps_a;
	else if (sist->a_size > sist->b_size && steps_b <= steps_a)
		steps_b = 0;
	if ((sist->b_size >= sist->a_size \
	&& steps_a <= sist->a_size - find_ind(el_a, *lst_A) + 1) \
	|| (sist->a_size > sist->b_size \
	&& steps_b <= sist->b_size - find_ind(start_b, *lst_B) + 1))
		while ((*lst_A)->index != el_a && (*lst_B)->index != start_b)
			manip_rrab(lst_A, lst_B, 1);
}

static void	use_cmd_rrr(t_list **lst_A, t_list **lst_B, t_stat *sist)
{
	int		el_a;
	int		start_b;
	int		steps_b;
	int		steps_a;

	start_b = best_step_pa(*lst_A, *lst_B, sist);
	el_a = find_el_a(*lst_A, start_b);
	steps_b = sist->b_size - find_ind(start_b, *lst_B) + 1;
	steps_a = sist->a_size - find_ind(el_a, *lst_A) + 1;
	if (sist->a_size > sist->b_size && steps_b > steps_a)
		steps_b = steps_b - steps_a;
	else if (sist->a_size > sist->b_size && steps_b <= steps_a)
		steps_b = 0;
	if (sist->b_size >= sist->a_size && steps_a > steps_b)
		steps_a = steps_a - steps_b;
	else if (sist->b_size >= sist->a_size && steps_a <= steps_b)
		steps_a = 0;
	if ((sist->a_size > sist->b_size \
	&& steps_b <= find_ind(start_b, *lst_B) - 1) \
	|| (sist->b_size > sist->a_size && steps_a <= find_ind(el_a, *lst_A) - 1))
		while ((*lst_A)->index != el_a && (*lst_B)->index != start_b)
			manip_rrr(lst_A, lst_B, 1);
}

static void	manip_stack_a(t_list **lst_A, int el_a, int a_size)
{
	while ((*lst_A)->index != el_a)
	{
		if (find_ind(el_a, *lst_A) <= a_size / 2 + a_size % 2)
			manip_r(lst_A, 'a');
		if (find_ind(el_a, *lst_A) > a_size / 2 + a_size % 2)
			manip_rr(lst_A, 'a');
	}
}

static void	manip_stack_b(t_list **lst_B, int start_b, int b_size)
{
	while ((*lst_B)->index != start_b)
	{
		if (find_ind(start_b, *lst_B) <= b_size / 2 + b_size % 2)
			manip_r(lst_B, 'b');
		if (find_ind(start_b, *lst_B) > b_size / 2 + b_size % 2)
			manip_rr(lst_B, 'b');
	}
}

void	big_sort(t_list **lst_A, t_list **lst_B, t_stat *sist)
{
	int	start_b;
	int	el_a;

	while (sist->b_size > 0)
	{
		start_b = best_step_pa(*lst_A, *lst_B, sist);
		el_a = find_el_a(*lst_A, start_b);
		if ((sist->b_size >= sist->a_size \
		&& find_ind(start_b, *lst_B) <= sist->b_size / 2 + sist->b_size % 2) \
		|| (sist->a_size > sist->b_size \
		&& find_ind(el_a, *lst_A) <= sist->a_size / 2 + sist->a_size % 2))
			use_cmd_rr(lst_A, lst_B, sist);
		if ((sist->b_size >= sist->a_size \
		&& find_ind(start_b, *lst_B) > sist->b_size / 2 + sist->b_size % 2) \
		|| (sist->a_size > sist->b_size \
		&& find_ind(el_a, *lst_A) > sist->a_size / 2 + sist->a_size % 2))
			use_cmd_rrr(lst_A, lst_B, sist);
		manip_stack_a(lst_A, el_a, sist->a_size);
		manip_stack_b(lst_B, start_b, sist->b_size);
		manip_pa(lst_A, lst_B, 1);
		sist->a_size = stack_size(*lst_A);
		sist->b_size = stack_size(*lst_B);
	}
	manip_stack_a(lst_A, 0, sist->a_size);
}
