/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/26 12:33:41 by tclement      #+#    #+#                 */
/*   Updated: 2020/10/02 16:13:53 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_n(t_info *info, int *n)
{
	int temp;

	temp = info->count;
	*n = temp;
}

void	ft_print_type(t_info *info, va_list args)
{
	if (info->spec == 1)
		ft_print_char(info, va_arg(args, int));
	else if (info->spec == 2)
		ft_print_percent(info);
	else if (info->spec == 3)
		ft_print_str(info, va_arg(args, char *));
	else if (info->spec == 4)
		ft_int_arg(info, args);
	else if (info->spec == 5)
		ft_hexlower_arg(info, args);
	else if (info->spec == 6)
		ft_hexupper_arg(info, args);
	else if (info->spec == 7)
		ft_uint_arg(info, args);
	else if (info->spec == 8)
		ft_print_pointer(info, va_arg(args, unsigned long));
	else if (info->spec == 0)
		info->error = -1;
}

void	ft_print_bonustype(t_info *info, va_list args)
{
	if (info->spec == 9)
		ft_n_arg(info, args);
	if (info->spec == 10)
		ft_oct_arg(info, args);
}
