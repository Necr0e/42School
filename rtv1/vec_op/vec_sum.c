/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_sum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:13:04 by oseitama          #+#    #+#             */
/*   Updated: 2023/01/28 17:13:42 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_op.h"

t_vec	vec_sum(t_vec v1, t_vec v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.y;
	return (v1);
}
