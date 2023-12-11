#include "../includes/so_long.h"

void clear(t_game *game) {
  int i;
  int j;

  j = 0;
  i = 0;
  while (j < game->lines) {
    while (i < game->rows) {
      // printf("%i ", i) ;
      game->matrix[j][i] = '0';
      i++;
    }
    i = 0;
    j++;
  }
}

t_game build_matrix(char *path, t_game game) {
  int file;
  char *line;
  char *big;

  line = NULL;
  file = open(path, O_RDONLY);
  if (file < 0)
    exit(1);
  line = get_next_line(file);
  if (!line)
    exit(1);
  game.lines = calc_lines(path);
  game.rows = ft_memchr_gnl(line, '\n');
  big = ft_calloc(1, 1);
  while (line) {
    big = ft_strjoin(big, line);
    free(line);
    line = get_next_line(file);
  }
  if (line)
    free(line);
  game.matrix = ft_split(big, '\n');
  free(big);
  close(file);
  return (game);
}

void set_start(t_game *game) {
  int i;
  int j;

  j = 0;
  i = 0;
  while (j < game->lines) {
    while (i < game->rows) {
      if (game->matrix[j][i] == 'P') {
        game->current_y = j;
        game->current_x = i;
      }
      i++;
    }
    i = 0;
    j++;
  }
}

void set_end(t_game *game) {
  int i;
  int j;

  j = 0;
  i = 0;
  while (j < game->lines) {
    while (i < game->rows) {
      if (game->matrix[j][i] == 'E') {
        game->end_y = j;
        game->end_x = i;
      }
      i++;
    }
    i = 0;
    j++;
  }
}

void set_collectables(t_game *game) {
  int i;
  int j;

  j = 0;
  i = 0;
  while (j < game->lines) {
    while (i < game->rows) {
      if (game->matrix[j][i] == 'C') {
        game->total_collectables++;
      }
      i++;
    }
    i = 0;
    j++;
  }
}
