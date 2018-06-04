#pragma once
#include "cocos2d.h"
USING_NS_CC;


/**
 @brief     ゲーム内で使われtるUIの親クラス
 @note      主にタッチイベント部分を担当する
 @author    Heewon Kim (nabicore@icloud.com)
 @date      2018-06-06
 */

class UI : public Sprite {
protected:
    virtual bool touchBegin(const std::vector<Touch*>&, Event*) = 0;
    virtual void touchMoved(const std::vector<Touch*>&, Event*) = 0;
    virtual void touchEnded(const std::vector<Touch*>&, Event*) = 0;
    
public:
    explicit UI() {}
    virtual ~UI() {}
    
    /**
     @return    このUIオブジェクトのタッチ登録をためなListener
     */
    EventListenerTouchAllAtOnce* getEventListener();
};
