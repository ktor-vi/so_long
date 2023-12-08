

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <string.h>

typedef struct	s_game {
	char	*addr;
	char  **matrix;
	int		lines;
	int		rows;
	int   img_pxl;
	int   collectables;
	int 	current_x;
	int 	current_y;
	int  end_x ;
	int  end_y ;
}				t_game;

int		calc_lines(char *path);
int		calc_rows(char *path);
t_game build_matrix(char *path, t_game game);
void print_map(t_game game);
void flood_fill(t_game *game, int x, int y);
int	check_wall(t_game *game);
void set_start(t_game *game);
void set_end(t_game *game);
void clear(t_game *game);
int check_bounds(int x, int y, t_game game);
void	clear_tab(char **splitted);
#endif
