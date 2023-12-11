#include "../includes/so_long.h"

int check_shape(t_game *game) {
  int i;
  int j;
  int k;
  size_t base_len;

  k = 0;
  j = 0;
  i = 0;
  base_len = ft_strlen(game->matrix[k]);
  while (j < game->lines) {
    while (i < game->rows) {
      if (game->matrix[j][i++] == '.' &&
          (j == 0 || i == 0 || i == game->rows - 1 || j == game->lines - 1))
        return (0);
    }
    i = 0;
    j++;
  }
  while (k < game->lines) {
    if (ft_strlen(game->matrix[k]) != base_len)
      return (0);
    k++;
  }
  write(1, "map is ok\n", 10);
  return (1);
}

void flood_fill(t_game *game, int x, int y) {
  if (game->matrix[y][x] == '.')
    return;
  if (check_bounds(y, x, *game)) {
    if (game->matrix[y][x] == 'C')
      game->collectables++;
    game->matrix[y][x] = '.';
    flood_fill(game, x - 1, y);
    flood_fill(game, x + 1, y);
    flood_fill(game, x, y + 1);
    flood_fill(game, x, y - 1);
  }
  return;
}

int check_collectables(t_game *game, t_game *og_game) {
  int i;
  int j;

  j = 0;
  i = 0;
  while (j < og_game->lines) {
    while (i < og_game->rows) {
      if (og_game->matrix[j][i] == 'C') {
        if (game->matrix[j][i] != '.')
          return (1);
      }
      i++;
    }
    i = 0;
    j++;
  }
  printf("%d\n", game->collectables);
  if (game->collectables < 1)
    return (1);
  else
    return (0);
}

int check_exit(t_game *game, t_game *og_game) {
  int i;
  int j;
  int only;

  j = 0;
  i = 0;
  only = 0;
  while (j < game->lines) {
    while (i < game->rows) {
      if (og_game->matrix[j][i] == 'E') {
        only++;
      }
      i++;
    }
    i = 0;
    j++;
  }

  if (game->matrix[game->end_y][game->end_x] == '.' || only != 1)
    return (1);
  else
    return (0);
}
