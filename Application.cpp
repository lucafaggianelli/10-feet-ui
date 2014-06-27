#include "Application.h"
#include <stdio.h>
#include <iostream>
#include <cerrno>
#include <fstream>
#include <cstring>
#include <cctype>

#define WS "[ \t]*"

using namespace std;

Application::Application()
{

}

Application* Application::fromDesktopFile(char *filename)
{
    Application* app = new Application;
    ifstream desktopFile(filename, ios::in);

    if (desktopFile.is_open()) {
        string line, buf, buf2;
        char c;
        bool group,key,eq,value, desktopEntry = false;

        while(std::getline(desktopFile, line)) {
            // Clear everything
            group = key = value = eq = false;
            buf.clear();
            buf2.clear();

            for(size_t i=0; i < line.size(); i++) {
                c = line[i];
                if (c == '#') break; // comment kills everything

                if (group) {
                    if (c == ']' && i == line.size() - 1) {
                        continue;
                    } else if (iscntrl(c) || c == '[' || c == ']') {
                        cerr << "Can't use CTRL, [ or ] in groups" << endl;
                        break;
                    }
                } else if (key) {
                    if (c == '=') {
                        // key-value pair
                        eq = true;
                        key = group = value = false;
                        buf2 = buf;
                        buf.clear();
                        continue;
                    } else if (c == '[') {
                        //cerr << "Keys localization not supported" << endl;
                        break;
                    } else if (!isalnum(c) && c != '-') {
                        cerr << "Only a-Z0-9 in keys"  << endl;
                        break;
                    }
                } else if (eq) {
                    if (iscntrl(c)) {
                        cerr << "Can't use CTRL chars in entries"  << endl;
                        break;
                    } else if (isblank(c)) {
                        continue;
                    } else {
                        value = true;
                        key = group = eq = false;
                    }
                } else if (value) {
                    if (iscntrl(c)) {
                        cerr << "Can't use CTRL chars in values"  << endl;
                        break;
                    }
                } else {
                    // line begins
                    if (isalnum(c) || c == '-') {
                        key = true;
                        group = value = eq = false;
                    } else if (c == '[') {
                        group = true;
                        key = value = eq = false;
                        continue;
                    }
                }
                buf += c;
            }
            if (group) {
                desktopEntry = (buf == "Desktop Entry");
                cout << "Group: " << buf << endl;
            } else if (value) {
                cout << "Entry: " << buf2 << " -> " << buf << endl;
                if (desktopEntry) {
                    cout << "Desktop Entry found, filling app" << endl;
                    if (buf2 == "Name") {
                        cout << "Name is: " << buf << endl;
                        app->name = buf;
                    } else if (buf2 == "Comment") {
                        app->description = buf;
                    } else if (buf2 == "Exec") {
                        app->exec = buf;
                    } else if (buf2 == "Icon") {
                        app->icon = buf;
                    } else if (buf2 == "Categories") {
                        app->category = 1;
                    }
                }
            }
        }
    } else {
        perror("Open .desktop file:");
    }
    return app;
}
