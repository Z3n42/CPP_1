# **QA technical test** 
_28/09/22_
_Iñigo Gonzalez Portela_
_ingonzal@student.42urduliz.com_

## Subject

#### 1 . Create a python script that finds the information requested by parameter in a JSON

> 1 . Parse arguments.
>
> 2 . Connect to API using **request** module.
>
> 3 . Extract and parse JSON to locate specific information that is defined by the arguments.
>
> 4 . Use **selenium** to connect to the websites and get the title. **_(Only works at the attached Docker enviroment because the [Xvfb](https://es.wikipedia.org/wiki/Xvfb) dependency)_**
>
> 5 . Print the info.

#### 2 . Build as many tests as possible with BEHAVE to check how it works.

> 1 . In this part I have put a common background to all the scenarios and then through "Scenario Outlines" I have tried to verify all the expected results.
>
> 2 . However, for this test, having also made the script, I think that I was building the tests looking for green, and I get the feeling that this is not the idea.

#### 3 . With the logging module create a log file system.

> 1 . I have set the level to info and I check all the accesses to the main class by registering the time, the file and as a message I contrast the flag entered with the return it gives.

## Tech

Specified technologies are used.:

- [Python] - Main scripting lenguage.
- [Behave] - behaviour-driven development, Python style.
- [Request] - Allows you to send HTTP/1.1 requests extremely easily.
- [Selenium] - Primarily it is for automating web applications for testing purposes, but is certainly not limited to just that.
- [Docker] - Use containers to Build, Share and Run your applications.
- [Bash] - GNU scripting lenguage.


## Installation

Just run the added script.
This script downloads all the necessary dependencies to build a container with all the necessary dependencies.

```sh
./run.sh start
```
When finished.
This script cleans all the downloaded enviroment.
 
 ```sh
./run.sh clean
```

## Docker
Inside the container, you can execute script directly or invoke Behave.

```sh
./script.py -[flag] [Argument]
```
```sh
behave
```
## Script arguments
**-n, --name** => Get the information from the newspaper with the specified name.

**-t, --type** => Get the list of newspapers of the specified type.

**-l, --language** => Get the list of newspapers of the specified languages.

**-o, --owner** => Get the list of newspapers of the specified owner.

**-w, --website** => Get the list of newspapers from the specified owner Retrieve the name of the newspaper (Name field) from the specified url and return the name of the newspaper and the title of the web page (specified url) (we get the value of the title using selenium).

**-c, --country** => Get the list of newspapers of the specified country.

## Special thanks and recognition

> Original Dockerfile by **[matt-bertoncello/Dockerfile](https://gist.github.com/matt-bertoncello)** adaptation by ingonzal

## License
[MIT](https://opensource.org/licenses/MIT)
**Free Software, Hell Yeah!**

   [Python]: <https://www.python.org/>
   [Behave]: <https://behave.readthedocs.io/en/stable/index.html>
   [Selenium]: <https://www.selenium.dev/>
   [Request]: <https://requests.readthedocs.io/en/latest/>
   [Docker]: <https://www.docker.com>
   [Bash]: <https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html>
