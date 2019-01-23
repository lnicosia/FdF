/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:08:35 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/23 12:13:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	fill_background(t_env data, int color)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < data.config.s_height)
	{
		j = 0;
		while (j < data.config.s_width)
		{
			data.img.str[k] = color;
			j++;
			k++;
		}
		i++;
	}
}

void	set_background(t_env data)
{
	if (data.config.debug == 1 && data.config.project_type == PC)
		fill_background(data, 0);
	else if (data.config.black_white == 0)
		fill_background(data, data.background_color);
	else
		fill_background(data, 0xFFFFFF);
}
