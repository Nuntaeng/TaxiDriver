//
//  Joystick.cpp
//  Survive
//
//  Created by 김희원 on 2018. 4. 28..
//

#include "Joystick.h"



bool JoyStick::Initialize(std::string innerSprName, std::string outerSprName) {
    innerCircle = Sprite::create(innerSprName);
    outerCircle = Sprite::create(outerSprName);
    outerRadius = outerCircle->getContentSize().width * 0.5f;
    outerRadius = innerCircle->getContentSize().width * 0.5f;
    return true;
}

bool JoyStick::Initialize(std::string innerSprName,
                          std::string outerSprName,
                          Vec2 startPos) {
    if (this->Initialize(innerSprName, outerSprName)) {
        this->setPosition(startPos);
        return true;
    }
    return false;
}

void JoyStick::Calculate(Vec2 touchPos) {
    float dx = touchPos.x - startPoint.x;
    float dy = touchPos.y - startPoint.y;
    length = sqrt(dx * dx + dy * dy);
    angle = atan2(dy, dx);
    if (length > outerRadius) {
        dx = cos(angle) * outerRadius;
        dy = sin(angle) * outerRadius;
    }
    innerCircle->setPosition(Vec2(dx + startPoint.x, dy + startPoint.y));
}

bool JoyStick::touchBegin(const std::vector<Touch *>& touches, cocos2d::Event *) {
    for (auto& touch : touches) {
        if (outerCircle->getBoundingBox().containsPoint(touch->getLocation())) {
            Calculate(touch->getLocation());
            isActivate = true;
        }
    }
    return true;
}

void JoyStick::touchMoved(const std::vector<Touch *>& touches, cocos2d::Event *) {
    for (auto& touch : touches) {
        if (isActivate)
            Calculate(touch->getLocation());
    }
}

void JoyStick::touchEnded(const std::vector<Touch *>& touches, cocos2d::Event *) {
    float prevAngle = angle;
    Calculate(startPoint);
    angle = prevAngle;
    isActivate = false;
}

JoyStick* JoyStick::create(std::string innerSprName, std::string outerSprName) {
    auto ret = new JoyStick();
    if (ret != nullptr && ret->Initialize(innerSprName, outerSprName)) {
        return ret;
    }
    return nullptr;
}

JoyStick* JoyStick::create(std::string innerSprName,
                      std::string outerSprName,
                      Vec2 startPos) {
    auto ret = JoyStick::create(innerSprName, outerSprName);
    if (ret != nullptr) {
        ret->setPosition(startPos);
        return ret;
    }
    return nullptr;
}

void JoyStick::setParent(Node* parent) {
    parent->addChild(outerCircle, 50);
    parent->addChild(innerCircle, 51);
}

EventListenerTouchAllAtOnce* JoyStick::getEventListener() {
    auto ret = EventListenerTouchAllAtOnce::create();
    ret->onTouchesBegan = CC_CALLBACK_2(JoyStick::touchBegin, this);
    ret->onTouchesMoved = CC_CALLBACK_2(JoyStick::touchMoved, this);
    ret->onTouchesEnded = CC_CALLBACK_2(JoyStick::touchEnded, this);
    return ret;
}

void JoyStick::setPosition(const Vec2& pos) {
    outerCircle->setPosition(pos);
    innerCircle->setPosition(pos);
    startPoint = pos;
}

Vec2 JoyStick::getVelocity() const {
    if (!isActivate)
        return Vec2::ZERO;
    return Vec2(cos(angle), sin(angle));
}

Size JoyStick::getContentSize() const {
    return outerCircle->getContentSize();
}

float JoyStick::getLength() const {
    return length;
}

float JoyStick::getLengthPercent() const {
    return MIN(length / outerRadius, 1.f);
}

float JoyStick::getAngle() const {
    return angle;
}
