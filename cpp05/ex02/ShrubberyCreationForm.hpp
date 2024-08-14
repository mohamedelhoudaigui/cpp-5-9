/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:29:59 by mel-houd          #+#    #+#             */
/*   Updated: 2024/07/29 15:24:21 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <exception>
#include <iostream>
#include <string>
#include <fstream>

#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		void	execute(const Bureaucrat& executor) const;

		class FileOpenError : public std::exception
		{
			public:
				const char* what() const throw();
		};

		std::string	target;
};

#endif