/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:32:31 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/09 15:16:52 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <string.h>
# include <errno.h>
# include "../MLX/include/MLX42/MLX42.h"

typedef struct s_elements
{
	int		collectibles;
	int		start;
	int		exit;
}	t_elements;

typedef struct s_position
{
	int		x;
	int		y;
}	t_pos;

typedef struct param
{
	int nb_moves;
}	t_param;

int			ft_check_extension(char *f);
int			ft_check_bordlines(char *line);
int			ft_check_midlines(char *line);
void		ft_get_elements(char *line, t_elements *elements);
t_elements	ft_set_struct(char **map);
int			ft_check_map(int fd);
void		display_info(char **map, t_elements cnt, t_elements cnt2, char *f);
char		**ft_stock_map(int fd);
int			ft_check_elements(t_elements count);
int			ft_check_shape(char **map);
void		ft_start_flood(char **map, t_elements *elements);
int			ft_check_forbidden_char(char **map);
int			ft_compare(t_elements cnt, t_elements cnt2);
int			ft_check_everything(int fd);
char		**ft_setting(t_elements cnt1, int fd);
void		ft_clear(char **map);

void		keyboard_hook_count(mlx_key_data_t key_enter, void *par);
void		ft_mlx_set(mlx_t *mlx);
mlx_image_t *ft_background(char **map, mlx_t *mlx);

#endif
