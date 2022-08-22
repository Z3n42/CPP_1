# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tests.feature                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 14:18:24 by ingonzal          #+#    #+#              #
#    Updated: 2022/08/22 16:51:46 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Feature: Searching data at the site

	Background:
		Given The user tries to connect to the site

	Scenario Outline: 
		Given The user is searching who is the owner
		When The user searches for the newspapers owned by {arg}, the response {ans} is returned
		Then the parser return the newspapers organized by owner

		Examples: Owners
		| arg							| ans					|
		| Unidad Editorial S.A.			| El Mundo				|
		| PRISA							| El Pais,AS			|
		| Unidad Editorial				| Marca					|
		| News UK Independent			| The Sun				|
		| Telegraph Media Group			| The Daily Telegraph	|
		| The New York Times Company	| The New York Times	|
		| Warner Bros. Discovery		| CNN International		|
		| People's Daily				| Global Times			|
