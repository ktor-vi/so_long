#include "../includes/so_long.h"

int display_wall(t_game *game, void *mlx, void *mlx_win) {
  void *wall;

  wall = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", &game->img_pxl,
                               &game->img_pxl);
  int i;
  int j;

  j = 0;
  i = 0;
  while (j < game->lines) {
    while (i < game->rows) {
      if (game->matrix[j][i] == '1') {
        mlx_put_image_to_window(mlx, mlx_win, wall, i * game->img_pxl,
                                j * game->img_pxl);
      }
      i++;
    }
    i = 0;
    j++;
  }
  return (0);
}

int display_ground(t_game *game, void *mlx, void *mlx_win) {
  void *ground;

  ground = mlx_xpm_file_to_image(mlx, "./img/ground.xpm", &game->img_pxl,
                                 &game->img_pxl);
  int i;
  int j;

  j = 0;
  i = 0;
  while (j < game->lines) {
    while (i < game->rows) {
      if (game->matrix[j][i] != '1') {
        mlx_put_image_to_window(mlx, mlx_win, ground, i * game->img_pxl,
                                j * game->img_pxl);
      }
      i++;
    }
    i = 0;
    j++;
  }
  return (0);
}

int display_collectible(t_game *game, void *mlx, void *mlx_win) {

  void *collectible;

  collectible = mlx_xpm_file_to_image(mlx, "./img/collectible.xpm",
                                      &game->img_pxl, &game->img_pxl);
  int i;
  int j;

  j = 0;
  i = 0;
  while (j < game->lines) {
    while (i < game->rows) {
      if (game->matrix[j][i] == 'C') {
        mlx_put_image_to_window(mlx, mlx_win, collectible, i * game->img_pxl,
                                j * game->img_pxl);
      }
      i++;
    }
    i = 0;
    j++;
  }
  return (0);
}

int display_player(t_game *game, void *mlx, void *mlx_win) {
  void *player;

  player = mlx_xpm_file_to_image(mlx, "./img/right1.xpm", &game->img_pxl,
                                 &game->img_pxl);

  mlx_put_image_to_window(mlx, mlx_win, player, game->current_x * 64,
                          (game->current_y - 1) * 64);

  return (0);
}

int display_exit(t_game *game, void *mlx, void *mlx_win) {
  void *exit;

  exit = mlx_xpm_file_to_image(mlx, "./img/exit.xpm", &game->img_pxl,
                               &game->img_pxl);

  mlx_put_image_to_window(mlx, mlx_win, exit, game->end_x * 64,
                          (game->end_x - 1) * 64);
  return (0);
}
