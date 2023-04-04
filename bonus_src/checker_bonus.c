/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:03:38 by ankhabar          #+#    #+#             */
/*   Updated: 2023/04/04 16:11:36 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

static int	second_part_problem(t_data *data, char *buff)
{
	if (!ft_strcmp(buff, "pa\n"))
		ft_pa(data);
	else if (!ft_strcmp(buff, "pb\n"))
		ft_pb(data);
	else if (!ft_strcmp(buff, "ra\n"))
		ft_ra(data);
	else if (!ft_strcmp(buff, "rb\n"))
		ft_rb(data);
	else if (!ft_strcmp(buff, "rr\n"))
		ft_rr(data);
	else if (!ft_strcmp(buff, "rra\n"))
		ft_rra(data);
	else if (!ft_strcmp(buff, "rrb\n"))
		ft_rrb(data);
	else if (!ft_strcmp(buff, "rrr\n"))
		ft_rrr(data);
	else
		return (1);
	return (0);
}

static int	read_loop(t_data *data)
{
	char	*buff;

	buff = "";
	buff = get_next_line(0);
	while (buff)
	{
		if (!ft_strcmp(buff, "sa\n"))
			ft_sa(data);
		else if (!ft_strcmp(buff, "sb\n"))
			ft_sb(data);
		else if (!ft_strcmp(buff, "ss\n"))
			ft_ss(data);
		else if (buff[0] == 'r' || buff[0] == 'p')
		{
			if (second_part_problem(data, buff))
				return (free(buff), 0);
		}
		else
			return (free(buff), 0);
		free(buff);
		buff = get_next_line(0);
	}
	return (free(buff), 1);
}

static void	sorted_check(t_data *data, char *argv[], int ref)
{
	if (!read_loop(data))
	{
		free_stack(data);
		error(argv, ref);
	}
	if (is_sorted(data))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char *argv[])
{
	t_data	data;
	char	*tmp;
	int		ref;

	ref = 0;
	if (argc > 1)
	{
		if (argc == 2 && argv[1][0] && ft_strcmp(argv[1], "-2147483648"))
		{
			tmp = ft_strjoin("./push_swap ", argv[1]);
			argv = ft_split(tmp, ' ');
			free(tmp);
			ref = 1;
			argc = 0;
			while (argv && argv[argc])
				argc++;
		}
		if (data_init_error(&data, argc, argv, ref))
			return (1);
		sorted_check(&data, argv, ref);
		if (ref)
			free_argv(argv);
		free_stack(&data);
	}
	return (0);
}
