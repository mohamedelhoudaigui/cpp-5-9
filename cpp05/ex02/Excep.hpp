/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Excep.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:16:22 by mel-houd          #+#    #+#             */
/*   Updated: 2024/07/29 15:26:14 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEP_HPP
#define EXCEP_HPP

#include <exception>
#include <iostream>
#include <string>

class GradeTooHighException : public std::exception
{
	public:
		const char* what() const _NOEXCEPT;
};

class GradeTooLowException : public std::exception
{
	public:
		const char* what() const _NOEXCEPT;
};

class FileOpenError : public std::exception
{
	public:
		const char* what() const _NOEXCEPT;
};

#endif