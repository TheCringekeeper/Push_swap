/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:27:54 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/31 21:23:00 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int	*stack;
	int	stack_size;
	int	index_a;
}		t_data;

/* main */
int		*get_stack(int stack_size, char *argv[]);

/* parsing */
int		parsing_error(char *argv[]);
int		has_doubles(int *stack, int stack_len);

/* quicksort */
void	ft_quicksort(int *array, int l_pos, int r_pos);

/* sorting1 */
void	sorting_smol(t_data *data);
void	sorting_3(t_data *data);
void	sorting_4(t_data *data);
void	sorting_5(t_data *data);

/* sorting2 */
void	sorting_everything(t_data *data);

/* cost */
int		find_cost(t_data *data, int i);
int		ft_find_most_optimal(int cost_ra, int cost_rb, int cost_rra,
			int cost_rrb);

/* cost_utils */
int		ft_cost_ra(t_data *data, int value);
int		ft_cost_rra(t_data *data, int value);
int		ft_cost_rb(t_data *data, int value);
int		ft_cost_rrb(t_data *data, int value);

/* do_ops */
void	do_ops(t_data *data, int i);

/* final */
void	final_rotations(t_data *data);

/* stack_utils */
int		is_sorted(t_data *data);
int		min_index_in_a(t_data *data);
int		get_max(int a, int b);

/* ops */
void	ft_pa(t_data *data);
void	ft_pb(t_data *data);
void	ft_sa(t_data *data);
void	ft_sb(t_data *data);
void	ft_ss(t_data *data);

/* ops_rr */
void	ft_ra(t_data *data);
void	ft_rb(t_data *data);
void	ft_rr(t_data *data);

/* ops_rrr */
void	ft_rra(t_data *data);
void	ft_rrb(t_data *data);
void	ft_rrr(t_data *data);

/* free */
void	free_stack(t_data *data);
void	free_argv(char *argv[]);

/* error */
void	error(void);

#endif
