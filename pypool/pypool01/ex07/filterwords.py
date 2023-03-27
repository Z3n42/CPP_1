# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    filterwords.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 19:27:50 by ingonzal          #+#    #+#              #
#    Updated: 2023/03/26 20:17:31 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
import sys
from string import punctuation

def filterwords(s, n):
    st = ''
    for c in s:
        st += c if c not in punctuation else ''
    lst = st.split(' ')
    ret = [word for word in lst if len(word) > n]
    return (ret)



if __name__=='__main__':
    try:
        assert len(sys.argv) == 3
        isinstance(sys.argv[1], str)
        sys.argv[2].isdigit()
        s = sys.argv[1]
        n = int(sys.argv[2])
        print(filterwords(s, n))
    except:
        print("Error")
