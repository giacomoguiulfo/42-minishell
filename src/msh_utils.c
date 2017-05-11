/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 23:53:37 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/11 10:21:04 by gguiulfo         ###   ########.fr       */
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
	while (len > 0 && cwd[len - 1] != '/')
		--len;
	/* Color Version */
		// ft_printf("%{bgreen}->  %{eoc}%{bcyan}%s%{eoc} ", cwd + len);
		// ft_printf("%{byellow} $>%{eoc} ");
	/* Non-color version */
		ft_printf("->  %s $> ", cwd + len);
	// TODO: Handle printing / when at root
}

char	*msh_get_env(char **envp, char *var)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (ft_strstr(envp[i], var))
			return (ft_strchr(envp[i], '=') + 1);
		i++;
	}
	return (NULL);
}
