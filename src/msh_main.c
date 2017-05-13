/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 03:49:17 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/13 07:26:52 by gguiulfo         ###   ########.fr       */
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
		if ((c = ft_getchar()) == EOF)
			free(buffer);
		if (c == EOF)
			return (NULL);
		if (c == '\n')
			buffer[position] = '\0';
		if (c == '\n')
			return (buffer);
		else
			buffer[position++] = c;
		if (position >= bufsize)
			buffer = ft_realloc(buffer, bufsize, bufsize + MSH_RL_SIZ);
		if (position >= bufsize)
			bufsize += MSH_RL_SIZ;
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

	(void)envp;
	status = 1;
	newenvp = dnarr_create(sizeof(char *), 50);
	msh_init_envp(envp, newenvp);
	while (status)
	{
		msh_put_arrow();
		line = msh_read_line();
		if (!line)
			break ;
		args = msh_strsplit(line);
		status = msh_execute(args, newenvp);
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
