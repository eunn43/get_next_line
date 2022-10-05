/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjeon <seonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:41:17 by seonjeon          #+#    #+#             */
/*   Updated: 2022/09/29 11:12:10 by seonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define OPEN_MAX 10240

char	*get_next_line(int fd);
int		sck_newline(char *buf);
char	*ft_read(char *backup, int fd);
char	*ft_strdup(char *s);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
