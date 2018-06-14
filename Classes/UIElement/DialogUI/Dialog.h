#pragma once
#include "UI.h"

/**
 @brief     ポップアップメッセージ出力用
 @author    Heewon Kim (nabicore@icloud.com)
 @date      2018-06-12
 */

class Dialog : public UI {
  
    virtual bool init(const std::string&);
    virtual bool touchBegin(const std::vector<Touch*>&, Event*) override;
    virtual void touchMoved(const std::vector<Touch*>&, Event*) override;
    virtual void touchEnded(const std::vector<Touch*>&, Event*) override;
    
public:
    explicit Dialog() {}
    virtual ~Dialog() {}
    
    /**
     @brief     インスタンスを生成します
     @param     メッセージ内容
     */
    static Dialog* create(const std::string&);
    
private:
    std::string                     message;
};
