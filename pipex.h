/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:47:58 by amessah           #+#    #+#             */
/*   Updated: 2022/04/04 01:00:38 by amessah          ###   ########.fr       */
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
char	*search_for_path(char **env);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free(char **tab);
void	file_error(char *str);
int		process_2(char **argv, char **env,char *path, int fd[]);
int		process_1(char **argv, char **env,char *path , int fd[]);
size_t	ft_strlen(const char *str);
char	*join(char *str1, char *str2, char *str3);
char	*unix_cmd(char	*line, char **argv);
void	ft_error(char **cmd,char **path);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	child_process(char *argv, char **env, char *path);
void	exucute(char *argv, char **env , char *path);
int		get_next_line_pipex(char **line);
void	here_doc(char *argv);

char	*get_buffer(int fd, char *str);
char	*get_line(char *s);
char	*rest(char *s);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);

#endif