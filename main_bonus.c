/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:51:04 by amessah           #+#    #+#             */
/*   Updated: 2022/04/04 01:03:21 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	child_process(char *argv, char **env, char *path)
{
	int	pid;
	int	fd[2];
	
	if(pipe(fd) == -1)
		exit(1);
	pid = fork();
	if(pid == -1 )
		exit(1);
	if(pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		exucute(argv, env, path);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, NULL, 0);
	}
}

void	exucute(char *argv, char **env , char *path)
{
	char *cmd;
	char **cmd_arg;

	cmd = unix_cmd(path, &argv);
	cmd_arg = ft_split(argv, ' ');
	if(execve(cmd, cmd_arg, env) == -1)
		exit(1);
	ft_free(cmd_arg);
	free(cmd);
}

void	here_doc(char *argv)
{
	int fd[2];
	char *line;
	int pid;
	
	if(pipe(fd) == -1)
		exit(1);
	pid = fork();	
	if (pid == 0)
	{
		while(get_next_line_pipex(&line))
		{
			puts("gggg");
			close(fd[0]);
			if(ft_strcmp(line, argv) == 0)
				exit(0);
			write(fd[1], line, ft_strlen(line));
			get_next_line_pipex(&line);
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
}

int	main(int argc, char *argv[], char **env)
{
	int	f1;
	int	f2;
	int	i;
	char *line;

	if (argc >= 5)
	{
		if(argc == 6 && !ft_strcmp(argv[1], "here_doc"))
		{
			i = 3;	
			i = open(argv[argc - 1], O_RDONLY | O_CREAT | O_APPEND, 0777);
			here_doc(argv[2]);
		}
		else
		{
			i = 2;	
			line = search_for_path(env);
			f1 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			f2 = open(argv[1], O_RDONLY, 0777);
			dup2(f2, 0);
		}
		while(i < argc - 2)
			child_process(argv[i++], env, line);
		dup2(f1, 1);
		exucute(argv[argc- 2], env, line);
	}
	return (0);
}
