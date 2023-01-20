/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:04:32 by abarriga          #+#    #+#             */
/*   Updated: 2023/01/20 11:54:27 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	main(int argc, char **argv)
{
	t_d		variables;

	check_fractal(&variables, argc, argv);
	variables.mlx = mlx_init(WIDTH, HEIGHT, "FRACTOL ABARRIGA", true);
	if (!variables.mlx)
		exit(EXIT_FAILURE);
	variables.img = mlx_new_image(variables.mlx, 1000, 1000);
	mlx_image_to_window(variables.mlx, variables.img, 0, 0);
	init_variables(&variables);
	fill_pixel(&variables);
	mlx_scroll_hook(variables.mlx, &mouse_hook, &variables);
	mlx_key_hook(variables.mlx, &key_hook, &variables);
	mlx_cursor_hook(variables.mlx, &position_mouse_hook, &variables);
	mlx_loop(variables.mlx);
	mlx_delete_image(variables.mlx, variables.img);
	mlx_terminate(variables.mlx);
	return (EXIT_SUCCESS);
}

void	init_variables(t_d *v)
{
	v->lim_infx_m = -2;
	v->lim_supx_m = 1;
	v->lim_infx_j = -1.5;
	v->lim_supx_j = 1.5;
	v->lim_infy = -1;
	v->lim_supy = 1;
	v->x = 0;
	v->y = 0;
	v->iter = 0;
	v->max_iter = 50;
	v->pasox_m = (v->lim_supx_m - v->lim_infx_m) / WIDTH;
	v->pasox_j = (v->lim_supx_j - v->lim_infx_j) / WIDTH;
	v->pasoy = (v->lim_supy - v->lim_infy) / HEIGHT;
	v->num_comp.r = 0;
	v->num_comp.i = 0;
	v->julia_values.r = 0;
	v->julia_values.i = 0;
	v->xpos = 0;
	v->ypos = 0;
}

void	fill_pixel(t_d	*v)
{
	v->y = -1;
	while (++v->y < HEIGHT)
	{
		v->num_comp.i = v->lim_supy - (v->y * v->pasoy);
		v->x = -1;
		while (++v->x < WIDTH)
		{
			if (v->fractal == 'm' || v->fractal == 'b')
				v->num_comp.r = v->lim_infx_m + (v->x * v->pasox_m);
			else if (v->fractal == 'j')
				v->num_comp.r = v->lim_infx_j + (v->x * v->pasox_j);
			draw_fractol(v);
		}
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_d	*variables;

	variables = (t_d *) param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(variables->mlx);
	if (keydata.key == MLX_KEY_C)
		variables->fractal_color = '1';
	if (keydata.key == MLX_KEY_X)
		variables->fractal_color = '2';
	key_arrow(keydata, variables);
	fill_pixel(variables);
}

void	mouse_hook(double xdelta, double ydelta, void *param)
{
	t_d	*v;

	(void) xdelta;
	v = (t_d *) param;
	if (!(v->xpos < 0 || v->ypos < 0 || v->xpos > WIDTH || v->ypos > HEIGHT))
	{
		v->lim_infx_m = v->lim_infx_m - ((WIDTH / 2) - v->xpos) * v->pasox_m;
		v->lim_supx_m = v->lim_infx_m + (WIDTH * v->pasox_m);
		v->lim_infx_j = v->lim_infx_j - ((WIDTH / 2) - v->xpos) * v->pasox_j;
		v->lim_supx_j = v->lim_infx_j + (WIDTH * v->pasox_j);
		v->lim_infy = v->lim_infy + ((HEIGHT / 2) - v->ypos) * v->pasoy;
		v->lim_supy = v->lim_infy + (HEIGHT * v->pasoy);
	}	
	if (ydelta > 0)
		zoom_in(v);
	else if (ydelta < 0)
		zoom_out(v);
	v->pasox_m = (v->lim_supx_m - v->lim_infx_m) / WIDTH;
	v->pasox_j = (v->lim_supx_j - v->lim_infx_j) / WIDTH;
	v->pasoy = (v->lim_supy - v->lim_infy) / HEIGHT;
	fill_pixel(v);
}
