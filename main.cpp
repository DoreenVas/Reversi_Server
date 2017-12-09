#include "Server.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;
int main() {
    //get the port from the setting file
    int port;
    ifstream settingFile;
    settingFile.open("../server_settings.txt");
    if(!settingFile.is_open()){
        cout<<"failed to open file";
        exit(0);
    }
    settingFile>>port;
    settingFile.close();

    Server server(port);
    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        server.stop();
        exit(-1);
    }
}