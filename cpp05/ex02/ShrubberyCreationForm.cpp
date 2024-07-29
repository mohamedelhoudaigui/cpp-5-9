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
#include "Excep.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : execGrade(137), signGrade(145)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
	*this = other;
}

ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other)
{
	this->target = other.getTarget();
	this->execGrade = other.getExecGrade();
	this->signGrade = other.getSignGrade();
	return (*this);
}

//--------------------------------------------------------------------------------


void	ShrubberyCreationForm::execute(const Bureaucrat& executor)
{
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


//----------------------------------------------------------------------------------

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

std::string	ShrubberyCreationForm::getExecGrade() const
{
	return (this->execGrade);
}

std::string	ShrubberyCreationForm::getSignGrade() const
{
	return (this->signGrade);
}