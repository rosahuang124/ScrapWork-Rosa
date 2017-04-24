#include "Button.h"

using namespace po::scene;

ButtonRef Button::create(gl::TextureRef btnImg, gl::TextureRef btnActiveImg){
    ButtonRef ref = std::shared_ptr<Button>(new Button);
    ref -> setup(btnImg, btnActiveImg);
    return ref;
}

void Button::setup(gl::TextureRef btnImg, gl::TextureRef btnActiveImg){
    
    mButtonTexture = btnImg;
    mButton = po::scene::Image::create(mButtonTexture);
    
    mButtonActiveTexture = btnActiveImg;
    mButtonActive = po::scene::Image::create(mButtonActiveTexture);
    
    mButton->setAlpha(1.f);
    mButtonActive->setAlpha(0.f);
    addChild(mButton);
    addChild(mButtonActive);

    
    getSignal(po::scene::MouseEvent::DOWN_INSIDE).connect(std::bind(&Button::mousedown, this, std::placeholders::_1));
}

void Button::mousedown(po::scene::MouseEvent &event)
{
    switch (event.getType()) {
        case po::scene::MouseEvent::DOWN_INSIDE:
            btnIsActivated = !btnIsActivated;
            if (btnIsActivated){
                
                mButtonActive->setAlpha(1.f);
                mButton ->setAlpha(0.f);
                btnStateChangeSignal.emit(mID);
                

            }else{
                mButtonActive->setAlpha(0.f);
                mButton ->setAlpha(1.f);
                btnStateChangeSignal.emit(mID);
                
            }
            break;
        default:
            break;
    }
}


void Button::setToNormal()
{
    mButtonActive->setAlpha(0.f);
    mButton->setAlpha(1.f);
    btnIsActivated = false;
}
