
#ifndef __INPUT_H_
#define __INPUT_H_

#include "resource.h"

class input_event
{
    friend class keyboard_event;
    friend class input_layer;
    public:
        input_event() { active=FALSE; event_type=FALSE; }
        bool is_active() { return active; }
        virtual void update() = 0;
    private:
        bool active;
        int event_type;
};

class keyboard_event: public input_event
{
    public:
        keyboard_event( int c, bool ot );
        void update();
    private:
        int key;
        bool one_time;
        bool wait_for_release;
};

class input_layer: public resource_list
{
    public:
        bool get_input( std::string name );
        void update();
};

#endif /* INPUT_H */
