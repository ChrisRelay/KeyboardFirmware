#ifndef PLUGIN_HELLOWORLD_H
#define PLUGIN_HELLOWORLD_H

void plugin_handleFN_HELLOWORLD() {

    if (checkFNKeyOnce('h')) {
        Keyboard.print("HELLO WORLD!");
    }
    
}

#endif