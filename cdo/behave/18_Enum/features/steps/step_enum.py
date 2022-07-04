# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    step_enum.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 16:54:04 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/03 16:56:23 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# file:datatype.features/steps/step_enum.py
# ------------------------------------------------------------------------
# USER-DEFINED TYPES:
# ------------------------------------------------------------------------
from behave import register_type
from parse_type import TypeBuilder
from domain import answer_oracle

# -- ENUM: Returns True (for "yes" and "jubilee"), False (for "no")
parse_yesno = TypeBuilder.make_enum({"yes": True, "no": False, "jubilee": True })
register_type(YesNo=parse_yesno)

# file:datatype.features/steps/step_enum.py
# ----------------------------------------------------------------------------
# STEPS:
# ----------------------------------------------------------------------------
from behave import when, then
from hamcrest import assert_that, equal_to

@when(u'Romeo asks Julia: "{question}"')
def step_when_romeo_asks_julia(context, question):
    context.question = question

@then(u'the answer is "{answer:YesNo}"')
def step_then_the_answer_is(context, answer):
    assert_that(answer, equal_to(answer_oracle.get(context.question, None)))
