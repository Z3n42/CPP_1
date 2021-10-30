#!/bin/bash
echo "Please wait... loading the image can take a few minutes... Take some time to find leaks on your minishell..."
# create save file
mkdir -p ${PWD}/savegame && touch ${PWD}/savegame/ctf && chmod a+rw ${PWD}/savegame/ctf

if [ -d /sgoinfre/students/dpuente- ];then # in Madrid
	docker load --input $(find /sgoinfre/students/dpuente- -name microctf.tar 2>/dev/null | head -n1)
	docker run -p 4242:4242 --mount type=bind,source="${PWD}/savegame",target=/tmp --hostname microctf -it darodrig/microctf
elif [ -d /sgoinfre/shared/ctf ];then # in Urduliz
	docker load --input $(find /sgoinfre/shared/ctf -name microctf.tar 2>/dev/null | head -n1)
	docker run -p 4242:4242 --mount type=bind,source="${PWD}/savegame",target=/tmp --hostname microctf -it darodrig/microctf
else
	docker load --input $(find / -name microctf.tar 2>/dev/null | head -n1)
	docker run -p 4242:4242 --mount type=bind,source="${PWD}/savegame",target=/tmp --hostname microctf -it darodrig/microctf
fi
