/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:47:58 by amessah           #+#    #+#             */
/*   Updated: 2022/04/10 00:32:47 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define BUFFER_SIZE 1

# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/errno.h>
# include <stdlib.h>
# include <stdio.h>

char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*search_for_path(char **env);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free(char **tab);
void	file_error(char *str);
int		process_2(char **argv, char **env, char *path, int fd[]);
int		process_1(char **argv, char **env, char *path, int fd[]);
size_t	ft_strlen(const char *str);
char	*join(char *str1, char *str2, char *str3);
char	*unix_cmd(char	*line, char **argv);
void	ft_error(char **cmd, char **path);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	child_process(char *argv, char **env);
int		get_next_line_pipex(char **line);
void	here_doc(char *limiter, int argc);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strnstr(const char	*big, const char *little, size_t len);
char	*ft_strdup(const char *s1);
int		get_next_line(char **line);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);
void	error(void);
int		open_file(char *argv, int i);

#endif