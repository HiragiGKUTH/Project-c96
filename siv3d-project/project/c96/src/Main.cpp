#include <Siv3D.hpp>

#include "SystemMain.h"

void Main()
{
    SystemMain system;
    
    if (system.init()) {
        system.main()
    }
    system.exit();
}
