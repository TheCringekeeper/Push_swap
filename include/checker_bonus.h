/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:10:30 by ankhabar          #+#    #+#             */
/*   Updated: 2023/02/02 13:18:52 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
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

/* stack_utils */
int		is_sorted(t_data *data);
int		min_value_in_a(t_data *data);
int		min_index_in_a(t_data *data);

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
void	error(char *argv[], int ref);

/* bonus */
int		data_init_error(t_data *data, int argc, char *argv[], int ref);

#endif
