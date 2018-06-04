#include "SteerController.h"

SteerController* SteerController::create(const std::string& sprName, const Vec2& pos) {
    auto ret = new SteerController();
    if (ret && ret->init(sprName, pos)) {
        ret->autorelease();
        return ret;
    }
    else {
        delete ret;
        ret = nullptr;
        return nullptr;
    }
}

bool SteerController::init(const std::string& sprName, const Vec2& pos) {
    if (Sprite::initWithFile(sprName)) {
        return false;
    }
    
    this->setPosition(pos);
    size = this->getContentSize();
    this->scheduleUpdate();
    
    return true;
}

void SteerController::update(float dt) {
    
}

bool SteerController::touchBegin(const std::vector<Touch *>& touches, cocos2d::Event*) {
    for (auto& t : touches) {
        if (isTouchOnSteer(t)) {
            isActivate = true;
            handlingTouch = t;
            Steer();
        }
    }
    return true;
}

void SteerController::touchMoved(const std::vector<Touch *>& touches, cocos2d::Event*) {
    if (isActivate) {
        Steer();
    }
}

void SteerController::touchEnded(const std::vector<Touch *>& touches, cocos2d::Event*) {
    if (isActivate) {
        curAngle = 0.f;
        handlingTouch = nullptr;
        isActivate = false;
    }
}

/**
 @return タッチした座標が画像範囲内にいるのか
 */
inline bool SteerController::isTouchOnSteer(Touch* t) const {
    return this->getBoundingBox().containsPoint(t->getLocation());
}

/**
 @brief 角度を変えたり、UI画像を回転させたりする本当の処理が書かれている
 */
void SteerController::Steer() {
    if (!handlingTouch) {
        return;
    }
    
}

inline float SteerController::getAngle() const {
    return curAngle;
}

inline void SteerController::setMaxAngle(const float& angle) {
    maxAngle = angle;
}

inline float SteerController::getMaxAngle() const {
    return maxAngle;
}
