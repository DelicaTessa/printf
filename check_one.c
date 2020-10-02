/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_one.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/26 10:49:56 by tclement      #+#    #+#                 */
/*   Updated: 2020/08/28 09:22:03 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_check_flag(t_info *info, const char **format)
{
	while (**format != '\0' && !ft_ispositive(**format)
	&& !ft_isalpha_percent(**format) && **format != '.'
	&& **format != '*')
	{
		if (**format == '-')
		{
			info->flag = '-';
			(*format)++;
		}
		else if (**format == '0')
		{
			if (info->flag != '-')
				info->flag = '0';
			(*format)++;
		}
		else
			ft_check_bonus_flag(info, format);
	}
}

void	ft_check_length(t_info *info, const char **format)
{
	while (**format != '\0' && **format != ft_isdigit(**format))
	{
		if (**format == 'l')
		{
			info->length = 3;
			ft_check_ll_hh(info, format);
			if (info->length == 4)
				(*format)++;
		}
		else if (**format == 'h')
		{
			info->length = 1;
			ft_check_ll_hh(info, format);
			if (info->length == 2)
				(*format)++;
		}
		else
			return ;
	}
}

void	ft_check_ll_hh(t_info *info, const char **format)
{
	(*format)++;
	if (**format == 'l' && info->length == 3)
		info->length = 4;
	else if (**format == 'h' && info->length == 1)
		info->length = 2;
}

void	ft_check_bonus_flag(t_info *info, const char **format)
{
	while (**format != '\0' && !ft_ispositive(**format)
	&& !ft_isalpha_percent(**format) && **format != '.'
	&& **format != '*')
	{
		if (**format == '+')
		{
			info->plus = '+';
			(*format)++;
		}
		else if (**format == ' ')
		{
			info->space = ' ';
			(*format)++;
		}
		else if (**format == '#')
		{
			info->hash = '#';
			(*format)++;
		}
		else
			return ;
	}
}

void	ft_check_width(t_info *info, va_list args, const char **format)
{
	while (**format != '\0' && !ft_isalpha_percent(**format) && **format != '.')
	{
		if (ft_ispositive(**format))
		{
			info->width = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else if (**format == '*')
		{
			info->width = va_arg(args, unsigned int);
			if (info->width < 0)
			{
				info->flag = '-';
				info->width *= -1;
			}
			(*format)++;
		}
	}
}
