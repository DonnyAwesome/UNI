#!/bin/bash

_yea=''
_mnt=''
_day=''
_hrs=''
_min=''
_sec=''

DSTRING= ``

# Gibt den Datum aus
#DSTRING=`grep -rI Date: eml/ | cut -d ":" -f 3`
DSTRING=`grep -rI Date: Beispielmails/ | cut -d ":" -f 3`

# Mon, 19 Mar 2018 15
_yea=$(echo $DSTRING | cut -d " " -f 4)
_mnt=$(echo $DSTRING | cut -d " " -f 3)
_day=$(echo $DSTRING | cut -d " " -f 2)
_hrs=$(echo $DSTRING | cut -d " " -f 5)

_min=`grep -rI Date: Beispielmails/ | cut -d ":" -f 4`
_sec=`grep -rI Date: Beispielmails/ | cut -d ":" -f 5`

echo "----------------------------"
echo "Year: $_yea"
echo "Mnth: $_mnt"
echo "Day : $_day"
echo "Hour: $_hrs"

echo "Min : $_min"
echo "Sec : $_sec"
echo "----------------------------"

# Kontrolle ob DSTRING die Liste der Datum enstpicht 
#echo ${DSTRING}
 
for a in "${DSTRING}"; do
    echo "$a"
done

read -n1 -r -p "Press any key to continue... " key
