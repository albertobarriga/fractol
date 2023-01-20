/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:53:24 by abarriga          #+#    #+#             */
/*   Updated: 2023/01/20 11:55:43 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_d	*v)
{
	v->lim_infx_m = v->lim_infx_m * 0.8;
	v->lim_supx_m = v->lim_supx_m * 0.8;
	v->lim_infx_j = v->lim_infx_j * 0.8;
	v->lim_supx_j = v->lim_supx_j * 0.8;
	v->lim_infy = v->lim_infy * 0.8;
	v->lim_supy = v->lim_supy * 0.8;
}

void	zoom_out(t_d *v)
{
	v->lim_infx_m = v->lim_infx_m * 1.2;
	v->lim_supx_m = v->lim_supx_m * 1.2;
	v->lim_infx_j = v->lim_infx_j * 1.2;
	v->lim_supx_j = v->lim_supx_j * 1.2;
	v->lim_infy = v->lim_infy * 1.2;
	v->lim_supy = v->lim_supy * 1.2;
}
