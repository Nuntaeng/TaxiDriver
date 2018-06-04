#pragma once
#include "UI.h"

/**
 @brief     仮想ハンドル
 @author    Heewon Kim (nabicore@icloud.com)
 @date      2018-06-06
 */

class SteerController : public UI {
private:
    bool init(const std::string&, const Vec2&);
    virtual void update(float) override;
    bool touchBegin(const std::vector<Touch*>&, Event*) override;
    void touchMoved(const std::vector<Touch*>&, Event*) override;
    void touchEnded(const std::vector<Touch*>&, Event*) override;
    
    inline bool isTouchOnSteer(Touch*) const;
    
    void Steer();
    
public:
    explicit SteerController() {}
    virtual ~SteerController() {}
    
    /**
     @param スティアーフィールとして使われる画像のファイルパス
     @param 配置位置
     */
    static SteerController* create(const std::string&, const Vec2&);
    
    /**
     @return 現在のスティアーの回転角度
     */
    inline float getAngle() const;
    
    /**
     @param 回転できる最大角度
     @note  -param ~ paramまでの角度で曲がれる
     */
    inline void setMaxAngle(const float&);
    inline float getMaxAngle() const;
    
private:
    bool            isActivate = false;
    float           curAngle = 0.f;
    float           maxAngle = 180.f;
    Size            size;
    Vec2            prevTouchLoc = Vec2();
    Touch*          handlingTouch = nullptr;
};
