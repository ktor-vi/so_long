#include "../includes/so_long.h"
#include <stdio.h>
#include <stdlib.h>

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17 // exit key code

int main(int argc, char **argv) {
  void *mlx;
  void *win;
  t_game game;
  t_game og_game;
  t_game g[2];

  (void)argc;
  game.addr = NULL;
  og_game.addr = NULL;
  og_game.matrix = 0;
  game.matrix = 0;
  game.lines = 0;
  game.rows = 0;
  ;
  game = build_matrix(argv[1], game);
  og_game = build_matrix(argv[1], og_game);
  print_map(game);
  set_start(&game);
  set_end(&game);
  og_game.img_pxl = 64;
  game.img_pxl = 64;

  g[0] = game;
  g[1] = og_game;
  mlx = mlx_init();
  win = mlx_new_window(mlx, calc_y(&game), calc_x(&game), "mlx_project");
  // display_wall(&og_game, mlx, win);
  // display_ground(&og_game, mlx, win);
  // display_collectible(&og_game, mlx, win);
  // display_player(&game, mlx, win);
  write(1, "ok\n", 3);
  printf("%d:%d\n", game.current_x, game.current_y + 1);
  mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, &g);

  // mlx_loop_hook(mlx, &display, g);
  //
  mlx_loop(mlx);
  return (0);
}
