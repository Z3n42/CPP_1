/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:18:03 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/16 11:18:06 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
// ************************************************************************** //
//                    	   	 Basic                                             //
// ************************************************************************** //
Character::Character(void) : _idx(0){
    int i = -1;
    while (++i < 4)  
        _array_materia[i] = NULL;
    std::cout << "(Character) Default constructor called" << std::endl;
}
Character::Character(std::string name) : _idx(0), _name(name){
    int i = -1;
    while (++i < 4)
        _array_materia[i] = NULL;
    std::cout << "(Character) Parameter constructor called" << std::endl;
}
//Lama a la funcin deep copy
Character::Character(Character const &src){
   std::cout << "(Character) Copy constructor called" << std::endl;
    *this = src;
}
//Se ha echo una copia deep, quiere decir que tenemos variblas en Heap
Character::~Character(void){
    int i;
    i= -1;
    while (++i < _idx)
        delete _array_materia[i];
    std::cout << "(Character) Destructor called" << std::endl;
}
//DEEP COPY
 Character &Character::operator=(const Character &raw){
    std::cout << "(Character) Assigment operator called" << std::endl; 
 	if (this != &raw)
     {
        int i = -1;   
		this->_name = raw._name;
        while (++i < _idx)
            delete _array_materia[i];
        this->_idx= raw._idx;
        i = -1;
        while (++i < _idx)
            _array_materia[i] = raw._array_materia[i]->clone();
         
     }
     return (*this);
 }
// ************************************************************************** //
//                ICharacter's Pure Virtual Functions                         //
// ************************************************************************** //
std::string const & Character::getName() const{
    return (_name);
}
void Character::equip(AMateria* m){
    AMateria *c;
    if ( _idx > 3 || _idx < 0)
    {
        delete m;
        std::cout << "[❌]Cannot equiped, inventory if full!"  << std::endl;
        return; 
    }
    c = m->clone();
    _array_materia[_idx] = c;
    delete m;
    (*_array_materia[_idx]).setAvailable(1);
    std::cout << "[📥]Materia equiped. Type: " << (*_array_materia[_idx]).getType() << ". Number[" << _idx <<"]"<< std::endl;
    _idx += 1;
}
void Character::unequip(int idx){
    if (idx > _idx || idx < 0)
        std::cout << "[❌]Could not unequip. Number[" << idx <<"] is not created or invalid argument" << std::endl;
    else
    {
        (*_array_materia[idx]).setAvailable(0);
         std::cout << "[📤]Materia unequiped: " << (*_array_materia[idx]).getType() << std::endl;
    }
}
void Character::use(int idx, ICharacter& target){
    if (idx > _idx || idx < 0)
    {  
        std::cout << "[❌]"<< target.getName() <<" could not use. Number[" << idx <<"] is not created or invalid argument" << std::endl;
        return ;
    }
    if ((*_array_materia[idx]).getAvailable() == 1)
        (*_array_materia[idx]).use(target);
    else
        std::cout << "[❌]"<< target.getName() <<" could not use. Number[" << idx <<"] is unequipped" << std::endl;
}