/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 10:40:50 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/12 09:50:45 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		msh_setenv(char **args, t_dnarr *newenvp, char **env)
{
	char *tmp;

	(void)args;
	(void)newenvp;
	if (!args[1] || !args[2])
		return (1);
	// TODO: Handle error syntax cases:
	// TODO: Check env vaiables before adding new ones

	if (msh_get_env(env, args[1]) != NULL)
	{
		ft_dprintf(2, "variable %s already exist\n", args[1]);
		return (1);
	}
	ft_asprintf(&tmp, "%s=%s", args[1], args[2]);
	dnarr_push(newenvp, tmp);
	return (1);
}
