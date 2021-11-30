/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:52:55 by ametta            #+#    #+#             */
/*   Updated: 2021/11/30 09:55:32 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define MAX_FD 256
# define BUFFER_SIZE 512

void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_realloc(void *ptr, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
void	ft_putstr(const char *str);
void	ft_putendl(const char *str);
int		get_next_line(const int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, char const *s2);
int		ft_atoi(const char *str);
char	**ft_split(const char *str, const char chr);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
int		word_counter(const char *line, const char chr);

#endif
