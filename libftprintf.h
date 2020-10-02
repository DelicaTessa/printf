/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/04 18:39:18 by tclement      #+#    #+#                 */
/*   Updated: 2020/10/02 16:13:27 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct		s_info
{
	int			width;
	int			prec;
	int			length;
	int			spec;
	long long	count;
	int			error;
	int			minus;
	char		flag;
	char		plus;
	char		hash;
	char		space;
}					t_info;

void				ft_put_char(t_info *info, char c);
void				ft_put_str(t_info *info, char *s, int len);
void				ft_put_nbr(t_info *info, long long n);
void				ft_put_uint(t_info *info, unsigned long long n);
void				ft_put_hexupper(t_info *info, unsigned long long n);
void				ft_put_hexlower(t_info *info, unsigned long long n);
void				ft_put_pointer(t_info *info, unsigned long n);
void				ft_put_width(t_info *info, char c);
void				ft_put_prec(t_info *info, char c);
void				ft_put_oct(t_info *info, unsigned long long n, \
					int checkzero);

void				ft_set_hex(t_info *info, unsigned long long n);
void				ft_set_int(t_info *info, long long n);
void				ft_set_oct(t_info *info, unsigned long long n, \
					unsigned long long len);
void				ft_set_oct_hash(t_info *info, unsigned long long len, \
					unsigned long long prec);


void				ft_print_type(t_info *info, va_list args);
void				ft_print_bonustype(t_info *info, va_list args);
void				ft_print_char(t_info *info, char c);
void				ft_print_str(t_info *info, char *str);
void				ft_print_percent(t_info *info);
void				ft_print_int(t_info *info, long long n);
void				ft_print_uint(t_info *info, unsigned long long n);
void				ft_print_hexupper(t_info *info, unsigned long long n);
void				ft_print_hexlower(t_info *info, unsigned long long n);
void				ft_print_pointer(t_info *info, unsigned long n);
void				ft_print_n(t_info *info, int *n);
void				ft_print_oct(t_info *info, unsigned long long n);

void				ft_int_arg(t_info *info, va_list args);
void				ft_uint_arg(t_info *info, va_list args);
void				ft_oct_arg(t_info *info, va_list args);
void				ft_hexlower_arg(t_info *info, va_list args);
void				ft_hexupper_arg(t_info *info, va_list args);
void				ft_n_arg(t_info *info, va_list args);

void				ft_check_flag(t_info *info, const char **format);
void				ft_check_bonus_flag(t_info *info, const char **format);
void				ft_check_width(t_info *info, va_list args, \
					const char **format);
void				ft_check_precision(t_info *info, va_list args, \
					const char **format);
void				ft_check_length(t_info *info, const char **format);
void				ft_check_ll_hh(t_info *info, const char **format);
void				ft_check_specifier(t_info *info, va_list args, \
					const char **format);
void				ft_check_manspec(t_info *info, const char **format);
void				ft_check_bonusspec(t_info *info, const char **format);

long long			ft_int_len(long long n);
unsigned long long	ft_hex_len(unsigned long long n);
unsigned long long	ft_uint_len(unsigned long long n);
unsigned long long	ft_oct_len(unsigned long long n);

int					ft_ispositive(int arg);
int					ft_isalpha_percent(int arg);

void				ft_reset_info(t_info *info);
t_info				*ft_set_info(void);
int					ft_print_stdout(t_info *info, const char **format, \
					va_list args);
int					ft_printf(const char *format, ...);

#endif
