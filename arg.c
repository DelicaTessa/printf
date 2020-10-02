/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/26 10:49:38 by tclement      #+#    #+#                 */
/*   Updated: 2020/08/26 12:45:17 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_hexupper_arg(t_info *info, va_list args)
{
	unsigned long long n;

	if (info->length == 0)
		n = va_arg(args, unsigned int);
	else if (info->length == 1)
		n = (unsigned short)va_arg(args, unsigned int);
	else if (info->length == 2)
		n = (unsigned char)va_arg(args, unsigned int);
	else if (info->length == 3)
		n = va_arg(args, unsigned long);
	else if (info->length == 4)
		n = va_arg(args, unsigned long long);
	else
		return ;
	ft_print_hexupper(info, n);
}

void	ft_hexlower_arg(t_info *info, va_list args)
{
	unsigned long long n;

	if (info->length == 0)
		n = va_arg(args, unsigned int);
	else if (info->length == 1)
		n = (unsigned short)va_arg(args, unsigned int);
	else if (info->length == 2)
		n = (unsigned char)va_arg(args, unsigned int);
	else if (info->length == 3)
		n = va_arg(args, unsigned long);
	else if (info->length == 4)
		n = va_arg(args, unsigned long long);
	else
		return ;
	ft_print_hexlower(info, n);
}

void	ft_uint_arg(t_info *info, va_list args)
{
	unsigned long long n;

	if (info->length == 0)
		n = va_arg(args, unsigned int);
	else if (info->length == 1)
		n = (unsigned short)va_arg(args, unsigned int);
	else if (info->length == 2)
		n = (unsigned char)va_arg(args, unsigned int);
	else if (info->length == 3)
		n = va_arg(args, unsigned long);
	else if (info->length == 4)
		n = va_arg(args, unsigned long long);
	else
		return ;
	ft_print_uint(info, n);
}

void	ft_n_arg(t_info *info, va_list args)
{
	int *n;

	n = va_arg(args, int *);
	ft_print_n(info, n);
}

void	ft_int_arg(t_info *info, va_list args)
{
	long long n;

	if (info->length == 0)
		n = va_arg(args, int);
	else if (info->length == 1)
		n = (short)va_arg(args, int);
	else if (info->length == 2)
		n = (char)va_arg(args, int);
	else if (info->length == 3)
		n = va_arg(args, long);
	else if (info->length == 4)
		n = va_arg(args, long long);
	else
		return ;
	ft_print_int(info, n);
}
