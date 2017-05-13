/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:58:00 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/13 04:07:53 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	msh_chenv_pwd(t_dnarr *newenvp, char *oldcwd)
{
	char buff[PATH_MAX + 1];
	char *newcwd;
	char *tmp;
	char **args;

	ft_asprintf(&tmp, "NULL OLDPWD %s", oldcwd);
	args = ft_strsplit(tmp, ' ');
	msh_setenv(args, newenvp);
	ft_free_map(args);
	free(tmp);
	newcwd = getcwd(buff, PATH_MAX + 1);
	ft_asprintf(&tmp, "NULL PWD %s", newcwd);
	args = ft_strsplit(tmp, ' ');
	msh_setenv(args, newenvp);
	ft_free_map(args);
	free(tmp);
}

void	msh_cd_ext(char **args, t_dnarr *newenvp, char *cwd)
{
	if (args[1][0] == '-' && args[1][1] == '\0')
	{
		if (chdir(msh_get_env(newenvp, "OLDPWD")) != 0)
			ft_dprintf(2, "msh: unable to change directory\n");
		else
		{
			msh_chenv_pwd(newenvp, cwd);
			ft_putendl(msh_get_env(newenvp, "OLDPWD"));
		}
	}
	else if (args[1][0] == '$' && args[1][1] != '\0')
	{
		if (chdir(msh_get_env(newenvp, &args[1][1])) != 0)
			ft_dprintf(2, "msh: unable to change directory\n");
		else
			msh_chenv_pwd(newenvp, cwd);
	}
	else
	{
		if (chdir(args[1]) != 0)
			ft_dprintf(2, "msh: unable to change directory\n");
		else
			msh_chenv_pwd(newenvp, cwd);
	}
}

int		msh_cd(char **args, t_dnarr *newenvp)
{
	char *tmp;
	char buff[PATH_MAX + 1];
	char *cwd;

	cwd = getcwd(buff, PATH_MAX + 1);
	if (args[1] == NULL)
	{
		if (chdir(msh_get_env(newenvp, "HOME")) != 0)
			ft_dprintf(2, "msh: unable to change directory\n");
		else
			msh_chenv_pwd(newenvp, cwd);
	}
	else if (args[1][0] == '~')
	{
		ft_asprintf(&tmp, "%s/%s", msh_get_env(newenvp, "HOME"), &args[1][1]);
		if (chdir(tmp) != 0)
			ft_dprintf(2, "msh: unable to change directory\n");
		else
			msh_chenv_pwd(newenvp, cwd);
		free(tmp);
	}
	else
		msh_cd_ext(args, newenvp, cwd);
	return (1);
}
