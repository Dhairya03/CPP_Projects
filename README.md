To compile the code file 

1. create a folder "files" inside "Parser"
2. add "books.xml" , "quiz.json", "student_marks.csv" in "files" folder
3. run this command:


g++ -I/home/dhairyagupta/training/c-_dhairyagupta/Parser/inc /home/dhairyagupta/training/c-_dhairyagupta/Parser/lib/pugixml-master/src/pugixml.cpp *.cpp -ljsoncpp

