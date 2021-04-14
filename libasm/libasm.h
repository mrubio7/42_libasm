/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:52:36 by mrubio            #+#    #+#             */
/*   Updated: 2021/04/14 23:24:32 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

size_t		ft_strlen(const char *str);
char		*ft_strcpy(const char *dest, const char *orig);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *str);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);

#endif