#! /bin/bash


# built in var
echo '$0' : $0
echo

echo '$1': "|$1|"
echo '$2': "|$2|"
echo '$3': "|$3|"
echo '$4': "|$4|"
echo '$5': "|$5|"
echo '$6': "|$6|"
echo '$7': "|$7|"
echo '$8': "|$8|"
echo '$9': "|$9|"
echo '$10': "|${10}|"
echo

echo '$@': "$@"

echo '$#': "$#"

ls not_exist
echo '$?' : "$?"

echo '$$' : "$$"
read
