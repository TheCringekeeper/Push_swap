/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:27:54 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/28 17:06:40 by ankhabar         ###   ########.fr       */
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

/* utils */
int		ft_strcmp(char *s1, char *s2);

/* parsing */
int		parsing_error(char *argv[]);
int		has_doubles(int *stack, int stack_len);

/* sorting */
int		is_sorted(t_data *data);
void	sorting_izi(t_data *data);
void	sorting_krab(t_data *data);

/* lst_utils */
int		ft_max(t_data *data);
int		max_index_in_a(t_data *data);

/* ops */
void	ft_pa(t_data *data);
void	ft_pb(t_data *data);
void	ft_sa(t_data *data);
void	ft_sb(t_data *data);
void	ft_ss(t_data *data);

/* ops_rr */
void	ft_ra(t_data *data);
void	ft_rb(t_data *data);

/* ops_rrr */
void	ft_rra(t_data *data);

/* free */
void	free_stack(t_data *data);

/* error */
void	error(void);

#endif
