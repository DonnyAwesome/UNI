#!/bin/bash

DSTRING= ``
#grep
#r -> recursive
#n -> get the line Number if found
#I -> no Binary file
#o -> only matching
 
# Gibt den Dateinamen aus
#DSTRING=`grep -rI Date: * | cut -d ":" -f 1`
#email.eml storemail.sh storemail.sh storemail.sh storemail.sh~
 
# Gibt den Müll aus
#DSTRING=`grep -rI Date: * | cut -d ":" -f 2`
#Date DSTRING=`grep -rI Date DSTRING=`grep -rI Date #DSTRING=`grep -rI Date DSTRING=`grep -rI Date #DSTRING=`grep -rI Date #DSTRING=`grep -rI Date
 
# Gibt den Datum aus
#DSTRING=`grep -rI Date: eml/ | cut -d ":" -f 3`
DSTRING=`grep -rI Date: Beispielmails/ | cut -d ":" -f 3`
 
# Kontrolle ob DSTRING die Liste der Datum enstpicht 
#echo ${DSTRING}
 
for a in "${DSTRING}"; do
    echo "$a"
done

read -n1 -r -p "Press any key to continue..." key
