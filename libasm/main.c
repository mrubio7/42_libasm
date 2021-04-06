/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:30:17 by mrubio            #+#    #+#             */
/*   Updated: 2021/04/06 11:40:26 by mrubio           ###   ########.fr       */
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
		printf("OK [%i] ", n1);
	}
	else
	{
		red();
		printf("KO my:[%i] orig:[%i] ", n1, n2);
	}
	printf(">> %s\n",str);

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
		printf("OK ");
	}
	else
	{
		red();
		printf("KO SRC> [%s] || MY> [%s] ", or, my);
	}
	printf(">> %s\n",str);
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
	printf("FT_STRCPY\n");
	check_strcpy("Holahola");
	check_strcpy("");
	check_strcpy("que tal como estas 42madrid, libasm es bien, el proyecto services es el demonio");
	check_strcpy("1234%%&(/&$$$$$$&//&u567465345)");

	end();
	return (0);
}