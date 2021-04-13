/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:52:36 by mrubio            #+#    #+#             */
/*   Updated: 2021/04/07 23:05:31 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

size_t		ft_strlen(const char *str);
char		*ft_strcpy(const char *dest, const char *orig);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *str);

#endif