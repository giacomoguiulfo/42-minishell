/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 11:59:22 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/12 10:25:16 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		msh_env_idx(t_dnarr *newenvp, char *var)
{
	int i;

	i = 0;
	while (i < newenvp->end)
	{
		if (newenvp->contents[i] && msh_envcmp(newenvp->contents[i], var)) // CANNOT BE STR STR
			return (i);
		i++;
	}
	return (-1);
}

int		msh_unsetenv(char **args, t_dnarr *newenvp, char **env)
{
	char	*lookup;
	if (!args[1])
		return (1);
	// TODO: Check Syntax...

	lookup = msh_get_env(env, args[1]);
	if (!lookup)
	{
		ft_printf("Variable %s doesn't exist\n", args[1]);
		return (1);
	}
	// ft_printf("Index: %d\n", msh_env_idx(newenvp, args[1]));
	free(dnarr_remove(newenvp, msh_env_idx(newenvp, args[1])));
	return (1);
}
