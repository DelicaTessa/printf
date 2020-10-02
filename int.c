/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/26 10:50:14 by tclement      #+#    #+#                 */
/*   Updated: 2020/08/30 16:57:15 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_put_nbr(t_info *info, long long n)
{
	if (n < -9 || n > 9)
		ft_put_nbr(info, n / 10);
	if (n < 0)
		ft_put_char(info, -(n % 10) + '0');
	else
		ft_put_char(info, (n % 10) + '0');
}

void	ft_put_uint(t_info *info, unsigned long long n)
{
	if (n > 9)
		ft_put_uint(info, n / 10);
	n = n % 10;
	ft_put_char(info, (n % 10) + '0');
}

void	ft_set_int(t_info *info, long long n)
{
	if (n < 0)
		info->minus = 1;
	if (n == 0 && info->prec == 0)
		info->width++;
	if (info->prec >= 0 && info->flag == '0')
		info->flag = 0;
	info->prec = info->prec - ft_int_len(n);
	info->width = info->width - ft_int_len(n);
	if (info->prec >= 0)
		info->width = info->width - info->prec;
	if (n < 0 || info->plus == '+' || info->space == ' ')
		info->width--;
}

void	ft_print_int(t_info *info, long long n)
{
	int prec;

	prec = info->prec;
	ft_set_int(info, n);
	if (n >= 0 && info->space == ' ' && info->flag != '0' && info->plus != '+')
		ft_put_char(info, ' ');
	if (info->flag != '-')
		ft_put_width(info, ' ');
	if (n < 0 && info->flag != '0')
		ft_put_char(info, '-');
	if (info->plus == '+' && info->flag != '0' && n >= 0)
		ft_put_char(info, '+');
	ft_put_prec(info, '0');
	if (n != 0 || prec != 0)
		ft_put_nbr(info, n);
	if (info->flag == '-')
		ft_put_width(info, ' ');
}

void	ft_print_uint(t_info *info, unsigned long long n)
{
	unsigned long long	len;
	int					prec;

	len = ft_uint_len(n);
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
	if (info->flag != '-')
		ft_put_width(info, ' ');
	ft_put_prec(info, '0');
	if (n != 0 || prec != 0)
		ft_put_uint(info, n);
	if (info->flag == '-')
		ft_put_width(info, ' ');
}
