/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:27:54 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/27 20:49:37 by ankhabar         ###   ########.fr       */
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
void	sorting_troitsa(t_data *data);

/* error */
void	error(void);

/* ops */
void	ft_pb(t_data *data);
void	ft_pb(t_data *data);

#endif
