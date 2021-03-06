/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 23:53:37 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/13 01:42:36 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	msh_put_arrow(void)
{
	int		len;
	char	*cwd;
	char	buff[PATH_MAX + 1];

	cwd = getcwd(buff, PATH_MAX + 1);
	len = ft_strlen(cwd);
	if (len == 1 && cwd[0] == '/')
	{
		ft_printf("%{bgreen}->%{eoc} %{bcyan}/%{eoc} ");
		ft_printf("%{byellow} $>%{eoc} ");
		return ;
	}
	while (len > 0 && cwd[len - 1] != '/')
		--len;
	ft_printf("%{bgreen}->%{eoc} %{bcyan}%s%{eoc} ", cwd + len);
	ft_printf("%{byellow}$>%{eoc} ");
}

int		msh_envcmp(char *env, char *lookup)
{
	char	*ret;
	int		i;

	i = 0;
	while (env[i] != '=' && env[i] != '\0')
		i++;
	if (env[i] == '\0')
		return (0);
	ret = ft_strndup(env, i);
	if (!ft_strcmp(ret, lookup))
	{
		free(ret);
		return (1);
	}
	free(ret);
	return (0);
}

char	*msh_get_env(t_dnarr *newenvp, char *look)
{
	int i;

	i = -1;
	while (++i < newenvp->end)
	{
		if (newenvp->contents[i] == NULL)
			continue ;
		if (msh_envcmp(newenvp->contents[i], look))
			return (ft_strchr(newenvp->contents[i], '=') + 1);
	}
	return (NULL);
}

char	**msh_cp_env(t_dnarr *newenvp)
{
	char	**ret;
	int		i;
	int		size;

	i = -1;
	size = 0;
	while (++i < newenvp->end)
		if (newenvp->contents[i] != NULL)
			size++;
	ret = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	i = -1;
	size = 0;
	while (++i < newenvp->end)
	{
		if (newenvp->contents[i] != NULL)
			ret[size++] = newenvp->contents[i];
	}
	return (ret);
}

char	*msh_check_bin(char *executable, char *path)
{
	struct stat	statbuf;
	char		*ret;

	ft_asprintf(&ret, "%s/%s", path, executable);
	if (lstat(ret, &statbuf) == -1)
	{
		free(ret);
		return (NULL);
	}
	else if ((statbuf.st_mode & S_IFMT) == S_IFREG)
		return (ret);
	return (NULL);
}
