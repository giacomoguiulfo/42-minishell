/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 21:57:23 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/11 11:25:14 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		msh_launch(char **args, char **envp)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;
	char	*cmd;
	char	**arr;
	int		i = 0;
	// for (int i = 0; envp[i]; i++)
	// 	ft_printf("%s\n", envp[i]);
	pid = fork();
	if (pid == 0)
	{
		arr = ft_strsplit(msh_get_env(envp, "PATH"), ':');
		ft_asprintf(&cmd, "%s/%s", arr[i++], args[0]);
		// ft_asprintf(&cmd, "/bin/%s", args[0]); // TODO: This is not good because I can't free cmd, I think...
		// TODO: Check access of paths for each path like this -> access(arr[i], X_OK)
		while (execve(cmd, args, envp) == -1)
		{
			ft_printf("cmd: [%s]\n", cmd);
			ft_printf("arr[%d]: [%s]\n", i, arr[i]);
			free(cmd);
			if (arr[i])
				ft_asprintf(&cmd, "%s/%s", arr[i++], args[0]);
			else
			{
				break ;
			}
		}
		if (execve(args[0], args, envp) == -1)
		// if (execve(args[0], args, envp) == -1) // This one is the rigth one
		// if (execvp(args[0], args) == -1) // Not this one...
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

int		msh_run_builtins(char **args, t_dnarr *newenvp)
{
	if (!ft_strcmp(args[0], "cd"))
		return (msh_cd(args));
	else if (!ft_strcmp(args[0], "echo"))
		return (msh_echo(args, newenvp));
	else if (!ft_strcmp(args[0], "exit") || !ft_strcmp(args[0], "EXIT"))
		return (msh_exit(args));
	else if (!ft_strcmp(args[0], "help"))
		return (msh_help(args));
	else if (!ft_strcmp(args[0], "env"))
		return (msh_displ_env(args, newenvp));
	else if (!ft_strcmp(args[0], "setenv"))
		return (msh_setenv(args, newenvp));
	return (-1);
}

int		msh_execute(char **args, t_dnarr *newenvp, char **envp)
{
	int ret;

	if (args[0] == NULL)
		return (1);
	ret = msh_run_builtins(args, newenvp);
	if (ret != -1)
		return (ret);
	return (msh_launch(args, envp)); // TODO: Handle make in the shell
}
