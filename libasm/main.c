/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:30:17 by mrubio            #+#    #+#             */
/*   Updated: 2021/04/07 20:08:29 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

//COLOR
void	green()
{
	printf("\033[0;32m");
}
void	red()
{
	printf("\033[0;31m");
}
void	yellow()
{
	printf("\033[0;33m");
}
void	end()
{
	printf("\033[0m");
}
//COLOR

void	check_strlen(char *str)
{
	int n1;
	int n2;

	n1 = ft_strlen(str);
	n2 = strlen(str);
	if (n1 == n2)
	{
		green();
		printf("OK [%i]   ", n1);
		printf(">> %s\n",str);
	}
	else
	{
		red();
		printf("KO   my:[%i] orig:[%i] ", n1, n2);
	}

}

void	check_strcpy(char *str)
{
	char *my;
	char *or;

	my = malloc(ft_strlen(str));
	or = malloc(ft_strlen(str));
	ft_strcpy(my, str);
	strcpy(or, str);
	if (strcmp(or, my) == 0)
	{
		green();
		printf("OK   ");
		printf(">> %s\n",str);
	}
	else
	{
		red();
		printf("KO   SRC> [%s] || MY> [%s] ", or, my);
	}
}

void	check_strcmp(char *s1, char *s2)
{
	int my;
	int or;

	my = ft_strcmp(s1, s2);
	or = strcmp(s1, s2);
	if (my == or)
	{
		green();
		printf("OK [%i]  ||  arg1> [%s]   arg2> [%s]\n", my, s1, s2);
	}
	else
	{
		red();
		printf("KO my[%i] or[%i]  ||  arg1> [%s]   arg2> [%s]\n", my, or, s1, s2);
	}
}

int		main(void)
{
	yellow();
	printf("FT_STRLEN\n");
	check_strlen("Holahola");
	check_strlen("");
	check_strlen("que tal como estas 42madrid, libasm es bien, el proyecto services es el demonio");
	check_strlen("1234%%&/(&$$$$$$&/(/&u567465345)");

	yellow();
	printf("\nFT_STRCPY\n");
	check_strcpy("Holahola");
	check_strcpy("");
	check_strcpy("que tal como estas 42madrid, libasm es bien, el proyecto services es el demonio");
	check_strcpy("1234%%&(/&$$$$$$&//&u567465345)");

	yellow();
	printf("\nFT_STRCMP\n");
	check_strcmp("Holhola", "Quetal");
	check_strcmp("", "");
	check_strcmp("Holhola", "");
	check_strcmp("Holholb", "");
	check_strcmp("Holaholb", "Holhola");
	check_strcmp("", "Holholb");

	end();
	return (0);
}