

#ifndef FDF_H
#define SO_LONG .H
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <stdio.h>
#include <string.h>

typedef struct s_game {
  char *addr;
  char **matrix;
  int lines;
  int rows;
  int img_pxl;
  int collectables;
  int total_collectables;
  int current_x;
  int current_y;
  int end_x;
  int end_y;
} t_game;

typedef struct s_img {
  void *img;
  char *addr;
  int bits_per_pixel;
  int line_length;
  int endian;
} t_img;

int display_wall(t_game *game, void *mlx, void *mlx_win);
int display_player(t_game *game, void *mlx, void *mlx_win);
int display_collectible(t_game *game, void *mlx, void *mlx_win);
int display_ground(t_game *game, void *mlx, void *mlx_win);
int move_right(t_game *game, void *mlx, void *mlx_win);
int key_press(int keycode, void *mlx, void *win, t_game *g);
int calc_lines(char *path);
int calc_rows(char *path);
int calc_x(t_game *game);
int calc_y(t_game *game);
t_game build_matrix(char *path, t_game game);
void print_map(t_game game);
void flood_fill(t_game *game, int x, int y);
int check_exit(t_game *game, t_game *og_game);
int check_shape(t_game *game);
int check_collectables(t_game *game, t_game *og_game);
void set_start(t_game *game);
void set_end(t_game *game);
void set_collectables(t_game *game);
void clear(t_game *game);
int check_bounds(int x, int y, t_game game);
void clear_tab(char **splitted);
#endif
