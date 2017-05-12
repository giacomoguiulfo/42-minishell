/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:58:00 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/12 11:22:19 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		msh_cd(char **args, t_dnarr *newenvp, char **env)
{
	char *tmp;
	(void)newenvp;
	if (args[1] == NULL)
	{
		if (chdir(msh_get_env(env, "HOME")) != 0) // Check msh_get_env before?
		{
			ft_dprintf(2, "Error: unable to change directory\n");
		}
	}
	else if (args[1][0] == '~')
	{
		// if home
		ft_asprintf(&tmp, "%s/%s", msh_get_env(env, "HOME"), &args[1][1]);
		if (chdir(tmp) != 0)
		{
			ft_dprintf(2, "Error: unable to change directory\n");
		}
		free(tmp);
	}
	else if (args[1][0] == '-' && args[1][1] == '\0')
	{
		if (chdir(msh_get_env(env, "OLDPWD")) != 0)
		{
			ft_dprintf(2, "Error: unable to change directory\n");
		}
		ft_putendl(msh_get_env(env, "OLDPWD"));
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			ft_dprintf(2, "Error: unable to change directory\n");
		}
	}
	return (1);
}
