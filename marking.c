#include "push_swap.h"

static int	start_pos(int *mass, int n)
{
	int	i;
	int	res;
	int	max;

	i = 0;
	res = 0;
	max = mass[i];
	while (i < n)
	{
		if (max < mass[i])
		{
			max = mass[i];
			res = i;
		}
		i++;
	}
	return (res);
}

static int	*mark_great(t_list *lst, int si)
{
	t_list	*a;
	int		*great;
	int		i;

	a = lst;
	great = malloc(sizeof(int) * si);
	if (!great)
		ft_error();
	i = 0;
	while (a)
	{
		great[i++] = seq_elem(a);
		a = a->next;
	}
	return (great);
}

static int	*mark_ind(t_list *lst, int si)
{
	t_list	*a;
	int		*ind;
	int		i;

	a = lst;
	ind = malloc(sizeof(int) * si);
	if (!ind)
		ft_error();
	i = 0;
	while (a)
	{
		ind[i++] = ind_elem(a, lst);
		a = a->next;
	}
	return (ind);
}

void	great_than(t_list *lst, t_stat *sist, int si)
{
	int	*str_one;
	int	*str_ind;
	int	i;

	str_one = mark_great(lst, si);
	str_ind = mark_ind(lst, si);
	if (str_one[start_pos(str_one, si)] > str_ind[start_pos(str_ind, si)])
	{
		sist->max_posl = str_one[start_pos(str_one, si)];
		i = start_pos(str_one, si);
		sist->type_mark = 1;
	}
	else
	{
		sist->max_posl = str_ind[start_pos(str_ind, si)];
		i = start_pos(str_ind, si);
		sist->type_mark = 2;
	}
	while (i--)
		lst = lst->next;
	sist->mark_up = lst->index;
	free(str_ind);
	free(str_one);
}
