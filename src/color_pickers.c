/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pickers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:44:03 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/09 17:15:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	put_red_picker(t_env data)
{
	int		x;
	int		y;
	float	k;

	y = 398;
	while (y <= 437)
	{
		x = 15;
		k = 0;
		while (x <= 177)
		{
			if (x < 15 || x > 175 || y < 400 || y > 435)
				data.img.str[y * data.config.s_width + x] = 0x303030;
			else
				data.img.str[y * data.config.s_width + x] = 65536 * (int)((k /
						160) * 255);
			x++;
			k++;
		}
		y++;
	}
}

void	put_green_picker(t_env data)
{
	int		x;
	int		y;
	float	k;

	y = 440;
	while (y <= 479)
	{
		x = 15;
		k = 0;
		while (x <= 177)
		{
			if (x < 15 || x > 175 || y < 442 || y > 477)
				data.img.str[y * data.config.s_width + x] = 0x303030;
			else
				data.img.str[y * data.config.s_width + x] = 256 * (int)((k /
						160) * 255);
			x++;
			k++;
		}
		y++;
	}
}

void	put_blue_picker(t_env data)
{
	int		x;
	int		y;
	float	k;

	y = 482;
	while (y <= 521)
	{
		x = 15;
		k = 0;
		while (x <= 177)
		{
			if (x < 15 || x > 175 || y < 482 || y > 519)
				data.img.str[y * data.config.s_width + x] = 0x303030;
			else
				data.img.str[y * data.config.s_width + x] = (int)((k / 160)
						* 255);
			x++;
			k++;
		}
		y++;
	}
}

void	put_color_pickers(t_env data)
{
	put_red_picker(data);
	put_green_picker(data);
	put_blue_picker(data);
}
