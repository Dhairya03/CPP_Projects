#include "parser.h"

void Parser::parse(){
    openFile();
    parseFile();
    printFileData();
    closeFile();
}