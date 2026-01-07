# Delete-Rename.cpp

A C++ program that allows to delete or rename a file from the command line


<img width="1898" height="1046" alt="image" src="https://github.com/user-attachments/assets/03478910-3045-4caa-b429-6c63601c574d" /><img width="1898" height="1046" alt="image" src="https://github.com/user-attachments/assets/0c1a7a81-ef35-4ab3-85c7-d3ec27765da8" />WARNING<img width="1898" height="1046" alt="image" src="https://github.com/user-attachments/assets/bb12a973-54cb-4181-94cc-4817a0d4c36e" />
<img width="1898" height="1046" alt="image" src="https://github.com/user-attachments/assets/db45dde8-8ce9-43f9-910a-d7aca18d583a" />
This program does destructives operations on system files
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



