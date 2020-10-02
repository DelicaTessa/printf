/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/26 10:49:45 by tclement      #+#    #+#                 */
/*   Updated: 2020/08/28 09:05:37 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_put_char(t_info *info, char c)
{
	ssize_t byteswritten;

	byteswritten = write(1, &c, 1);
	if (byteswritten == -1)
		info->error = -1;
	info->count++;
}

void	ft_put_str(t_info *info, char *s, int len)
{
	int index;

	index = 0;
	if (s == NULL)
		s = "(null)";
	while (s[index] != '\0' && index < len)
	{
		ft_put_char(info, s[index]);
		index++;
	}
}

void	ft_print_char(t_info *info, char c)
{
	info->width--;
	if (info->flag != '-')
	{
		ft_put_width(info, ' ');
		ft_put_char(info, c);
	}
	else if (info->flag == '-')
	{
		ft_put_char(info, c);
		ft_put_width(info, ' ');
	}
}

void	ft_print_percent(t_info *info)
{
	info->width--;
	if (info->flag != '-')
	{
		ft_put_width(info, ' ');
		ft_put_char(info, '%');
	}
	else if (info->flag == '-')
	{
		ft_put_char(info, '%');
		ft_put_width(info, ' ');
	}
}

void	ft_print_str(t_info *info, char *str)
{
	int len;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (info->prec >= 0 && info->prec < len)
		len = info->prec;
	info->width = info->width - len;
	if (info->flag != '-')
		ft_put_width(info, ' ');
	ft_put_str(info, str, len);
	if (info->flag == '-')
		ft_put_width(info, ' ');
}
