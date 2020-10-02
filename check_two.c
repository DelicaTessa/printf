/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_two.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/26 10:50:01 by tclement      #+#    #+#                 */
/*   Updated: 2020/10/02 16:12:38 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_check_precision(t_info *info, va_list args, const char **format)
{
	while (**format != '\0' && !ft_isalpha_percent(**format))
	{
		if (**format == '.')
			info->prec = 0;
		(*format)++;
		if (ft_ispositive(**format))
		{
			info->prec = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else if (**format == '*')
		{
			info->prec = va_arg(args, unsigned int);
			(*format)++;
		}
	}
}

void	ft_check_specifier(t_info *info, va_list args, const char **format)
{
	ft_check_manspec(info, format);
	if (info->spec >= 0 && info->spec < 9 && info->error != -1)
		ft_print_type(info, args);
	else if (info->spec >= 9 && info->error != -1)
		ft_print_bonustype(info, args);
	else if (info->error == -1)
		return ;
}

void	ft_check_manspec(t_info *info, const char **format)
{
	if (**format == 'c')
		info->spec = 1;
	else if (**format == '%')
		info->spec = 2;
	else if (**format == 's')
		info->spec = 3;
	else if (**format == 'd' || **format == 'i')
		info->spec = 4;
	else if (**format == 'x')
		info->spec = 5;
	else if (**format == 'X')
		info->spec = 6;
	else if (**format == 'u')
		info->spec = 7;
	else if (**format == 'p')
		info->spec = 8;
	else
		info->spec = 0;
	if (info->spec == 0)
		ft_check_bonusspec(info, format);
}

void	ft_check_bonusspec(t_info *info, const char **format)
{
	if (**format == 'n')
		info->spec = 9;
	else if (**format == 'o')
		info->spec = 10;
	else
	{
		info->spec = -1;
		info->error = -1;
	}
}
