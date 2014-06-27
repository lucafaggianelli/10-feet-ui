#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>

class Application
{
public:
    std::string
        name,
        description,
        exec,
        icon;
    int category;
    
    Application();
    static Application* fromDesktopFile(char *filename);
};

#endif // APPLICATION_H
