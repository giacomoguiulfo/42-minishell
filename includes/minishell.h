/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 01:53:12 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/13 07:17:30 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <limits.h>
# include <sys/stat.h>
# include <stdio.h>

# define MSH_RL_SIZ 1024

/*
** Main Functions
*/

int		msh_execute(char **args, t_dnarr *newenvp);

/*
** Builtins
*/

int		msh_exit(char **args);
int		msh_cd(char **args, t_dnarr *newenvp);
int		msh_echo(char **args, t_dnarr *newenvp);
int		msh_displ_env(t_dnarr *newenvp);
int		msh_setenv(char **args, t_dnarr *newenvp);
int		msh_unsetenv(char **args, t_dnarr *newenvp);

/*
** Utils
*/

void	msh_put_arrow(void);
char	**msh_strsplit(char *line);
char	*msh_check_bin(char *executable, char *path);
char	*msh_get_env(t_dnarr *newenvp, char *look);
int		msh_envcmp(char *env, char *lookup);
char	**msh_cp_env(t_dnarr *newenvp);
int		msh_env_idx(t_dnarr *newenvp, char *var);
int		msh_env_inval(char *str);

/*
** Extras
*/

int		msh_help(char **args);
void	echo_esc_chr(char esc);

#endif
