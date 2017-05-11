/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 19:24:50 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/11 15:23:18 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		msh_displ_env(char **args, t_dnarr *newenvp)
{
	int i;

	i = 0;
	(void)args;
	while (i < newenvp->end)
	{
		if (newenvp->contents[i] != NULL)
			ft_putendl(newenvp->contents[i]);
		++i;
	}
	return (1);
}
