/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:31:01 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/09 21:31:02 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <ctime>
# include <cstdlib>

class RobotomyRequestForm: public AForm
{

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm();

		std::string	GetTarget() const;

		class	FormNotSignedException: public std::exception {
			public:
				const char* what() const throw();
		};

		class	GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & src );
		void	execute(const Bureaucrat & executor) const;

	private:
		std::string	target;
};

#endif