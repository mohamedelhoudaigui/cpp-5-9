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

#include "Form.hpp"

class	ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		std::string	getTarget() const;
		std::string	getSignGrade() const;
		std::string	getExecGrade() const;

		void	execute(const Bureaucrat& executor);
		
	private:
		unsigned int	execGrade;
		unsigned int	signGrade;
		std::string		target;
};



#endif