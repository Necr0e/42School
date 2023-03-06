/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:40:38 by oseitama          #+#    #+#             */
/*   Updated: 2022/08/24 16:40:11 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define MAX_FD 4096

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int	get_next_line(const int fd, char **line);

#endif
