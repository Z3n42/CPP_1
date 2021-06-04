echo $FT_NRB1 + $FT_NRB2 | sed "s/\'/0/g" | tr '\\\"\?\!' 1234 | tr 'mrdoc' 01234 | xargs echo 'ibase=5; obase=D;' | bc | tr 0123456789ABC 'gtaio luSnemf'
