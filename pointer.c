/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pointer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/26 10:50:26 by tclement      #+#    #+#                 */
/*   Updated: 2020/08/30 08:55:19 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_put_pointer(t_info *info, unsigned long n)
{
	if (n == 0 && info->prec == 0)
		return ;
	if (n >= 16)
		ft_put_pointer(info, n / 16);
	n %= 16;
	if (n > 9)
		n += 87;
	else
		n += '0';
	if (!info->error)
		ft_put_char(info, n);
}

void	ft_print_pointer(t_info *info, unsigned long n)
{
	unsigned long long len;

	len = ft_hex_len(n);
	info->prec = info->prec - len;
	if (n == 00)
		info->width = info->width + 1;
	if (n == 0 && info->prec == 0)
		info->width++;
	if (info->prec >= 0 && info->flag == '0')
		info->flag = ' ';
	if (info->prec >= 0)
		info->width = info->width - info->prec - len - 2;
	else
		info->width = info->width - len - 2;
	if (info->flag == 0 || info->flag == ' ')
		ft_put_width(info, ' ');
	ft_put_str(info, "0x", 2);
	if (info->flag == '0')
		ft_put_width(info, '0');
	ft_put_prec(info, '0');
	ft_put_pointer(info, n);
	if (info->flag == '-')
		ft_put_width(info, ' ');
}
