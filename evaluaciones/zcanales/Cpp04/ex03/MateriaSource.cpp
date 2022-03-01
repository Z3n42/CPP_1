/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:22:30 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/16 11:22:30 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// ************************************************************************** //
//                    	   	 Basic                                             //
// ************************************************************************** //
MateriaSource::MateriaSource(void) :_idxLearn(0){
    std::cout << "(MateriaSource) Default constructor called" << std::endl;
    int i = -1;
    while (++i < 4)
        _arrayLearn[i] = NULL;
}
MateriaSource::MateriaSource(MateriaSource const &src) {
    std::cout << "(MateriaSource) Copy constructor called" << std::endl;
    *this = src;
}
MateriaSource::~MateriaSource(void){
   std::cout << "(MateriaSource) Destructor called" << std::endl;
    int i;
    i = -1;
    while (++i < _idxLearn)
        delete _arrayLearn[i];
}
// ************************************************************************** //
//                Overload operator                                          //
// ************************************************************************** //
MateriaSource &MateriaSource::operator=(const MateriaSource &raw){
    std::cout << "(MateriaSource) Assigment operator called" << std::endl; 
    if (this != &raw)
     {
        int i = -1;   
        while (++i < _idxLearn)
            delete _arrayLearn[i];
        this->_idxLearn = raw._idxLearn;
        i = -1;
        while (++i < _idxLearn)
            _arrayLearn[i] = raw._arrayLearn[i]->clone();    
     }
     return (*this);
}
// ************************************************************************** //
//                IMateriaSource's Pure Virtual Functions                     //
// ************************************************************************** //
//LEARN MATERIA
//Guarda la direccion de src. Como se utiliza en otra funcion (createMaeria)
void MateriaSource::learnMateria(AMateria* src){
    if (_idxLearn == 4)
    {
        delete src;
         std::cout << "[❌]Cannot learn, maximum materia to learn (4) reached!"  << std::endl;
        return ;
        }
    _arrayLearn[_idxLearn] = src;
    std::cout << "[💭]Materia learned. Type: "<< _arrayLearn[_idxLearn]->getType() << ". Number[" << _idxLearn <<"]" <<std::endl;
    _idxLearn += 1;
}
//CREATE MATERIA
//1. Search if it is in the invententory
//2. Clone 
//Must be able to lern "template" -->Al ser una funcion virtual->Se clona en la clase que es.
AMateria* MateriaSource::createMateria(std::string const & type){
    std::string temp;
    int i;

    i = -1;
    while (++i < _idxLearn)
    {
        temp = _arrayLearn[i]->getType();
        if (!type.compare(temp))
        {   
            std::cout << "[🧱]Materia created in the Materia Source!"  << std::endl;
            return (_arrayLearn[i]->clone());
        }
    }
    std::cout << "[❌]Cannot create in the Materia Source, this materia is not learned yet"  << std::endl;
    return (0);
}