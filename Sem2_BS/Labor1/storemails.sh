#!/bin/bash
 
# Anzahl an Param
#echo "$#"
if [[ "$#" -eq 0 ]]; then
  echo 'No Arguments!'
  #exit 1
else
  # Alle Param in ein String
  #echo "$@"
  for a in "$@"; do
    echo "$a"
  done
fi
 
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
 
echo ${DSTRING}
 
for a in "${DSTRING}"; do
    echo "$a"
  done
