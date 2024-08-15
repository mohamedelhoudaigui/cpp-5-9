/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:29:57 by mel-houd          #+#    #+#             */
/*   Updated: 2024/07/29 15:34:05 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
	*this = other;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	this->target = other.target;
	return (*this);
}

//--------------------------------------------------------------------------------


void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	else if (!this->getStatus())
		throw FormNotSigned();
	std::string	file_name = this->target + "_shrubbery";
	std::ofstream	file;
	file.open(file_name);
	if (!file.is_open())
		throw FileOpenError();

	file << "                                                        ." << "\n";
	file << "                                             .         ;  " << "\n";
	file << "                .              .              ;%     ;;   " << "\n";
	file << "                  ,           ,                :;%  %;   " << "\n";
	file << "                   :         ;                   :;%;'     .,   " << "\n";
	file << "          ,.        %;     %;            ;        %;'    ,;" << "\n";
	file << "            ;       ;%;  %%;        ,     %;    ;%;    ,%'" << "\n";
	file << "             %;       %;%;      ,  ;       %;  ;%;   ,%;' " << "\n";
	file << "              ;%;      %;        ;%;        % ;%;  ,%;'" << "\n";
	file << "               `%;.     ;%;     %;'         `;%%;.%;'" << "\n";
	file << "                `:;%.    ;%%. %@;        %; ;@%;%'" << "\n";
	file << "                   `:%;.  :;bd%;          %;@%;'" << "\n";
	file << "                     `@%:.  :;%.         ;@@%;'  "  << "\n";
	file << "                       `@%.  `;@%.      ;@@%;     "     << "\n";
	file << "                         `@%%. `@%%    ;@@%;       "  << "\n";
	file << "                           ;@%. :@%%  %@@%;       " << "\n";
	file << "                             %@bd%%%bd%%:;     " << "\n";
	file << "                               #@%%%%%:;;" << "\n";
	file << "                               %@@%%%::;" << "\n";
	file << "                               %@@@%(o);  . '         " << "\n";
	file << "                               %@@@o%;:(.,'         " << "\n";
	file << "                           `.. %@@@o%::;         " << "\n";
	file << "                              `)@@@o%::;         " << "\n";
	file << "                               %@@(o)::;        " << "\n";
	file << "                              .%@@@@%::;         " << "\n";
	file << "                              ;%@@@@%::;.         "  << "\n";
	file << "                             ;%@@@@%%:;;;. " << "\n";
	file << "                         ...;%@@@@@%%:;;;;,.. " << "\n";
	file.close();
}

const char*	ShrubberyCreationForm::FileOpenError::what() const throw()
{
	return ("Error oppening file !");
}