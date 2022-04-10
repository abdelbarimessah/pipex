/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:47:20 by amessah           #+#    #+#             */
/*   Updated: 2022/04/10 00:28:54 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **env)
{
	char	*line;
	int		fd[2];
	int		id1;
	int		id2;

	if (argc == 5)
	{
		line = search_for_path(env);
		if (pipe(fd) < 0 || !line)
			exit(1);
		id1 = process_1(argv, env, line, fd);
		id2 = process_2(argv, env, line, fd);
		free(line);
		close(fd[0]);
		close(fd[1]);
		waitpid(id1, NULL, 0);
		waitpid(id2, NULL, 0);
	}
	else
		write(1, "error", 5);
	return (0);
}
