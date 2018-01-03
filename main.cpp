#include "Server.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;
int main() {
    //get the port from the setting file
    int port;
    ifstream settingFile;
    settingFile.open("server_settings.txt");
    if(!settingFile.is_open()){
        cout<<"failed to open file";
        exit(0);
    }
    settingFile>>port;
    settingFile.close();

    Server server(port);
    try {
        server.start();

        cout<<"Enter exit to stop server"<<endl;
        string str;
        do {
            cin >> str;
        } while (str!="exit");
        server.stop();

    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}