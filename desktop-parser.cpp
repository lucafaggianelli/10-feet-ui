#include "Application.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main (int argc, char* argv[]) {
    char DESKTOP_NAUTILUS[] = "/usr/share/applications/nautilus.desktop";
    char* fname;

    if (argc > 1) {
        fname = argv[1];
    }else {
        fname = (char*) malloc(sizeof(DESKTOP_NAUTILUS));
        strcpy(fname, DESKTOP_NAUTILUS); 
    }

    Application* app = Application::fromDesktopFile(fname);
    cout << "### " << app->name << " ###" << endl;
    cout << app->description <<endl;
    cout << app->exec << endl;
    cout << app->category << endl;
    cout << app->icon << endl;
}
