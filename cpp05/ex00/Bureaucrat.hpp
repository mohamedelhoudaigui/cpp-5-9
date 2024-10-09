/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 00:47:05 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/08 03:33:30 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat(std::string Name, int Grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & src );

		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};

		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};

		int			GetGrade() const;
		std::string	GetName() const;
		void		IncrGrade();
		void		DecrGrade();

	private:

		const std::string	Name;
		int					Grade;
		

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif