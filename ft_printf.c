/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/04 18:39:01 by tclement      #+#    #+#                 */
/*   Updated: 2020/10/02 16:17:52 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_reset_info(t_info *info)
{
	info->spec = 0;
	info->prec = -1;
	info->width = -1;
	info->minus = 0;
	info->flag = 0;
	info->plus = 0;
	info->hash = 0;
	info->space = 0;
	info->length = 0;
}

t_info	*ft_set_info(void)
{
	t_info *new;

	new = malloc(sizeof(t_info));
	if (new == NULL)
		return (NULL);
	new->count = 0;
	new->error = 0;
	new->spec = 0;
	new->prec = -1;
	new->width = -1;
	new->minus = 0;
	new->flag = 0;
	new->plus = 0;
	new->hash = 0;
	new->space = 0;
	new->length = 0;
	return (new);
}

int		ft_print_stdout(t_info *info, const char **format, va_list args)
{
	while (**format != '\0')
	{
		if (**format == '%')
		{
			(*format)++;
			ft_check_flag(info, format);
			ft_check_width(info, args, format);
			ft_check_precision(info, args, format);
			ft_check_length(info, format);
			ft_check_specifier(info, args, format);
			if (info->error == -1)
				return (-1);
			else
				ft_reset_info(info);
		}
		else if (info->error != -1)
			ft_put_char(info, **format);
		else
			return (-1);
		(*format)++;
	}
	return (info->count);
}

int		ft_printf(const char *format, ...)
{
	t_info	*info;
	va_list	args;
	int		res;

	res = 0;
	va_start(args, format);
	info = ft_set_info();
	if (info == NULL)
		res = -1;
	if (res != -1)
		res = ft_print_stdout(info, &format, args);
	va_end(args);
	free(info);
	if (res == -1)
		return (-1);
	else
		return (res);
}
