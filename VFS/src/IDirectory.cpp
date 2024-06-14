#include <IDirectory.h>

IDirectory::IDirectory() {}

IDirectory::IDirectory(const std::string &name) : FileSystemComponent(name) {}

IDirectory::~IDirectory() {}