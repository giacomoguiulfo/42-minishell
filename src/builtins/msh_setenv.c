/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 10:40:50 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/11 10:46:39 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		msh_setenv(char **args, t_dnarr *newenvp)
{
	char *tmp;

	(void)args;
	(void)newenvp;
	if (!args[1] || !args[2])
		return (1);
	ft_asprintf(&tmp, "%s=%s", args[1], args[2]);
	dnarr_push(newenvp, tmp);
	return (1);
}
