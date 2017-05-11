/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 01:53:12 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/11 10:42:29 by gguiulfo         ###   ########.fr       */
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

int		msh_execute(char **args, t_dnarr *newenvp, char **envp);

/*
** Builtins
*/

int		msh_help(char **args);
int		msh_exit(char **args);
int		msh_cd(char **args);
int		msh_echo(char **args, t_dnarr *newenvp);
int		msh_displ_env(char **args, t_dnarr *newenvp);
int		msh_setenv(char **args, t_dnarr *newenvp);

/*
** Utils
*/

void	msh_put_arrow(void);
char	**msh_strsplit(char *line);
char	*msh_get_env(char **envp, char *var);

#endif
