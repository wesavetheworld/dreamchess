
#ifndef __CAMERA_H
#define __CAMERA_H

#include <string>
#include "entity.h"

class camera: public entity
{
    public:
        camera(std::string name2);
        void render();
        virtual void update();
        entity *target;
};

#endif