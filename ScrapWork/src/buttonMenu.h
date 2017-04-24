#pragma once

#include "poNodeContainer.h"
#include "Button.h"

class buttonMenu;
typedef std::shared_ptr<buttonMenu> buttonMenuRef;

class buttonMenu
:public po::scene::NodeContainer
{
public:
    static buttonMenuRef create();
    
    void setup();
    void updateMenuState(int number);

    
private:
    ButtonRef btn1;
    ButtonRef btn2;
    ButtonRef btn3;
    ButtonRef btn4;
    
    gl::TextureRef btn1Texture;
    gl::TextureRef btn2Texture;
    gl::TextureRef btn3Texture;
    gl::TextureRef btn4Texture;
    
    gl::TextureRef btn1ActiveTexture;
    gl::TextureRef btn2ActiveTexture;
    gl::TextureRef btn3ActiveTexture;
    gl::TextureRef btn4ActiveTexture;
    
};
