#!/bin/bash
 
DSTRING= ``
#grep
#r -> recursive
#n -> get the line Number if found
#I -> no Binary file
#o -> only matching
 
# Gibt den Dateinamen aus
DSTRING=`grep -rI Date: ${PWD}`

# oder geht auch mit
#DSTRING=`grep -rI Date: *`

read -n1 -r -p "Press any key to continue..." key
