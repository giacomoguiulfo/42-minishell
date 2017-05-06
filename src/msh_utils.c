/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 23:53:37 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/06 00:08:37 by gguiulfo         ###   ########.fr       */
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
}
