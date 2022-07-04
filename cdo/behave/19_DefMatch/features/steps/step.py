# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    step.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 17:13:43 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/03 17:13:56 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- FILE: features/steps/step.py
from behave import given, when, then, use_step_matcher
from hamcrest import assert_that, equal_to

# ------------------------------------------------------------------------
# STEPS with Regular Expression Matcher ("re")
# ------------------------------------------------------------------------
# -- SELECT STEP MATCHER: Before using it in step definitions.
use_step_matcher("re")

@when(u'I meet with "(?P<person>Alice|Bob)"')
def step_when_I_meet(context, person):
    context.person = person

# ------------------------------------------------------------------------
# STEPS with Parse Matcher ("parse")
# ------------------------------------------------------------------------
use_step_matcher("parse")

@then(u'I have a lot of fun with "{person}"')
def step_then_I_have_fun_with(context, person):
    assert_that(person, equal_to(context.person))
