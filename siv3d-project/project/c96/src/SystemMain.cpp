#include <Siv3D.hpp>
#include <HamFramework.hpp>

#include "SystemMain.hpp"
#include "Define.hpp"
#include "Looper.hpp"

void SetUpFullScreen() {
    Window::SetBaseSize(Define::WindowSize);
    const auto[displayIndex, displayMode]
        = OptimalScreen::Get(OptimalScreen::Preference::AspectMin, Define::WindowSize);
    Graphics::SetFullScreen(true, displayMode.size, displayIndex, displayMode.refreshRateHz);
    Graphics::SetBackground(ColorF(0.2, 0.2, 0.2));
}

bool SystemMain::init() {
    Window::SetTitle(U"Project-c96");
    SetUpFullScreen();
    return true;
}


bool SystemMain::main() {
    Looper looper;
    
    while(System::Update()) {
        if (!looper.loop()) {
            break;
        }
    }
    return true;
}

bool SystemMain::exit() {
    return true;
}
