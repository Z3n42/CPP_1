TEST:       QA 
CREATOR:    ALAIN MIRANDA LOPEZ 
DATE:       5/07/2022 
CAMPUS:     |42 Urduliz, since March 2022.

******** First exercise, python script (11 to 12:30 am)********

1. Get by 'requests' library a JSON from 'https://gq67r.mocklab.io/escuela42/newspapers'
2. Treat user flags:

    *How i worked this part:

    I focused on having a valid program, just using one flag at a time, and just looking for one language even if the subject suggested a list. I priorized having a proper program to test as fast as possible, for that, the 'website' flag wasn't programmed.

    Even if i can't test the multiple languages, i would have done some testing making sure the list of languages works.
        Case 1- If all the languages in the list are at the json.
        Case 2- If none of the languages appear at the request json.
        Case 3- Mixed languages, both valid and invalid. I would only treat the valid ones, ignoring the invalid.
        Case 4- Empty list, nothing returned.

    * Casefold incident. 
        I used .casefold() in my program to put all the parameters in lowers, in order to both -n and -N to be valid. For some reason, i am having  trouble in the code, but the testing understand both -n and -N are valid, instead of being uppercase invalid.

********* Behave exercise (12:30 to 14:00) ************

3. Behave:

    My approach for this solution has been resolving the name flag, since once its correctly tested i believe the rest are similar, for the exception of language and website, which unfortunately i didn't code due to time.

    All the valid tests are checked with the name 'El Mundo' and its different variations. Again, these tests could also be done with other name values but it is making the example list longer, and kind of redundant.

    I fear the fact that i didn't check correcty the given value by my code, i explain myself.

        My code returns an array, empty or not, which has to be tested against the json of 'https://gq67r.mocklab.io/escuela42/newspapers' . My first though was to use selenium but since it is just a json, i can't get an element by its name directly.
        i also thought about making a get request, looking  for the given name, but i finally tested rapidly by hardcoding the correct answer, and comparing it against mine.
        I am sorry i was not able to fully complete this part, but I hope i can show you my idea and point of view for the whole project, if i was able to work longer inside a team.

        Finally, i would like to add the suggestion of dividing the feature in two scenario outlines. I did it all in one, with the doubt of which choice would be more reliable.
         1- Both valid and fail cases in the same scenario.
         2- Make two scenarios, one for valid and other for invalid. Since it can get a long list of Examples.

4. Thank you for the given opportunity and I hope i fit in your future plans, if not, see you at the next one.

****** Log exercise *********

The 'logs' are now shown by prints, getting the resuting array or an Exception if there was a problem with the request petition.