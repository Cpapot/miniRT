/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse_ft.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:59:56 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 16:00:27 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PARSE_FT_H
# define MINI_PARSE_FT_H

typedef bool	(*t_mini_parse_ft)(char **line_pt);

bool	rgb_check(char **line_pt);
bool	skip_nb(char **line);
bool	check_empty(char **line);
bool	coord_check(char **line);
bool	vec_check(char **line);
bool	fov_check(char **line);
bool	check_for_material(char **line);
bool	check_float(char **line_pt);
bool	incr_one(char **line_pt);
bool	space_incr(char **line_pt);

#endif
