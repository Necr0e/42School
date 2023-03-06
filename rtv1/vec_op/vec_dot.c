/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:47:57 by oseitama          #+#    #+#             */
/*   Updated: 2023/01/28 16:51:04 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_op.h"

/*
**	Uses the dot product to multiply two vectors
*/
double	vec_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
