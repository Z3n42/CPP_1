# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    steps.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 14:22:47 by ingonzal          #+#    #+#              #
#    Updated: 2022/09/28 13:48:02 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from behave import *
from ex02 import *
from ex03 import *
from ex04 import *
from ex05 import *
from ex06 import *
from hamcrest import *

#Background
@given ('The user tries to connect to the site')
def step_conect(context):
    """
    BACKGROUND
    """
    assert_that(str(connect()), equal_to("<Response [200]>"))
