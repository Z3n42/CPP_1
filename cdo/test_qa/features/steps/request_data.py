import requests

def get_json():
    try:
       return requests.get("https://gq67r.mocklab.io/escuela42/newspapers")
    except:
        print("Exception at get request. None received.")
        return None

def get_by_name(value):
    json = get_json().json()
    result = []
    if json is None:
        return result
    for news, content in json.items():
        if content["Name"] == value:
            result.append(content)
    print (result)
    return result

def get_by_type(value):
    json = get_json().json()
    result = []
    if json is None:
        return result
    for news, content in json.items():
        if content["Type"] == value:
            result.append(content)
    print(result)
    return result

#WIP LIST OF 4 LANGUAGES. Only works with 1 language at parameter.
def get_by_language(value): 
    json = get_json().json()
    result = []
    if json is None:
        return result
    for news, content in json.items():
        for each in content["Language"]:
            if each == value:
                result.append(content)
    print(result)
    return result

def get_by_owner(value):
    json = get_json().json()
    result = []
    if json is None:
        return result
    for news, content in json.items():
        if content["Owner"] == value:
            result.append(content)
    print(result)
    return result

def get_by_country(value):
    json = get_json().json()
    result = []
    if json is None:
        return result
    for news, content in json.items():
        if content["Country"] == value:
            result.append(content)
    print(result)
    return result
    