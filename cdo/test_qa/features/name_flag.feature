Feature: Check if the given parameters are valid or not
    By valid, we mean the program will treat them.
    A not valid flag returns an empty array.

Scenario Outline: Treat the 'name' flag
    Given the user writes the <flag> and <value>
    Then the user will get a <result> array

    Examples:
    | flag      | value    | result   |
    | -n        | El Mundo | correct  |
    | -n        | el mundo | correct  |
    | -n        | Le monde | empty    |
    | -n        | empty    | empty    |
    | -N        | El Mundo | correct  |
    | -N        | el mundo | correct  |
    | -N        | Le monde | empty    |
    | -N        | empty    | empty    |
    | --name    | El Mundo | correct  |
    | --name    | el mundo | correct  |
    | --name    | Le monde | empty    |
    | --name    | empty    | empty    |
    | --Name    | El Mundo | correct  |
    | --Name    | el mundo | correct  |
    | --Name    | Le monde | empty    |
    | --Name    | empty    | empty    |
    | -a        | El Mundo | empty    |
    | -a        | el mundo | empty    |
    | -a        | Le monde | empty    |
    | -a        | empty    | empty    |
    | --any     | El Mundo | empty    |
    | --any     | el mundo | empty    |
    | --any     | Le monde | empty    |
    | --any     | empty    | empty    |
    | empty     | empty    | empty    |