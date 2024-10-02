/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:06:58 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/01 19:24:38 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data* ptr) {
	return uintptr_t(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw) {
	return static_cast<Data*>(reinterpret_cast<void*>(raw));
}