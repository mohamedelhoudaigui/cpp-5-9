/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 03:59:16 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/08 04:10:39 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>


class Bureaucrat;

class Form
{

	public:

		Form();
		Form(std::string Name, int GSign, int GExec);
		Form( Form const & src );
		~Form();
		Form &		operator=( Form const & src );

		std::string	GetName()	const;
		bool		GetStatus()	const;
		int			GetGSign()	const;
		int			GetGExec()	const;
		void		beSigned(const Bureaucrat& b);

		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};

		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};

	private:
		const std::string	Name;
		const int			GSign;
		const int			GExec;
		bool				Signed;

};

std::ostream&			operator<<( std::ostream & o, Form const & i );

#endif