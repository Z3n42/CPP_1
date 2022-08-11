import requests
import sys
from collections import defaultdict
#import argpare

def name (arg2, r):
   dic = r.items()
   for key, value in dic:
     # if value == arg2:
            print (key, ":", value)

def typ (arg2, r):
    print (r.text)

def lang (arg2, r):
    print (r.text)

def owner (arg2, r):
    print (r.text)

def arg (arg2, r):
    print (r.text)

if len(sys.argv) == 3:
    arg = sys.argv[1]
    arg2 = sys.argv[2]
    r = requests.get('https://gq67r.mocklab.io/escuela42/newspapers')
    rjson = r.json()
    if arg == '-n' or arg == '-name':
        name(arg2, rjson)
    if arg == '-t' or arg == '-type':
        typ(arg2, rjson)
    if arg == '-l' or arg == '-language':
        lang(arg2, rjson)
    if arg == '-w' or arg == '-website':
        owner(arg2, rjson)
    if arg == '-c' or arg == '-country':
        country(arg2, rjson)
else:
    print("Error - Introduce los argumentos correctamente")
    print('Ejemplo: script.py argumento')

#parser = argparse.ArgumentParser()
