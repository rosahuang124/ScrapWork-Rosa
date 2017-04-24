#pragma once

#include "poNodeContainer.h"
#include "poImage.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Button;
typedef  std::shared_ptr<Button> ButtonRef;
typedef  ci::signals::Signal<void(int number)> btnChangeState;

class Button
:public po::scene::NodeContainer
{
public:
    
    static ButtonRef  create(gl::TextureRef btnImg, gl::TextureRef btnActiveImg);
    btnChangeState& getbtnChangeStateSignal(){return btnStateChangeSignal;}
    
    void setup(gl::TextureRef btnImg, gl::TextureRef btnActiveImg);
    void mousedown(po::scene::MouseEvent &event);
    void setToNormal();
    void setID(int number){mID = number;}
    btnChangeState btnStateChangeSignal;
    bool btnIsActivated;
    
    
private:
    
    po::scene::ImageRef mButton;
    po::scene::ImageRef mButtonActive;
    
    gl::TextureRef mButtonTexture;
    gl::TextureRef mButtonActiveTexture;
    
    int             mID;

    

};

