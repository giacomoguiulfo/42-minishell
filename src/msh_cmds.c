/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 21:57:23 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/06 00:46:11 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

extern char **environ; // TODO: Check this...

// TODO: I can't use global variables :(
char	*builtin_str[] = {
	"cd",
	"help",
	"exit"
};

// TODO: I can't use global variables :(
int		(*builtin_func[]) (char **) = {
	&msh_cd,
	&msh_help,
	&msh_exit
};

int		msh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

int		msh_cd(char **args)
{
	if (args[1] == NULL)
	{
		ft_dprintf(2, "minishell: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			ft_dprintf(2, "Error: unable to change directory\n");
		}
	}
	return (1);
}

int		msh_help(char **args)
{
	int i;
	int total;

	i = -1;
	total = msh_num_builtins();
	ft_putstr("************************************************************\n");
	ft_putstr("*                        Minishell                         *\n");
	ft_putstr("* -------------------------------------------------------- *\n");
	ft_putstr("* Author:        gguiulfo                                  *\n");
	ft_putstr("* Contact:       gguiulfo@student.42.us.org                *\n");
	ft_putstr("* Description:   A simple shell made in C.                 *\n");
	ft_putstr("*                By Odin, by Thor! Use the shell!!!        *\n");
	ft_putstr("* Builtin Commands:                                        *\n");
	while (++i < total)
		ft_printf("* %2d. %-53s*\n", i, builtin_str[i]);
	ft_putstr("************************************************************\n");
	(void)args;
	return (1);
}

int		msh_exit(char **args)
{
	(void)args;
	return (0);
}

int		msh_launch(char **args)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;
	// char	*cmd;

	pid = fork();
	if (pid == 0)
	{
		// ft_asprintf(&cmd, "/bin/%s", args[0]); // TODO: This is not good because I can't free cmd, I think...
		// if (execve(cmd, args, NULL) == -1) // This one is the rigth one
		if (execvp(args[0], args) == -1) // Not this one...
		{
			// ft_dprintf(2, "msh: command not found: %s\n", cmd);
			ft_dprintf(2, "msh: command not found: %s\n", args[0]); // Same here
		}
		exit(EXIT_FAILURE); // TODO: We have to free stuff before exiting... or not?
	}
	else if (pid < 0)
		ft_dprintf(2, "msh: unable to fork the process\n");
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}

int		msh_execute(char **args)
{
	int i;
	int total;

	if (args[0] == NULL)
		return (1);
	i = 0;
	total = msh_num_builtins();
	while (i < total)
	{
		if (ft_strcmp(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(args));
		i++;
	}
	return (msh_launch(args));
}
