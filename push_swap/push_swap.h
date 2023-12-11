/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:44:33 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/11 14:15:59 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
int		ft_tablen(char **tab);
void	ft_free(char **tab);

char	**get_input(int argc, char **argv);
int		checkerror(char *input);
int		checkdup(t_stack *a);
void	debug_prntlst(t_stack *a, t_stack *b);

void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*setupstack(int argc, char **argv);
t_stack	*ft_lstnew(int value, int index, void *prev, void *next);
t_stack	*ft_lstdelelem(t_stack *elem);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);

t_stack	*swap(t_stack **a);
int		issorted(t_stack **a);
void	clear_index(t_stack **stack);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif