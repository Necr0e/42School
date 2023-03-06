/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_roty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:05:44 by oseitama          #+#    #+#             */
/*   Updated: 2023/01/28 17:07:01 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_op.h"

t_vec	vec_roty(t_vec dir, double deg)
{
	t_vec rot;

	rot.x = dir.x * cos(deg) + dir.z * sin(deg);
	rot.y = dir.y;
	rot.z = dir.z * cos(deg) - dir.x * sin(deg);
	return (rot);
}
