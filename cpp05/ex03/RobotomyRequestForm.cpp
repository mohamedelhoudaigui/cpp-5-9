/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:30:01 by mel-houd          #+#    #+#             */
/*   Updated: 2024/08/14 06:15:29 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	AForm::operator=(other);
	this->target = other.target;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	else if (!this->getStatus())
		throw FormNotSigned();
	srand(time(0));
	if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully\n";
	else
		std::cout << this->target << " has failed to be robotomized\n";
}