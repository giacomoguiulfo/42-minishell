/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 16:02:17 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/10 13:16:05 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		msh_exit(char **args)
{
	(void)args;
	return (0);
}

int		msh_help(char **args)
{
	ft_putstr("************************************************************\n");
	ft_putstr("*                        Minishell                         *\n");
	ft_putstr("* -------------------------------------------------------- *\n");
	ft_putstr("* Author:        gguiulfo                                  *\n");
	ft_putstr("* Contact:       gguiulfo@student.42.us.org                *\n");
	ft_putstr("* Description:   A simple shell made in C.                 *\n");
	ft_putstr("*                By Odin, by Thor! Use the shell!!!        *\n");
	ft_putstr("* Builtin Commands:                                        *\n");
	ft_putstr("*      echo -- cd -- setenv -- unsetenv -- env -- exit     *\n");
	ft_putstr("************************************************************\n");
	(void)args;
	return (1);
}
