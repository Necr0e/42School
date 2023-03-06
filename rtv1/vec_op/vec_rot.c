/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:02:31 by oseitama          #+#    #+#             */
/*   Updated: 2023/01/28 17:11:46 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_op.h"

t_vec	vec_rot(t_vec dir, t_vec rot)
{
	dir = vec_rotx(dir, DTR(rot.x));
	dir = vec_roty(dir, DTR(rot.y));
	dir = vec_rotz(dir, DTR(rot.z));
	return (dir);
}
