# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tests.feature                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 14:18:24 by ingonzal          #+#    #+#              #
#    Updated: 2022/09/27 17:55:34 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Feature: Searching data at the site

	Background:
		Given The user tries to connect to the site

	#Name Flag
	Scenario Outline: Searching by name 
		Given The user is searching all information about a specific user
		When The user searches for a user named as "<arg>"
		Then all the info "<answer>" is returned

		Examples: Searching by name
		| arg					| answer																																																			|
		| Oormila Bandopadhyay	| {'id': 2533, 'name': 'Oormila Bandopadhyay', 'email': 'bandopadhyay_oormila@jones-schroeder.io', 'gender': 'female', 'status': 'active'}|
		| Prof. Himadri Varrier	| {'id': 2532, 'name': 'Prof. Himadri Varrier', 'email': 'himadri_varrier_prof@mcclure-wehner.com', 'gender': 'female', 'status': 'active'}											|         
		| Marca					| {'Name': 'Marca', 'Type': 'Daily sports newspaper', 'Language': ['Spanish', 'English'], 'Owner': 'Unidad Editorial', 'Website': 'http://www.marca.com', 'Country': 'Spain'}										|
		| AS					| {'Name': 'AS', 'Type': 'Daily sports newspaper', 'Language': ['Spanish'], 'Owner': 'PRISA', 'Website': 'http://as.com', 'Country': 'Spain'}																		|
		| The Sun				| {'Name': 'The Sun', 'Type': 'Daily newspaper', 'Language': ['English'], 'Owner': 'News UK Independent', 'Website': 'https://www.thesun.co.uk', 'Country': 'United Kingdom'}										|
		| The Daily Telegraph	| {'Name': 'The Daily Telegraph', 'Type': 'Daily newspaper', 'Language': ['English'], 'Owner': 'Telegraph Media Group', 'Website': 'https://www.telegraph.co.uk', 'Country': 'United Kingdom'}						|
		| The New York Times	| {'Name': 'The New York Times', 'Type': 'Daily newspaper', 'Language': ['English', 'Spanish', 'Chinese'], 'Owner': 'The New York Times Company', 'Website': 'https://www.nytimes.com', 'Country': 'United States'}	|
		| CNN International		| {'Name': 'CNN International', 'Type': 'Daily newspaper', 'Language': ['English'], 'Owner': 'Warner Bros. Discovery', 'Website': 'https://edition.cnn.com', 'Country': 'United States'}							|
		| Global Times			| {'Name': 'Global Times', 'Type': 'Daily newspaper', 'Language': ['English', 'Chinese'], 'Owner': "People's Daily", 'Website': 'https://www.huanqiu.com', 'Country': 'China'}										|
		| Fake news				| ['Don´t exist!!!']																																																|

	#Type Flag
	Scenario Outline: Searching by id
		Given The user is searching a list of users by id
		When The user searches for the user idf "<arg>" 
		Then the "<answer>" is returned

		Examples: Types
		| arg					| answer																												|
		| 2533		| ['Oormila Bandopadhyay']	| 
		| Daily sports newspaper| ['Marca', 'AS']																										|
		| Fake news				| ['Don´t exist!!!']																									|

	#Languge Flag
	Scenario Outline: Searching by language
		Given The user is searching a list of newapapers by language
		When The user searches for the newspapers written in "<arg>" 
		Then the list "<answer>" grouped by lenguage is returned

		Examples: Languages
		| arg		| answer																						|
		| Spanish	| El Mundo,El Pais,Marca,AS,The New York Times													|
		| Portuguese| El Pais																						|
		| Catalan	| El Pais																						|
		| English	| El Pais,Marca,The Sun,The Daily Telegraph,The New York Times,CNN International,Global Times	|
		| Chinese	| The New York Times,Global Times																|
		| Fake news	| Don´t exist!!!																				|

	#Owner Flag
	Scenario Outline: Searching by owner
		Given The user is searching who is the owner
		When The user searches for the newspapers owned by "<arg>"
		Then the response "<answer>" is returned

		Examples: Owners
		| arg							| answer				|
		| Unidad Editorial S.A.			| El Mundo				|
		| PRISA							| El Pais,AS			|
		| Unidad Editorial				| Marca					|
		| News UK Independent			| The Sun				|
		| Telegraph Media Group			| The Daily Telegraph	|
		| The New York Times Company	| The New York Times	|
		| Warner Bros. Discovery		| CNN International		|
		| People's Daily				| Global Times			|
		| Fake news						| Don´t exist!!!		|

	#Website Flag
	Scenario Outline: Searching website
		Given The user wants connect to Newspaper´s Website
		When The user searches "<arg>" website
		Then the website title is "<answer>"

		Examples: Websites
		| arg							| answer																									|
		| https://www.nytimes.com		| ['The New York Times : The New York Times - Breaking News, US News, World News and Videos']				|
		| http://www.elmundo.es			| ['El Mundo : EL MUNDO - Diario online líder de información en español']									|
		| http://www.elpais.com			| ['El Pais : EL PAÍS: el periódico global']																|
		| http://www.marca.com			| ['Marca : MARCA - Diario online líder en información deportiva']											|
		| http://as.com					| ['AS : AS.com - Diario online deportivo. Fútbol, motor y mucho más']										|
		| https://www.thesun.co.uk		| ['The Sun : News, sport, celebrities and gossip \| The Sun']												|
		| https://www.telegraph.co.uk	| ['The Daily Telegraph : The Telegraph - Telegraph Online, Daily Telegraph, Sunday Telegraph - Telegraph']	|
		| https://edition.cnn.com		| ['CNN International : CNN International - Breaking News, US News, World News and Video']					|
		| https://www.huanqiu.com		| ['Global Times : 环球网_全球生活新门户_环球时报旗下网站']													|
		| Fake news						| Don´t exist!!!																							|

	#Country Flag
	Scenario Outline: Searching by country
		Given The user is searching a list of newapapers by country
		When The user searches for the newspapers published at "<arg>"
		Then the newspapers list is "<answer>"

		Examples: Countries
		| arg			| answer								|
		| China			| Global Times							|
		| Spain		    | El Mundo,El Pais,Marca,AS				|
		| United Kingdom| The Sun,The Daily Telegraph			|
		| United States	| The New York Times,CNN International	|
		| Fake news		| Don´t exist!!!						|
