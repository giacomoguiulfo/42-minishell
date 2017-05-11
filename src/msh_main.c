/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 03:49:17 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/11 15:36:18 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*msh_read_line(void)
{
	int		c;
	int		bufsize;
	int		position;
	char	*buffer;

	position = 0;
	bufsize = MSH_RL_SIZ;
	buffer = (char *)malloc(sizeof(char) * bufsize);
	while (1)
	{
		c = ft_getchar();
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
			buffer[position] = c;
		position++;
		if (position >= bufsize)
		{
			buffer = ft_realloc(buffer, bufsize, bufsize + MSH_RL_SIZ);
			bufsize += MSH_RL_SIZ;
		}
	}
}

void	msh_init_envp(char **envp, t_dnarr *newenvp)
{
	int i;

	i = 0;
	while (envp[i])
		dnarr_push(newenvp, ft_strdup(envp[i++]));
}

void	msh_loop(char **envp)
{
	int		status;
	char	*line;
	char	**args;
	t_dnarr	*newenvp;

	status = 1;
	newenvp = dnarr_create(sizeof(char *) ,50);
	msh_init_envp(envp, newenvp);
	while (status)
	{
		msh_put_arrow();
		line = msh_read_line();
		args = msh_strsplit(line);
		status = msh_execute(args, newenvp, envp);
		free(line);
		ft_free_map(args);
	}
	dnarr_clrdestroy(newenvp);
}

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	msh_loop(envp);
	return (0);
}
