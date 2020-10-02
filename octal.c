/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   octal.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/30 16:40:16 by tclement      #+#    #+#                 */
/*   Updated: 2020/09/06 12:28:26 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_put_oct(t_info *info, unsigned long long n, int checkzero)
{
	if (checkzero == 0 && n == 0)
	{
		if (info->hash == '#')
			ft_put_char(info, '0');
		return ;
	}
	if (n > 7)
		ft_put_oct(info, n / 8, checkzero);
	n = n % 8;
	ft_put_char(info, (n % 8) + '0');
}

void	ft_set_oct_hash(t_info *info, unsigned long long len, \
		unsigned long long prec)
{
	unsigned long long width;

	info->prec = info->prec - len;
	if (info->width < 0)
		width = 0;
	else
		width = info->width;
	info->prec--;
	if (prec <= len)
		info->width--;
	if (prec >= len && width < prec)
		info->width = info->width - prec - len;
	if (prec >= len && width >= prec)
		info->width = info->width - prec;
	if (prec < len && width > prec)
		info->width = info->width - len;
	if (prec <= len && width <= prec)
		info->width = 0;
}

void	ft_set_oct(t_info *info, unsigned long long n, unsigned long long len)
{
	unsigned long long	prec;

	if (info->prec < 0)
		prec = 0;
	else
		prec = info->prec;
	if (prec > 0 && info->flag == '0')
		info->flag = ' ';
	if (prec == 0 && info->flag == '0')
		info->flag = '0';
	if (info->hash == '#' && n != 0)
		ft_set_oct_hash(info, len, prec);
	if (n == 0 && prec == 0 && info->hash == '#')
		info->width--;
	else if (info->hash != '#' || n == 0)
	{
		if (n == 0 && info->prec == 0)
			info->width++;
		info->prec = info->prec - len;
		if (info->prec > 0)
			info->width = info->width - info->prec - len;
		else if (info->prec <= 0)
			info->width = info->width - len;
	}
}

void	ft_print_oct(t_info *info, unsigned long long n)
{
	int					checkzero;
	unsigned long long	len;

	checkzero = info->prec;
	len = ft_oct_len(n);
	ft_set_oct(info, n, len);
	if (info->flag != '-')
		ft_put_width(info, ' ');
	if (info->hash == '#' && n != 0)
		ft_put_char(info, '0');
	ft_put_prec(info, '0');
	ft_put_oct(info, n, checkzero);
	if (info->flag == '-')
		ft_put_width(info, ' ');
}

void	ft_oct_arg(t_info *info, va_list args)
{
	unsigned long long n;

	if (info->length == 0)
		n = va_arg(args, unsigned int);
	else if (info->length == 1)
		n = (unsigned short int)va_arg(args, unsigned int);
	else if (info->length == 2)
		n = (unsigned char)va_arg(args, unsigned int);
	else if (info->length == 3)
		n = va_arg(args, unsigned long);
	else if (info->length == 4)
		n = va_arg(args, unsigned long long);
	else
		return ;
	ft_print_oct(info, n);
}
