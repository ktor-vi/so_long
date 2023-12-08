#include "../includes/so_long.h"

int	check_bounds(int y, int x, t_game game)
{

	if (x < 0 || x > game.rows - 1)
		return (0);
	else if (y < 0 || y > game.lines- 1)
		return (0);
	else if (game.matrix[y][x] != '1')
		return (1);
	 return 0;
}
