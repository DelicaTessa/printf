/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/26 10:50:09 by tclement      #+#    #+#                 */
/*   Updated: 2020/08/28 15:10:04 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_put_hexupper(t_info *info, unsigned long long n)
{
	if (n >= 16)
		ft_put_hexupper(info, n / 16);
	n = n % 16;
	if (n >= 10 && n <= 15)
	{
		if (n == 10)
			ft_put_char(info, 'A');
		else if (n == 11)
			ft_put_char(info, 'B');
		else if (n == 12)
			ft_put_char(info, 'C');
		else if (n == 13)
			ft_put_char(info, 'D');
		else if (n == 14)
			ft_put_char(info, 'E');
		else if (n == 15)
			ft_put_char(info, 'F');
		else
			ft_put_char(info, (n % 16) + '0');
	}
	else
		ft_put_char(info, (n % 16) + '0');
}

void	ft_put_hexlower(t_info *info, unsigned long long n)
{
	if (n >= 16)
		ft_put_hexlower(info, n / 16);
	n = n % 16;
	if (n >= 10 && n <= 15)
	{
		if (n == 10)
			ft_put_char(info, 'a');
		else if (n == 11)
			ft_put_char(info, 'b');
		else if (n == 12)
			ft_put_char(info, 'c');
		else if (n == 13)
			ft_put_char(info, 'd');
		else if (n == 14)
			ft_put_char(info, 'e');
		else if (n == 15)
			ft_put_char(info, 'f');
		else
			ft_put_char(info, (n % 16) + '0');
	}
	else
		ft_put_char(info, (n % 16) + '0');
}

void	ft_set_hex(t_info *info, unsigned long long n)
{
	unsigned long long	len;
	int					prec;

	len = ft_hex_len(n);
	prec = info->prec;
	info->prec = info->prec - len;
	if (n == 0 && prec == 0)
		info->width++;
	if (prec >= 0 && info->flag == '0')
		info->flag = ' ';
	if (info->prec >= 0)
		info->width = info->width - info->prec - len;
	else
		info->width = info->width - len;
	if (info->hash == '#' && n != 0)
		info->width = info->width - 2;
}

void	ft_print_hexupper(t_info *info, unsigned long long n)
{
	int					prec;

	prec = info->prec;
	ft_set_hex(info, n);
	if (info->flag != '-' && info->flag != '0')
		ft_put_width(info, ' ');
	if (info->hash == '#' && n != 0)
		ft_put_str(info, "0X", 2);
	if (info->flag == '0')
		ft_put_width(info, '0');
	ft_put_prec(info, '0');
	if (n != 0 || prec != 0)
		ft_put_hexupper(info, n);
	if (info->flag == '-')
		ft_put_width(info, ' ');
}

void	ft_print_hexlower(t_info *info, unsigned long long n)
{
	int					prec;

	prec = info->prec;
	ft_set_hex(info, n);
	if (info->flag != '-' && info->flag != '0')
		ft_put_width(info, ' ');
	if (info->hash == '#' && n != 0)
		ft_put_str(info, "0x", 2);
	if (info->flag == '0')
		ft_put_width(info, '0');
	ft_put_prec(info, '0');
	if (n != 0 || prec != 0)
		ft_put_hexlower(info, n);
	if (info->flag == '-')
		ft_put_width(info, ' ');
}
