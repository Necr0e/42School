/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:07:03 by oseitama          #+#    #+#             */
/*   Updated: 2023/01/28 17:07:59 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_op.h"

t_vec	vec_rotz(t_vec dir, double deg)
{
	t_vec rot;

	rot.x = dir.x * cos(deg) - dir.y * sin(deg);
	rot.y = dir.y * sin(deg) + dir.y * cos(deg);
	rot.z = dir.z;
	return (rot);
}
