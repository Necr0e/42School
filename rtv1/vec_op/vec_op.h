/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_op.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:36:21 by oseitama          #+#    #+#             */
/*   Updated: 2023/01/28 17:13:50 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_OP_H
# define VEC_OP_H

# include <math.h>
# define DTR(deg) ((double)deg * (M_PI / 180))

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

double	vec_len(t_vec v1);
double	vec_dot(t_vec v1, t_vec v2);
t_vec	vec_scale(t_vec v1, double t);
t_vec	vec_norm(t_vec v1);
t_vec	vec_sub(t_vec v1, t_vec v2);
t_vec	vec_sum(t_vec v1, t_vec v2);
t_vec	vec_rot(t_vec dir, t_vec rot);
t_vec	vec_rotx(t_vec dir, double deg);
t_vec	vec_roty(t_vec dir, double deg);
t_vec	vec_rotz(t_vec dir, double deg);

#endif
