/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   width_prec.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/26 11:03:57 by tclement      #+#    #+#                 */
/*   Updated: 2020/08/29 08:44:51 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_put_width(t_info *info, char c)
{
	if ((info->flag != '0' && info->flag != '-'))
		c = ' ';
	if (info->flag == '0')
	{
		if (info->plus == '+' && info->minus != 1 && info->spec == 4)
			ft_put_char(info, '+');
		if (info->space == ' ' && info->minus != 1 && info->spec != 4 \
			&& info->spec != 2)
			ft_put_char(info, ' ');
		if (info->spec == 4)
		{
			if (info->space == ' ' && info->minus != 1 && info->plus != '+')
				ft_put_char(info, ' ');
		}
		c = '0';
	}
	if (info->minus == 1 && info->flag == '0' && info->spec == 4)
		ft_put_char(info, '-');
	while (info->width > 0)
	{
		ft_put_char(info, c);
		info->width--;
	}
}

void	ft_put_prec(t_info *info, char c)
{
	while (info->prec > 0)
	{
		ft_put_char(info, c);
		info->prec--;
	}
}
