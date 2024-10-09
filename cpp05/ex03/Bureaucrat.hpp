/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:30:27 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/09 21:30:29 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class AForm;


class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat(std::string Name, int Grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();
		Bureaucrat &		operator=( Bureaucrat const & src );

		int			GetGrade() const;
		std::string	GetName() const;
		void		IncrGrade();
		void		DecrGrade();

		void		signForm(AForm& f) const;
		void		executeForm(AForm const & form) const;
	
		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};


	private:

		const std::string	Name;
		int					Grade;
		

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif