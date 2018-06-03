//
//  Joystick.hpp
//  Survive
//
//  Created by 김희원 on 2018. 4. 28..
//

#ifndef Joystick_hpp
#define Joystick_hpp

#include "cocos2d.h"
USING_NS_CC;


class JoyStick {
    
    bool Initialize(std::string, std::string);
    bool Initialize(std::string, std::string, Vec2);
    void Calculate(Vec2);
    bool touchBegin(const std::vector<Touch*>&, Event*);
    void touchMoved(const std::vector<Touch*>&, Event*);
    void touchEnded(const std::vector<Touch*>&, Event*);
    
public:
    explicit JoyStick() {}
    virtual ~JoyStick() {}
    
    /**
     @brief タッチスクリーン上で使える仮想ジョイスティックを生成します。
     @param ジョイスティックの外側の画像ファイルパス
     @param ジョイスティックの実際操作する側の画像ファイルパス
     @param 初期位置
    */
    static JoyStick* create(std::string, std::string);
    static JoyStick* create(std::string, std::string, Vec2);
    
    /**
     @brief 親を指定します。
     @param 親
    */
    void setParent(Node*);
    
    /**
     @return ジョイスティックのタッチ操作をシーンのイベントに登録するためのListener
    */
    EventListenerTouchAllAtOnce* getEventListener();
    
    void setPosition(const Vec2&);
    Vec2 getVelocity() const;
    Size getContentSize() const;
    float getLength() const;
    float getLengthPercent() const;
    float getAngle() const;
    
private:
    bool isActivate = false;
    float outerRadius = 0.f;
    float innerRadius = 0.f;
    float angle = 0.f;
    float length = 0.f;
    Vec2 startPoint = Vec2::ZERO;
    
    Sprite* innerCircle;
    Sprite* outerCircle;
};


#endif /* Joystick_hpp */
