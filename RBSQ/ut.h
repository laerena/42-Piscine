/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:08:22 by leilai            #+#    #+#             */
/*   Updated: 2025/09/08 17:46:01 by leilai           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UT_H
# define UT_H

typedef struct s_map
{
	int	rows;
	int 	cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
}	t_map;

typedef struct s_square
{
	int	size;
	int	row;
	int	col;
}	t_square;

#endif
