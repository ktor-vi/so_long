#include "../includes/so_long.h"

int move_right(t_game *game, void *mlx, void *mlx_win) {
  void *ground;
  void *player;
  ground = mlx_xpm_file_to_image(mlx, "./img/ground.xpm", &game->img_pxl,
                                 &game->img_pxl);
  player = mlx_xpm_file_to_image(mlx, "./img/right1.xpm", &game->img_pxl,
                                 &game->img_pxl);

  if (game->matrix[game->current_y][game->current_x + 1] != '1') {
    mlx_put_image_to_window(mlx, mlx_win, ground, game->current_x * 64,
                            (game->current_y) * 64);

    mlx_put_image_to_window(mlx, mlx_win, player, (game->current_x + 1) * 64,
                            (game->current_y - 1) * 64);
  }
  return (0);
}
