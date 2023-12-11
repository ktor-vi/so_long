#include "../includes/so_long.h"

// Mac key code example
// All the key code example other than below is described on the site linked in
// READEME.md
#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_E 14
#define KEY_R 15
#define KEY_C 8

int key_press(int keycode, void *mlx, void *win, t_game *g) {

  t_game *game = &g[0];
  t_game *og_game = &g[1];
  if (keycode == KEY_ESC) // Quit the program when ESC key pressed
  {
    // system("leaks so_long");
    if (game->matrix)
      clear_tab(game->matrix);
    // clear_tab(og_game->matrix);
    exit(0);
  } else if (keycode == KEY_R) // Print map
  {
    print_map(*game);
    // write(1, "zoop\n", 5);
    // return (0);
  } else if (keycode == KEY_C) // Clear Map
  {
    clear(game);
    print_map(*game);
    // write(1, "zoop\n", 5);
    // return (0);
  } else if (keycode == KEY_E) // Parse map
  {
    printf("Key: E\n");
    game->collectables = 0;
    set_start(game);
    set_end(game);
    flood_fill(game, game->current_x, game->current_y);
    printf("current - %d, %d \n", game->current_x, game->current_y);
    printf("end - %d, %d \n", game->end_x, game->end_y);
    print_map(*game);
    if (check_shape(game) && !check_collectables(game, og_game))
      printf("Map is valid\n");
    else
      printf("Map is not valid\n");
  } else if (keycode == KEY_W) // Quit the program when ESC key pressed
  {
    if (check_bounds(game->current_y - 1, game->current_x, *og_game)) {
      printf("Key: W\n");
      (*game).matrix[game->current_y - 1][game->current_x] = '.';
      (*game).matrix[game->current_y][game->current_x] =
          (*og_game).matrix[game->current_y][game->current_x];
      game->current_y--;
    }
    print_map(*game);
  } else if (keycode == KEY_A) // Quit the program when ESC key pressed
  {
    if (check_bounds(game->current_y, game->current_x - 1, *og_game)) {
      printf("Key: A\n");
      (*game).matrix[game->current_y][game->current_x - 1] = '.';
      (*game).matrix[game->current_y][game->current_x] =
          (*og_game).matrix[game->current_y][game->current_x];
      game->current_x--;
    }
    print_map(*game);
  } else if (keycode == KEY_S) // Quit the program when ESC key pressed
  {
    if (check_bounds(game->current_y + 1, game->current_x, *og_game)) {
      printf("Key: S valid\n");
      (*game).matrix[game->current_y + 1][game->current_x] = '.';
      (*game).matrix[game->current_y][game->current_x] =
          (*og_game).matrix[game->current_y][game->current_x];
      game->current_y++;
    }
    print_map(*game);
  } else if (keycode == KEY_D) // Quit the program when ESC key pressed
  {

    if (check_bounds(game->current_y, game->current_x + 1, *og_game)) {
      printf("Key: D valid\n");
      (void)win;
      (void)mlx;
      printf("%d:%d\n", game->current_y, game->current_x + 1);

      (*game).matrix[game->current_y][game->current_x + 1] = '.';
      (*game).matrix[game->current_y][game->current_x] =
          (*og_game).matrix[game->current_y][game->current_x];
      //(void)move_right(game, mlx, win);
      game->current_x++;
    }
    print_map(*game);
  }
  return (0);
}
