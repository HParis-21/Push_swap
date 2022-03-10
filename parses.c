#include "push_swap.h"

static int	ft_atoi(const char *s)
{
	int			i;
	int			z;
	int long	res;

	i = 0;
	z = 1;
	res = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
		z = ',' - s[i++];
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i++] - '0');
		if ((res > 2147483647 && z == 1) || (res > 2147483648 && z == -1))
			return (0);
	}
	return ((int)res * z);
}

static int	ft_adigit(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+' || s[i] == ' ')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '\0' || s[i] == ' ')
		return (1);
	return (0);
}

static t_list	*test_dubl(t_list **arg)
{
	t_list	*dubl1;
	t_list	*dubl2;

	dubl1 = *arg;
	while (dubl1)
	{
		dubl2 = *arg;
		while (dubl2)
		{
			if (dubl2->val == dubl1->val && dubl2 != dubl1)
			{
				free_stack(arg);
				return (NULL);
			}
			dubl2 = dubl2->next;
		}
		dubl1 = dubl1->next;
	}
	return (*arg);
}

static int	ft_azero(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] == '0' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (0);
	else
		return (1);
}

t_list	*ft_parses(char **mass)
{
	t_list	*arg;
	int		nb;
	int		i;

	arg = NULL;
	i = 0;
	while (mass[i])
	{
		if (ft_adigit(mass[i]))
		{
			nb = ft_atoi(mass[i]);
			if (nb == 0 && ft_azero(mass[i]))
				return (free_stack(&arg));
			creat_stack(&arg, nb);
		}
		else
			return (free_stack(&arg));
		i++;
	}
	return (test_dubl(&arg));
}
