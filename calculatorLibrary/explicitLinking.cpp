#include <dlfcn.h>

typedef double (*DoubleFunction)(double,double);

void *handle=dlopen("../lib_Calc1.so",RTLD_LAZY);
    if(!handle){
        std::cout<<"Error loading shared library"<<std::endl;
        return 1;
    }
    DoubleFunction add = reinterpret_cast<DoubleFunction>(dlsym(handle, "add"));
    DoubleFunction sub = reinterpret_cast<DoubleFunction>(dlsym(handle, "sub"));
    DoubleFunction multiply = reinterpret_cast<DoubleFunction>(dlsym(handle, "multiply"));
    DoubleFunction divide = reinterpret_cast<DoubleFunction>(dlsym(handle, "divide"));

    if(!add || !sub || !multiply || !divide){
        std::cout<<"Error finding the function"<<std::endl;
        dlclose(handle);
        return 1;
    }
    //double add=(dlsym(handle,"add"));
