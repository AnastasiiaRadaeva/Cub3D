#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_drawer(t_vars *vars)
{
	int k;
	int i;
	int j;
	int x;
	int y = -1;
	i = -1;
	k = CUBE;
	int a = 1;

	while (vars->map->map[++i])
	{
		{
			while (++y < (i + 1) * CUBE)
			{
				x = -1;
				j = 0;
				while (vars->map->map[i][j])
				{
					while (++x < (j + 1) * CUBE)
					{
						if (vars->map->map[i][j] == '1')
						{
							if ((x + 1) == ((j + 1) * CUBE))
							{
								my_mlx_pixel_put(vars->img, x, y, 0xaa0000);
								my_mlx_pixel_put(vars->img, x + 1, y, 0xaa0000);
							}
							else
								my_mlx_pixel_put(vars->img, x, y, 0x878794);
						}
						else if (vars->map->map[i][j] == '0' || vars->map->map[i][j] == 'N' ||
								 vars->map->map[i][j] == '2' || vars->map->map[i][j] == 'W' ||
								 vars->map->map[i][j] == 'E' || vars->map->map[i][j] == 'S')
						{
							if ((x + 1) == ((j + 1) * CUBE))
							{
								my_mlx_pixel_put(vars->img, x, y, 0xaa0000);
								my_mlx_pixel_put(vars->img, x + 1, y, 0xaa0000);
							}
							else
								my_mlx_pixel_put(vars->img, x, y, 0x36054d);
						}
					}
					j++;
				}
				if ((y + 1) == ((i + 1) * CUBE))
				{
					x = -1;
					j--;
					while (++x < (j + 1) * CUBE)
					{
						my_mlx_pixel_put(vars->img, x, y, 0xaa0000);
						my_mlx_pixel_put(vars->img, x, y + 1, 0xaa0000);
					}
				}
			}
		}
	}
	my_mlx_pixel_put(vars->img, vars->map->p_x, vars->map->p_y, 0xffffff); //player
}
