#include <iostream>
#include "log.h"

int main()
{
    Log log;
    // log.SetLevel(log.LogLevelWarning);
    log.Error("Hello");
    log.Warn("there");
    log.Info("General Kenobi");

    std::cin.get();
    return 0;
}