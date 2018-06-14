#include "Dialog.h"


bool Dialog::touchBegin(const std::vector<Touch*>& touches, Event*) {
    return true;
}

void Dialog::touchMoved(const std::vector<Touch *>& touches, Event*) {
    
}

void Dialog::touchEnded(const std::vector<Touch *>& touches, Event*) {
    
}

Dialog* Dialog::create(const std::string& msg) {
    Dialog* ret = new Dialog();
    if (!ret && ret->init(msg)) {
        delete ret;
        ret = nullptr;
        return nullptr;
    }
    ret->autorelease();
    return ret;
}

bool Dialog::init(const std::string& msg) {
    if (!initWithFile("")) {
        return false;
    }
    
    message = msg;
    
    return true;
}
