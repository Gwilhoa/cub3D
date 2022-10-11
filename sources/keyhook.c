// #include "cub.h"

int	ft_key_hook2(int keycode, t_data *struc)
{
	if (keycode == 2)
	{
		if (struc->map_str[struc->perso_y / 64]
			[(struc->perso_x / 64) + 1] == '1')
			return (0);
		if (struc->map_str[struc->perso_y / 64][(struc->perso_x / 64)] == 'C')
			struc->map_str[struc->perso_y / 64][(struc->perso_x / 64)] = '0';
		struc->perso_x += 64;
		mlx_clear_window(struc->mlx_ptr, struc->mlx_win);
		ft_print_img(struc, keycode);
		struc->movement += 1;
	}
	return (1);
}

int ft_key_hook2(int keycode, t_data *cub)
{
	if (keycode == 2)
	{
		(cub->map[])
	}
}