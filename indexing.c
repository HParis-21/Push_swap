#include "push_swap.h"

static void	sort_mas(int *str, int si)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i < si)
	{
		tmp = str[i];
		j = i - 1;
		while (j >= 0 && str[j] > tmp)
		{
			str[j + 1] = str[j];
			j--;
		}
		str[j + 1] = tmp;
		i++;
	}
}

static void	index_list(t_list *lst, int *str, int si)
{
	int	i;

	while (lst)
	{
		i = 0;
		while (i < si)
		{
			if (lst->val == str[i])
			{
				lst->index = i;
				break ;
			}
			i++;
		}
		lst = lst->next;
	}
}

void	index_s(t_list *lst, int si)
{
	t_list	*tmp;
	int		*mass;
	int		i;

	tmp = lst;
	mass = malloc(sizeof(int) * si);
	if (!mass)
		ft_error();
	i = 0;
	while (i < si)
	{
		mass[i++] = lst->val;
		lst = lst->next;
	}
	sort_mas(mass, si);
	index_list(tmp, mass, si);
	free(mass);
}
