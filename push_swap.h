#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				val;
	int				index;
	int				keep_stack;
	struct s_list	*next;
}				t_list;

typedef struct s_stat
{
	int			a_size;
	int			b_size;
	int			mark_up;
	int			type_mark;
	int			max_posl;
}				t_stat;

t_list	*ft_parses(char **mass);
char	**ft_split(char const *s, char c);
void	*free_stack(t_list **top);
void	creat_stack(t_list **arg, int val);
int		ft_error(void);
void	manip_s(t_list **lst, char name);
void	manip_ss(t_list **lst_A, t_list **lst_B);
void	manip_r(t_list **lst, char name);
void	manip_rr(t_list **lst, char name);
void	manip_pa(t_list **lst_A, t_list **lst_B, int f);
void	manip_pb(t_list **lst_A, t_list **lst_B, int f);
void	manip_rrr(t_list **lst_A, t_list **lst_B, int f);
void	manip_rrab(t_list **lst_A, t_list **lst_B, int f);
int		stack_size(t_list *list);
void	index_s(t_list *lst, int si);
int		seq_elem(t_list *lst);
int		ind_elem(t_list *lst, t_list *l_start);
void	one_mar_keep(t_list *lst);
void	two_mar_keep(t_list *lst, t_list *l_start);
void	mark_keep(t_list **lst, t_stat *sist);
void	great_than(t_list *lst, t_stat *sist, int si);
t_list	*get_list(t_list *lst, t_list *l_start, int index);
int		get_val(t_list *stack, int pos);
void	big_sort(t_list **lst_A, t_list **lst_B, t_stat *sist);
int		sorted_list(t_list *lst);
void	mini_sort(t_list **lst_A, t_list **lst_B, int size);
int		best_step_pa(t_list *lst_A, t_list *lst_B, t_stat *sist);
int		max_index(t_list *lst);
int		min_index(t_list *lst);
int		find_ind(int num_ind, t_list *lst);
int		find_el_a(t_list *lst_A, int ind_b);
int		fals_keep_stack(t_list *lst);
int		get_next_line(char **line);
int		ft_strncmp(const char *s1, const char *s2, int n);
#endif //PUSH_SWAP_H