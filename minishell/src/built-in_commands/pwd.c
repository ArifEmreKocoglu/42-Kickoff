/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:46:47 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/07 12:28:33 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(char **parse)
{
	char	*pwd;

	(void)parse;
	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	free(pwd);
	data.status = 0;
}
