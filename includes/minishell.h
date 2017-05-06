/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 01:53:12 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/06 00:05:38 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <limits.h>
# include <stdio.h>

# define MSH_RL_SIZ 1024

/*
** Main Functions
*/

int		msh_execute(char **args);

/*
** Commands
*/

int		msh_help(char **args);
int		msh_exit(char **args);
int		msh_cd(char **args);

/*
** Utils
*/

void	msh_put_arrow(void);

#endif
