# Delete-Rename.cpp

A C++ program that allows to delete or rename a file from the command line


⚠️⚠️⚠️WARNING⚠️⚠️⚠️

Use exclusively with educative fines and in controlled enviroments

---

##Description

Personal learning project which the intention of practice the management of C++ files
The program asks for a file rute, verifies its existence and allows the user to delete it 
or rename it from the terminal


---

##Funcionalities


-Comprobation of the existence of the files

-Elimination of files

-Changing the name of files

-Input validation of the user

-Detection of non ASCII characters on the file rute (ñ,tildes,etc...)

---

#Decisiones de diseño

-We restrict rutes with non ASCII characters to avoid codification problems in basic systems

-We priorize clarity and control of error before optimization and concision

-We use an easy implementation with educational purposes


---

#What did we learnt?

-C/C++ files management

-Use of standart funtions ('fopen', 'remove', 'rename')

-Inputs validations from terminal

-Errors control and executions flows

-Basic interaction with the user


---

#Possible Improvements

-Refactor the repited code in functios

-Use of 'std::string' instead of 'char[]'

-Complete support to UTF-8 rutes

-Improve the user interface

-Add extra confirmations before delete files




