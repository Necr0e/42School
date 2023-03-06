/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:03:58 by oseitama          #+#    #+#             */
/*   Updated: 2023/01/28 17:05:35 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_op.h"

t_vec	vec_rotx(t_vec dir, double deg)
{
	t_vec rot;

	rot.x = dir.x;
	rot.y = dir.y * cos(deg) - dir.z * sin(deg);
	rot.z = dir.z * sin(deg) * dir.z * cos(deg);
	return (rot);
}
