/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:03:19 by abarriga          #+#    #+#             */
/*   Updated: 2023/01/20 11:55:51 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractol(t_d *v)
{
	int	*c1;
	int	*c2;

	c1 = (int [5]){0xFF0000FF, 0xa85032FF, 0x32a852FF, 0x3266a8FF, 0xa432a8FF};
	c2 = (int [5]){0x2F4F4FFF, 0x008B8BFF, 0x7FFFD4FF, 0x00BFFFFF, 0x4169E1FF};
	if (v->fractal == 'm')
		mandelbrot(v);
	else if (v->fractal == 'j')
	{			
		init_julia_values(v);
		julia(v);
	}
	else if (v->fractal == 'b')
	{
		burningship(v);
	}
	if (v->iter == v->max_iter)
		mlx_put_pixel(v->img, v->x, v->y, 0x696969FF);
	else
	{
		if (v->fractal_color == '1')
			mlx_put_pixel(v->img, v->x, v->y, c1[v->iter % 5]);
		else
			mlx_put_pixel(v->img, v->x, v->y, c2[v->iter % 5]);
	}
}

void	legend_info(void)
{
	write(1, "\n\nFRACTOL ABARRIGA\n\n", 20);
	write(1, "\tChoose your type of color:\n", 29);
	write(1, "\t\t-1\n", 5);
	write(1, "\t\t-2\n", 5);
	write(1, "\tChoose your type of fractal:\n", 30);
	write(1, "\t\t-Mandelbrot  ->> m\n", 21);
	write(1, "\t\t-Julia       ->> j", 20);
	write(1, "   (If you choose julia you need to choose the type:"
		" 0, 1, 2, 3.)\n", 67);
	write(1, "\t\t-Burningship ->> m\n\n", 22);
	exit(EXIT_FAILURE);
}

void	check_fractal(t_d *variables, int argc, char **argv)
{
	if (argc > 4 || argc < 3)
		legend_info();
	if (argv[1][0] == '1' || argv[1][0] == '2')
		variables->fractal_color = argv[1][0];
	else
		legend_info();
	if (argv[2][0] == 'm' || argv[2][0] == 'j' || argv[2][0] == 'b')
	{
		variables->fractal = argv[2][0];
		printf("%d", argc);
	}
	else
		legend_info();
	if (variables->fractal == 'j')
	{
		if (argv[3][0] == '0' || argv[3][0] == '1' || argv[3][0] == '2'
			|| argv[3][0] == '3')
			variables->julia_type = argv[3][0];
		else
			legend_info();
	}	
}

void	position_mouse_hook(double xpos, double ypos, void *param)
{
	t_d	*v;

	v = (t_d *) param;
	v->xpos = xpos;
	v->ypos = ypos;
}

void	key_arrow(mlx_key_data_t keydata, t_d *variables)
{
	if (keydata.key == MLX_KEY_LEFT)
	{
		variables->lim_infx_m -= variables->pasox_m * 25;
		variables->lim_supx_m -= variables->pasox_m * 25;
		variables->lim_infx_j -= variables->pasox_j * 25;
		variables->lim_supx_j -= variables->pasox_j * 25;
	}
	if (keydata.key == MLX_KEY_RIGHT)
	{
		variables->lim_infx_m += variables->pasox_m * 25;
		variables->lim_supx_m += variables->pasox_m * 25;
		variables->lim_infx_j += variables->pasox_j * 25;
		variables->lim_supx_j += variables->pasox_j * 25;
	}
	if (keydata.key == MLX_KEY_UP)
	{
		variables->lim_supy += variables->pasoy * 25;
		variables->lim_infy += variables->pasoy * 25;
	}
	if (keydata.key == MLX_KEY_DOWN)
	{
		variables->lim_supy -= variables->pasoy * 25;
		variables->lim_infy -= variables->pasoy * 25;
	}
}	
