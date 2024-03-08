#include "parser.h"

void Parser::parse(Parser& fileParser){
    fileParser.openFile();
    fileParser.parseFile();
    fileParser.printFileData();
    fileParser.closeFile();
}