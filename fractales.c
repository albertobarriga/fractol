/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:04:50 by abarriga          #+#    #+#             */
/*   Updated: 2023/01/20 11:35:18 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	mandelbrot(t_d	*variables)
{
	t_complex	z;
	t_complex	temp;
	t_complex	c;

	variables->iter = 0;
	z.r = 0;
	z.i = 0;
	c = variables->num_comp;
	while ((z.r * z.r + z.i * z.i) < 4 && variables->iter < variables->max_iter)
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = z.r * z.i * 2 + c.i;
		z.r = temp.r;
		z.i = temp.i;
		variables->iter++;
	}
}

void	julia(t_d	*variables)
{
	t_complex	z;
	t_complex	temp;
	t_complex	c;

	variables->iter = 0;
	z.r = variables->num_comp.r;
	z.i = variables->num_comp.i;
	c = variables->julia_values;
	while ((z.r * z.r + z.i * z.i) < 4 && variables->iter < variables->max_iter)
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = z.r * z.i * 2 + c.i;
		z.r = temp.r;
		z.i = temp.i;
		variables->iter++;
	}
}

void	burningship(t_d	*variables)
{
	t_complex	z;
	t_complex	temp;
	t_complex	c;

	variables->iter = 0;
	z.r = 0;
	z.i = 0;
	c = variables->num_comp;
	while ((z.r * z.r + z.i * z.i) < 4 && variables->iter < variables->max_iter)
	{
		if (z.r < 0)
			z.r = -z.r;
		if (z.i < 0)
			z.i = -z.i;
		temp.r = z.r * z.r - z.i * z.i - c.r;
		temp.i = z.r * z.i * 2 - c.i;
		z.r = temp.r;
		z.i = temp.i;
		variables->iter++;
	}
}

void	init_julia_values(t_d	*variables)
{
	if (variables->julia_type == '0')
	{
		variables->julia_values.r = -0.8 ;
		variables->julia_values.i = 0.156;
	}
	else if (variables->julia_type == '1')
	{
		variables->julia_values.r = 0.285;
		variables->julia_values.i = 0.01;
	}
	else if (variables->julia_type == '2')
	{
		variables->julia_values.r = -0.70176;
		variables->julia_values.i = -0.3842;
	}
	else if (variables->julia_type == '3')
	{
		variables->julia_values.r = -0.7269;
		variables->julia_values.i = 0.1889;
	}
}
