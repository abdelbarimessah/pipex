/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:09:12 by amessah           #+#    #+#             */
/*   Updated: 2022/04/10 00:31:32 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char **cmd, char **path)
{
	write(2, "command not found :", 20);
	if (*cmd)
		write(2, *cmd, ft_strlen(*cmd));
	write(2, "\n", 2);
	if (path[0])
		ft_free(path);
	ft_free(cmd);
}

char	*search_for_path(char **env)
{
	int		i;
	char	**line;
	char	*line1;
	int		k;

	k = 0;
	i = 0;
	while (env[i])
	{
		line = ft_split(env[i], '=');
		if (!ft_strcmp(line[0], "PATH"))
		{
			k = ft_strlen(line[1]);
			line1 = (char *)malloc(sizeof(char) * k);
			ft_memcpy(line1, line[1], k);
			ft_free(line);
			return (line1);
		}
		ft_free(line);
		i++;
	}
	ft_free(line);
	return (NULL);
}

char	*unix_cmd(char *line, char **argv)
{
	char	**cmd_split;
	char	**path;
	char	*cmd;
	int		i;

	i = -1;
	path = ft_split(line, ':');
	cmd_split = ft_split(*argv, ' ');
	if (access(cmd_split[0], X_OK) == 0)
		return (cmd_split[0]);
	else
	{
		while (path[++i])
		{
			cmd = join(path[i], "/", cmd_split[0]);
			if (access(cmd, X_OK) == 0)
			{
				ft_free(path);
				ft_free(cmd_split);
				return (cmd);
			}
			free(cmd);
		}
	}
	ft_error(cmd_split, path);
	return (NULL);
}

int	process_1(char **argv, char **env, char *path, int fd[])
{
	char	*cmd;
	char	**cmd_arg;
	int		pid;
	int		fd_prosses;

	cmd = unix_cmd(path, &argv[2]);
	cmd_arg = ft_split(argv[2], ' ');
	pid = fork();
	if (pid == -1)
		strerror(pid);
	if (pid == 0)
	{
		fd_prosses = open(argv[1], O_RDWR, 0777);
		if (fd_prosses < 0)
			file_error(argv[1]);
		dup2(fd_prosses, 0);
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		close(fd_prosses);
		execve(cmd, cmd_arg, env);
		free(cmd);
		exit(1);
	}
	ft_free(cmd_arg);
	free(cmd);
	return (pid);
}

int	process_2(char **argv, char **env, char *path, int fd[])
{
	char	*cmd;
	char	**cmd_arg;
	int		pid;
	int		fd_prosses;

	cmd = unix_cmd(path, &argv[3]);
	cmd_arg = ft_split(argv[3], ' ');
	pid = fork();
	if (pid == -1)
		strerror(pid);
	if (pid == 0)
	{
		fd_prosses = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (fd_prosses < 0)
			file_error(argv[4]);
		dup2(fd_prosses, 1);
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[1]);
		close(fd_prosses);
		execve(cmd, cmd_arg, env);
		free(cmd);
		exit(1);
	}
	ft_free(cmd_arg);
	free(cmd);
	return (pid);
}
