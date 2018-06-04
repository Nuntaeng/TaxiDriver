#include "UI.h"



EventListenerTouchAllAtOnce* UI::getEventListener() {
    auto ret = EventListenerTouchAllAtOnce::create();
    ret->onTouchesBegan = CC_CALLBACK_2(UI::touchBegin, this);
    ret->onTouchesMoved = CC_CALLBACK_2(UI::touchMoved, this);
    ret->onTouchesEnded = CC_CALLBACK_2(UI::touchEnded, this);
    return ret;
}
