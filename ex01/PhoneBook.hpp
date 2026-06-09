/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:59:39 by louka             #+#    #+#             */
/*   Updated: 2026/06/09 15:41:19 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

class PhoneBook {
private:
    Contact _contacts[8];
    int     _count;
    int     _current_index;
    std::string _format_string(std::string str) const;

public:
    PhoneBook();
    ~PhoneBook();
    void add_contact();
    void search_contact();
};

#endif