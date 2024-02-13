#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"


typedef struct s_position
{
	int		x;
	int 	y;
}	t_position;

typedef struct s_elements
{
	static int		collectibles;
	static int		start;
	static int		exit;
}	t_elements;

int		ft_check_extension(char *f);
int		ft_check_bordline(char *line);
int		ft_check_midlines(char *line);
t_elements ft_get_elements(char *line);

#endif