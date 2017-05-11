/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 19:24:50 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/11 10:40:17 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		msh_displ_env(char **args, t_dnarr *newenvp)
{
	int i;

	i = 0;
	(void)args;
	while (newenvp->contents[i])
		ft_putendl(newenvp->contents[i++]);
	return (1);
}
