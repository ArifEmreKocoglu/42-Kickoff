/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:35:07 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/19 13:32:41 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# define WIDTH 1920
# define HEIGHT 1080

# define NORTH	"NO"
# define SOUTH	"SO"
# define WEST	"WE"
# define EAST	"EA"

# define FLOOR	'F'
# define CEIL	'C'


# include "mlx/mlx.h"
# include "../libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

typedef struct s_data
{
	double	ground_x;
	double	ground_y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	move_speed;
	double	rot_speed;

	void	*mlx_ptr;
	void	*mlx_win_ptr;

	char	**map_and_ftrs;
	char	*map_ftrs[6];
	char	**map;

	int		row_len;
	int		row_cnt;
	int		nw_cnt;
	
}	t_data;


void	set_value(t_data *data);
void	map_oprt(t_data *data, char *arv);
void	map_features_check(t_data *data);
void	map_ftrs_is_same_check(t_data *data);
void	idf_f_ctrl(t_data *data);
void	idf_c_ctrl(t_data *data);

int		map_format_check(char *av);

char	*ft_strcpy(char *dst, const char *src);
char	**ft_map_split(char const *s, char c, t_data *data);

#endif