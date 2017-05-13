/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 19:24:50 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/13 02:46:24 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		msh_displ_env(t_dnarr *newenvp)
{
	int i;

	i = 0;
	while (i < newenvp->end)
	{
		if (newenvp->contents[i] != NULL)
			ft_putendl(newenvp->contents[i]);
		++i;
	}
	return (1);
}

int		msh_env_idx(t_dnarr *newenvp, char *var)
{
	int i;

	i = 0;
	while (i < newenvp->end)
	{
		if (newenvp->contents[i] && msh_envcmp(newenvp->contents[i], var))
			return (i);
		i++;
	}
	return (-1);
}

int		msh_unsetenv(char **args, t_dnarr *newenvp)
{
	char	*lookup;

	if (!args[1])
		return (1);
	lookup = msh_get_env(newenvp, args[1]);
	if (!lookup)
	{
		return (1);
	}
	free(dnarr_remove(newenvp, msh_env_idx(newenvp, args[1])));
	return (1);
}

int		msh_env_inval(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ISLOWER(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int		msh_setenv(char **args, t_dnarr *newenvp)
{
	char	*tmp;
	char	index;

	if (!args[1] || !args[2])
		return (1);
	if (ft_strchr(args[1], '=') || ft_strchr(args[2], '=') ||
		msh_env_inval(args[1]))
	{
		return (1);
	}
	ft_asprintf(&tmp, "%s=%s", args[1], args[2]);
	if (msh_get_env(newenvp, args[1]) != NULL)
	{
		index = msh_env_idx(newenvp, args[1]);
		free(dnarr_remove(newenvp, index));
		dnarr_set(newenvp, index, tmp);
		return (1);
	}
	dnarr_push(newenvp, tmp);
	return (1);
}
