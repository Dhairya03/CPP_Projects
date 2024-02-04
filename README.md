 For Static Linking

1. Make object file of all the header files that needs to be added to library
        g++ -c *.cpp 

2. Make static library of the object files
        ar rcs lib_Static.a

3. Make object file of main applcition
        g++ -I/home/dhairyagupta/training/c-_dhairyagupta/calculatorLibrary/ImplicitLinking/inc -c applicationImplicit.cpp -o application.o

4. Link Library with Apllication
        g++ -I/home/dhairyagupta/training/c-_dhairyagupta/calculatorLibrary/ImplicitLinking/inc applicationImplicit.cpp -L/home/dhairyagupta/training/c-_dhairyagupta/ lib_static.a
 
  
 For Implicit Dynamic Linking
 To run applicationImplicit.cpp
 
1. Make object file of all the header files that needs to be added to library
        g++ -c *.cpp -fpic

2. Make shared library using those object files
        g++ *.o -shared -o lib_Implicit.so

3. Make object file of main applcition
        g++ -I/home/dhairyagupta/training/c-_dhairyagupta/calculatorLibrary/ImplicitLinking/inc -c applicationImplicit.cpp -o application.o

4. Link Library with Apllication
        g++ -I/home/dhairyagupta/training/c-_dhairyagupta/calculatorLibrary/ImplicitLinking/inc applicationImplicit.cpp -L/home/dhairyagupta/training/c-_dhairyagupta/ -l_Implicit -o application

5. If Library file not found , check
        ldd application

6. if dependency is not found, run this command
        export LD_LIBRARY_PATH=:/home/dhairyagupta/training/c-_dhairyagupta/

7. Run the executable
        ./application

For Explicit Dynamic Linking

1. Make object file of all the header files that needs to be added to library
        g++ -c *.cpp -fpic

2. Make shared library using those object files
        g++ *.o -shared -o lib_Explicit.so

3. Link the shared library
        g++ -I/home/dhairyagupta/training/c-_dhairyagupta/calculatorLibrary/ExplicitLinking/inc/ application.cpp /home/dhairyagupta/training/c-_dhairyagupta/lib_Explicit.so -ldl -o application

4. Run the executable
        ./application

