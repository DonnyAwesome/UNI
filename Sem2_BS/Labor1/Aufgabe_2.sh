#!/bin/bash

# Wie schreiben sie in einem bash-Skript eine Schleife, die Beleibig vile Kommandozeilenparameter abarbeitet?

# "$@" gib alle Param in ein String
#echo "$@"

for a in "$@"; do
  echo "$a"
  #switch "$a"
done

read -n1 -r -p "Press any key to continue..." key
