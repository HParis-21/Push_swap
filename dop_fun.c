#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i != n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int	get_val(t_list *stack, int pos)
{
	int	i;

	i = 1;
	while (stack && pos != i)
	{
		stack = stack->next;
		i++;
	}
	if (!stack)
		return (0);
	return (stack->val);
}

t_list	*get_list(t_list *lst, t_list *l_start, int index)
{
	if (lst == NULL)
		lst = l_start;
	while (!(index == lst->index))
	{
		lst = lst->next;
		if (lst == NULL)
			lst = l_start;
	}
	if (!lst)
		return (0);
	return (lst);
}

void	manip_rrr(t_list **lst_A, t_list **lst_B, int f)
{
	manip_rr(lst_A, 'p');
	manip_rr(lst_B, 'p');
	if (f)
		write(1, "rrr\n", 4);
}

void	manip_rrab(t_list **lst_A, t_list **lst_B, int f)
{
	manip_r(lst_A, 'p');
	manip_r(lst_B, 'p');
	if (f)
		write(1, "rr\n", 3);
}
