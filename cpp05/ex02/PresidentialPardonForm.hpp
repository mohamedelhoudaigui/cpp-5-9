/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:54:39 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/08 10:54:40 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.cpp"


class PresidentialPardonForm : public AForm
{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm( PresidentialPardonForm const & src );
		~PresidentialPardonForm();

		std::string	GetTarget() const;

		class	FormNotSignedException: public std::exception {
			public:
				const char* what() const throw();
		};

		class	GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};

		PresidentialPardonForm&		operator=( PresidentialPardonForm const & src );
		void	execute(const Bureaucrat & executor);

	private:
		std::string	target;

};

#endif