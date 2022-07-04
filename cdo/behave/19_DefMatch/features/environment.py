# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    environment.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 17:12:51 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/03 17:13:08 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- FILE: features/environment.py
from behave import use_step_matcher

# -- SELECT DEFAULT STEP MATCHER: Use "re" matcher as default.
# use_step_matcher("parse")
# use_step_matcher("cfparse")
use_step_matcher("re")

