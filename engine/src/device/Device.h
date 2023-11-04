//
// Created by chips on 11/4/23.
//

#ifndef IMGUI_DEVICE_H
#define IMGUI_DEVICE_H

namespace game {

    class Device {
        bool createBackend(bool forceOpenGL);


    private:
        bool vulkanSupported = false; // assume false
    };

} // game

#endif //IMGUI_DEVICE_H
