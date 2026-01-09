/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:12:23 by rchaumei          #+#    #+#             */
/*   Updated: 2025/11/20 17:38:36 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putnbr_hex_lower(long n, int fd);
int	ft_putnbr_hex_upper(long n, int fd);
int	ft_putptr(void *ptr, int fd);
int	ft_printf(const char *s, ...);
int	ft_print_str(char *s, int fd);
int	ft_print_char(char c, int fd);
int	ft_print_num(long int nb, int fd);
int	ft_conversion(char c, va_list ap);
int	ft_putunsigned_lower(unsigned int n, int fd);
int	ft_putunsigned_upper(unsigned int n, int fd);
int	ft_putadress(unsigned long nb, int fd);

#endif