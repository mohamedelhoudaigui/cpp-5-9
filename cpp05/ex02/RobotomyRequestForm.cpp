/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theworld27 <theworld27@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:56:54 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/09 15:47:13 by theworld27       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ):
AForm(src.GetName(), src.GetGSign(), src.GetGExec()), target(src.GetTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &		RobotomyRequestForm::operator=( RobotomyRequestForm const & src )
{
	if ( this != &src )
	{
		this->target = src.GetTarget();
	}
	return *this;
}

std::string	RobotomyRequestForm::GetTarget() const {
	return (this->target);
}

const char*	RobotomyRequestForm::GradeTooLowException::what() const throw() {
	return ("Grade too low !");
}

const char*	RobotomyRequestForm::FormNotSignedException::what() const throw() {
	return ("Form not signed !");
}

void	RobotomyRequestForm::execute( const Bureaucrat & executor ) const {
	if (this->GetStatus() == false)
		throw FormNotSignedException();
	else if (executor.GetGrade() > this->GetGExec())
		throw GradeTooLowException();
	else {
		srand( time(0) );
		int	RandomNumber = rand() % 2 + 1;
		if ( RandomNumber == 1 ) {
			std::cout << this->target << " has been robotomized successfully\n";
		} else {
			std::cout << "the robotomy failed\n";
		}	
	}
}
