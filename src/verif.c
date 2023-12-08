#include "../includes/so_long.h"

int	check_wall(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < game->lines)
	{
		while (i < game->rows)
		{
			if (game->matrix[j][++i] == '.' && (j == 0 || i == 0 || i == game->rows - 1 ||  j == game->lines - 1))
				return (0);
		}
		i = 0;
		j++;
	}
	return (1);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (game->matrix[y][x] == '.')
		return ;
	if (check_bounds(y, x, *game))
	{
		if (game->matrix[y][x] == 'C')
			game->collectables++;
		game->matrix[y][x] = '.';
		flood_fill(game, x - 1, y);
		flood_fill(game, x + 1, y);
		flood_fill(game, x, y + 1);
		flood_fill(game, x, y - 1);
	}
	return ;
}


