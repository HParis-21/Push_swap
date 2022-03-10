#include "push_swap.h"

void	manip_ss(t_list **lst_A, t_list **lst_B)
{
	manip_s(lst_A, 'p');
	manip_s(lst_B, 'p');
}

static void	ft_command(t_list **lst_A, t_list **lst_B, char *line)
{
	if (ft_strncmp(line, "sa", 2) == 0)
		manip_s(lst_A, 'p');
	else if (ft_strncmp(line, "sb", 2) == 0)
		manip_s(lst_B, 'p');
	else if (ft_strncmp(line, "ss", 2) == 0)
		manip_ss(lst_A, lst_B);
	else if (ft_strncmp(line, "pa", 2) == 0)
		manip_pa(lst_A, lst_B, 0);
	else if (ft_strncmp(line, "pb", 2) == 0)
		manip_pb(lst_A, lst_B, 0);
	else if (ft_strncmp(line, "ra", 2) == 0)
		manip_r(lst_A, 'p');
	else if (ft_strncmp(line, "rb", 2) == 0)
		manip_r(lst_B, 'p');
	else if (ft_strncmp(line, "rra", 3) == 0)
		manip_rr(lst_A, 'p');
	else if (ft_strncmp(line, "rrb", 3) == 0)
		manip_rr(lst_B, 'p');
	else if (ft_strncmp(line, "rrr", 3) == 0)
		manip_rrr(lst_A, lst_B, 0);
	else if (ft_strncmp(line, "rr", 2) == 0)
		manip_rrab(lst_A, lst_B, 0);
	else
		write(2, "Error\n", 7);
}

int	get_next_line(char **line)
{
	char	buf[10000];
	int		byte;
	int		i;

	i = 0;
	if ((read(0, &buf[i], 0) < 0) || !(line))
		return (-1);
	byte = read(0, &buf[i], 1);
	while (byte > 0 && buf[i] != '\n')
		byte = read(0, &buf[++i], 1);
	buf[i] = '\0';
	if (byte != -1)
	{
		*line = malloc(sizeof(char) * i);
		if (*line)
		{
			i = -1;
			while (buf[++i])
				(*line)[i] = buf[i];
			(*line)[i] = '\0';
		}
	}
	if (byte > 0)
		return (1);
	return (byte);
}

static void	ft_read(t_list **lst_A, t_list **lst_B)
{
	char	*line;

	line = NULL;
	while (get_next_line(&line))
	{
		ft_command(lst_A, lst_B, line);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_list	*lst_A;
	t_list	*lst_B;
	char	**mass;

	lst_B = NULL;
	lst_A = NULL;
	if (argc < 2)
		return (ft_error());
	if (argc == 2)
		mass = ft_split(argv[1], ' ');
	if (argc > 2)
		mass = ++argv;
	lst_A = ft_parses(mass);
	if (!lst_A)
		return (ft_error());
	ft_read(&lst_A, &lst_B);
	if (lst_B == NULL && sorted_list(lst_A))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
