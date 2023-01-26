/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:04:58 by abarriga          #+#    #+#             */
/*   Updated: 2023/01/26 13:14:18 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 667

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_d
{
	char		fractal;
	char		fractal_color;
	char		julia_type;
	int			max_iter;
	int			iter;
	double		x;
	double		y;
	double		lim_infx_m;
	double		lim_supx_m;
	double		lim_infx_j;
	double		lim_supx_j;
	double		lim_infy;
	double		lim_supy;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_complex	num_comp;
	t_complex	julia_values;
	double		pasox_m;
	double		pasox_j;
	double		pasoy;
	double		xpos;
	double		ypos;

}	t_d;

void	init_variables(t_d *variables);

void	fill_pixel(t_d	*variables);

void	draw_fractol(t_d *variables);

void	mandelbrot(t_d	*variables);

void	julia(t_d	*variables);

void	burningship(t_d	*variables);

void	init_julia_values(t_d	*variables);

void	legend_info(void);

void	key_hook(mlx_key_data_t keydata, void *param);

void	check_fractal(t_d *variables, int argc, char **argv);

void	mouse_hook(double xdelta, double ydelta, void *param);

void	position_mouse_hook(double xpos, double ypos, void *param);

void	key_arrow(mlx_key_data_t keydata, t_d *variables);

void	zoom_in(t_d	*v);

void	zoom_out(t_d *v);

#endif
