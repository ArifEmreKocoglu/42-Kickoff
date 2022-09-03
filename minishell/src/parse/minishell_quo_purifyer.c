/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_quo_purifyer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:13:41 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/03 18:14:03 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void quo_transformer(char **parse, char **prs, int *i, int *i2, int *x)
{
	parse[*i][*i2] = 0;
	char *tmp;
	char *env_var;
	int b;
	bool ctrl;

	b = 0;
	ctrl = false;
	while (parse[*i][b] == 34)
		b++;
	tmp = ft_calloc(sizeof(char), ft_strlen(parse[*i]) - b);
	tmp = ft_strcpy(tmp, &(parse[*i][b]));
	parse[*i][*i2] = '$';
	env_var = ft_calloc(sizeof(char), ft_strlen(&(parse[*i][*i2])) - 1);
	b = 0;
	if(parse[*i][*i2 + 1] == '?')
	{
		char *str;
		
		ctrl = true;
		str = ft_itoa(data.status);
		while (str[b])
		{
			env_var[b] = str[b];
			b++;
		}
		free(str);
		*i2 += 2;
	}
	while (parse[*i][*i2] != 34 && parse[*i][*i2])
		env_var[b++] = parse[*i][(*i2)++];
	if(ctrl == false)
		env_var = env_converter(env_var);
	free(prs[*x]);
	prs[*x] = ft_strjoin(tmp, env_var);
	free(env_var);
	free(tmp);
}

static void transformer(char **parse, char **prs, int *i, int *i2, int *x)
{
	parse[*i][*i2] = 0;
	char *tmp;
	char *env_var;
	int b;
	bool ctrl;

	b = 0;
	ctrl = false;
	tmp = ft_calloc(sizeof(char), ft_strlen(parse[*i]));
	tmp = ft_strcpy(tmp, parse[*i]);
	parse[*i][*i2] = '$';
	env_var = ft_calloc(sizeof(char), ft_strlen(&(parse[*i][*i2])));
	if(parse[*i][*i2 + 1] == '?')
	{
		char *str;
		
		ctrl = true;
		str = ft_itoa(data.status);
		while (str[b])
		{
			env_var[b] = str[b];
			b++;
		}
		free(str);
		*i2 += 2;
	}
	while (parse[*i][*i2])
		env_var[b++] = parse[*i][(*i2)++];
	if(ctrl == false)
		env_var = env_converter(env_var);
	free(prs[*x]);
	prs[*x] = ft_strjoin(tmp, env_var);
	free(env_var);
	free(tmp);
}

static int quo_finder(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 34)
			return (2);
		else if (s[i] == 39)
			return (1);
		i++;
	}
	return (0);
}

static int dbl_quo_cnt(char *s)
{
	int cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == '"')
			cnt++;
		s++;
	}
	return (cnt);
}

char **quotes_purifyer(char **parse)
{
	int i;
	int i2;
	int x;
	int x2;
	char **prs;

	i = 0;
	x = 0;
	prs = ft_calloc(sizeof(char *), ft_arglen(parse) + 1);
	while (parse[i])
	{
		i2 = 0;
		x2 = 0;
		prs[x] = ft_calloc(sizeof(char), (ft_strlen(parse[i]) - dbl_quo_cnt(parse[i]) + 1));
		if (quo_finder(parse[i]) == 2)
		{
			while (parse[i][i2])
			{
				if (parse[i][i2] != 34 && parse[i][i2] != '$')
					prs[x][x2++] = parse[i][i2++];
				else if (parse[i][i2] != 34 && parse[i][i2] == '$')
					quo_transformer(parse, prs, &i, &i2, &x);
				else
					i2++;
			}
		}
		else if (quo_finder(parse[i]) == 1)
		{
			while (parse[i][i2])
			{
				if (parse[i][i2] != 39)
					prs[x][x2++] = parse[i][i2++];
				else
					i2++;
			}
		}
		else
		{
			while (parse[i][i2])
			{
				if (parse[i][i2] != '$')
					prs[x][x2++] = parse[i][i2++];
				else if (parse[i][i2] == '$')
					transformer(parse, prs, &i, &i2, &x);
				else
					i2++;
			}
		}
		x++;
		i++;
	}
	ft_free(parse);
	return (prs);
}