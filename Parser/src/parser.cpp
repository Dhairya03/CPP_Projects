#include "parser.h"

bool Parser::parse(Parser& fileParser){
    fileParser.openFile();
    fileParser.parseFile();
    fileParser.printFileData();
    fileParser.closeFile();
    return true;
}