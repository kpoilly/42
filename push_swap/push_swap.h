/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:44:33 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/03 23:48:58 by marvin           ###   ########.fr       */
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

void	push_swap(int *a);
int		ft_atoi(const char *nptr);
int		checkerror(char *input);

t_stack	*setupstack(int argc, char **argv);
t_stack	*checkdup(t_stack *a);
void	debug_prntlst(t_stack *lst);

void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstdelelem(t_stack *elem);
t_stack	*ft_lstlast(t_stack *lst);

t_stack	*swap(t_stack **a);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

#endif