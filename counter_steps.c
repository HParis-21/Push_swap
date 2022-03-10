#include "push_swap.h"

static int	move_up(int order_b, t_list *lst_A, t_list *lst_B, t_stat *sist)
{
	int	a_ind;
	int	steps_b;
	int	steps_a;
	int	len_a;
	int	len_b;

	len_a = sist->a_size;
	len_b = sist->b_size;
	a_ind = find_el_a(lst_A, order_b);
	steps_b = find_ind(order_b, lst_B) - 1;
	steps_a = find_ind(a_ind, lst_A) - 1;
	if (len_b >= len_a && steps_a > steps_b)
		steps_a = steps_a - steps_b;
	else if (len_b >= len_a && steps_a <= steps_b)
		steps_a = 0;
	if (len_b >= len_a && steps_a > len_a - find_ind(a_ind, lst_A) + 1)
		steps_a = len_a - find_ind(a_ind, lst_A) + 1;
	if (len_a > len_b && steps_b > steps_a)
		steps_b = steps_b - steps_a;
	else if (len_a > len_b && steps_b <= steps_a)
		steps_b = 0;
	if (len_a > len_b && steps_b > len_b - find_ind(order_b, lst_B) + 1)
		steps_b = len_b - find_ind(order_b, lst_B) + 1;
	return (steps_b + steps_a + 1);
}

static int	move_down(int b_ind, t_list *lst_A, t_list *lst_B, t_stat *sist)
{
	int	a_ind;
	int	steps_b;
	int	steps_a;
	int	len_a;
	int	len_b;

	len_a = sist->a_size;
	len_b = sist->b_size;
	a_ind = find_el_a(lst_A, b_ind);
	steps_b = len_b - find_ind(b_ind, lst_B) + 1;
	steps_a = len_a - find_ind(a_ind, lst_A) + 1;
	if (len_b >= len_a && steps_a > steps_b)
		steps_a = steps_a - steps_b;
	else if (len_b >= len_a && steps_a <= steps_b)
		steps_a = 0;
	if (len_b >= len_a && steps_a > find_ind(a_ind, lst_A) - 1)
		steps_a = find_ind(a_ind, lst_A) - 1;
	if (len_a > len_b && steps_b > steps_a)
		steps_b = steps_b - steps_a;
	else if (len_a > len_b && steps_b <= steps_a)
		steps_b = 0;
	if (len_a > len_b && steps_b > find_ind(b_ind, lst_B) - 1)
		steps_b = find_ind(b_ind, lst_B) - 1;
	return (steps_b + steps_a + 1);
}

static int	num_of_step(int b_ind, t_list *lst_A, t_list *lst_B, t_stat *sist)
{
	int		el_a;
	int		len_a;
	int		len_b;
	int		steps;

	len_a = sist->a_size;
	len_b = sist->b_size;
	el_a = find_el_a(lst_A, b_ind);
	if ((len_b >= len_a && find_ind(b_ind, lst_B) <= len_b / 2 + len_b % 2) \
	|| (len_a > len_b && find_ind(el_a, lst_A) <= len_a / 2 + len_a % 2))
		steps = move_up(b_ind, lst_A, lst_B, sist);
	if ((len_b >= len_a && find_ind(b_ind, lst_B) > len_b / 2 + len_b % 2) \
	|| (len_a > len_b && find_ind(el_a, lst_A) > len_a / 2 + len_a % 2))
		steps = move_down(b_ind, lst_A, lst_B, sist);
	return (steps);
}

int	best_step_pa(t_list *lst_A, t_list *lst_B, t_stat *sist)
{
	int		step;
	int		newstep;
	int		b_ind;
	t_list	*tmp;

	b_ind = lst_B->index;
	tmp = lst_B->next;
	step = num_of_step(b_ind, lst_A, lst_B, sist);
	while (tmp != NULL)
	{
		newstep = num_of_step(tmp->index, lst_A, lst_B, sist);
		if (newstep < step || (newstep == step && b_ind > tmp->index))
		{
			step = newstep;
			b_ind = tmp->index;
		}
		tmp = tmp->next;
	}
	return (b_ind);
}
