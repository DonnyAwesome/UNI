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

_min=`grep -rI Date: Beispielmails/ | cut -d ":" -f 4`
_sec=`grep -rI Date: Beispielmails/ | cut -d ":" -f 5`
 
echo "$_min"
echo "$_sec"

# Kontrolle ob DSTRING die Liste der Datum enstpicht 
#echo ${DSTRING}
 
for a in "${DSTRING}"; do
    echo "$a"
done

read -n1 -r -p "Press any key to continue... " key
