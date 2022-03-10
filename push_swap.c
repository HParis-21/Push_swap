#include "push_swap.h"

static void	init(t_stat *sist)
{
	sist->max_posl = 0;
	sist->mark_up = 0;
	sist->type_mark = 0;
}

static int	start_sort(t_list **lst_A, t_list **lst_B, t_stat *sist)
{
	if (sist->a_size == 2 && sorted_list(*lst_A) == 0)
		manip_s(lst_A, 'a');
	if (sist->a_size > 2 && sist->a_size < 6 && sorted_list(*lst_A) == 0)
		mini_sort(lst_A, lst_B, sist->a_size);
	if (sorted_list(*lst_A))
		return (0);
	while (fals_keep_stack((*lst_A)))
	{
		if ((*lst_A)->keep_stack == 0)
			manip_pb(lst_A, lst_B, 1);
		else
			manip_r(lst_A, 'a');
	}
	sist->a_size = stack_size(*lst_A);
	sist->b_size = stack_size(*lst_B);
	big_sort(lst_A, lst_B, sist);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_A;
	t_list	*stack_B;
	t_stat	sist;
	char	**mass;

	stack_B = NULL;
	stack_A = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		mass = ft_split(argv[1], ' ');
	if (argc > 2)
		mass = ++argv;
	stack_A = ft_parses(mass);
	if (!stack_A)
		return (ft_error());
	init(&sist);
	sist.a_size = stack_size(stack_A);
	index_s(stack_A, sist.a_size);
	great_than(stack_A, &sist, sist.a_size);
	mark_keep(&stack_A, &sist);
	return (start_sort(&stack_A, &stack_B, &sist));
}
