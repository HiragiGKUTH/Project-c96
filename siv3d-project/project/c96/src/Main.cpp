#include <Siv3D.hpp>

#include "SystemMain.hpp"

void Main()
{
    SystemMain system;
    
    if (system.init()) {
        system.main();
    }
    system.exit();
}
