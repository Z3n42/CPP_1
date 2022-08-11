import sys
from request_data import *

def treat_flags(flag, value):
    if flag == "-n" or flag == "--name":
        return get_by_name(value)
    elif flag == "-t" or flag == "--type":
        return get_by_type(value)
    elif flag == "-l" or flag == "--language":
        return get_by_language(value)
    elif flag == "-o" or flag == "--owner":
        return get_by_owner(value)
    #elif flag == "-w" or flag == "--website":
        #return get_by_website(value)
    elif flag == "-c" or flag == "--country":
        return get_by_country(value)


if __name__ == "__main__":
    if (len(sys.argv) == 3):
        treat_flags(sys.argv[1], sys.argv[2])