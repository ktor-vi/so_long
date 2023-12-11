#include "../includes/so_long.h"

int calc_x(t_game *game) {
  int size_x;

  size_x = game->img_pxl * game->lines;
  return (size_x);
}

int calc_y(t_game *game) {
  int size_y;

  size_y = game->img_pxl * game->rows;
  return (size_y);
}
