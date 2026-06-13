/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:04:03 by louka             #+#    #+#             */
/*   Updated: 2026/06/13 13:33:33 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_info(std::string fn, std::string ln, std::string nn, std::string num, std::string sc)
{
    _first_name = fn;
    _last_name = ln;
    _nickname = nn;
    _phone_number = num;
    _darkest_secret = sc;
}

std::string Contact::get_first_name() const 
{
    return (_first_name);
}

std::string Contact::get_last_name() const
{
    return (_last_name);
}

std::string Contact::get_nickname() const
{
    return (_nickname);
}

std::string Contact::get_phone_number() const
{
    return (_phone_number);
}

std::string Contact::get_darkest_secret() const
{
    return (_darkest_secret);
}