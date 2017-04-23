#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "poScene.h"
#include "poImage.h"
#include "poShape.h"
#include "poNodeContainer.h"
#include "Pile.h"
#include "activePageButton.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ScrapWorkApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    
    PileRef                         mPile ;
    activePageButtonRef             mActivePageBtn;
    
    po::scene::SceneRef             mScene;
    po::scene::NodeContainerRef     mContainer;
    po::scene::NodeContainerRef     waitContainer;
    po::scene::NodeContainerRef     activeContainer;
    
    po::scene::ImageRef             bgImg;
    
    
};

void ScrapWorkApp::setup()
{
    ci::app::setWindowSize(glm::vec2(1280.f, 800.f));
    
    mContainer = po::scene::NodeContainer::create();
    mScene = po::scene::Scene::create(mContainer);
   
    waitContainer = po::scene::NodeContainer::create();
    activeContainer = po::scene::NodeContainer::create();
    
    mContainer->addChild(waitContainer);
    mContainer->addChild(activeContainer);
    
    bgImg = po::scene::Image::create(ci::gl::Texture::create(ci::loadImage(loadAsset("bg.png"))));
    
//    waitContainer->addChild(bgImg);
//    mPile = Pile::create();
//    waitContainer->addChild(mPile);
    
    
    activeContainer->addChild(bgImg);
    mActivePageBtn = activePageButton::create();
    activeContainer->addChild(mActivePageBtn);
    //activeContainer->setAlpha(0.f);
    
}

void ScrapWorkApp::mouseDown( MouseEvent event )
{

}

void ScrapWorkApp::update()
{
    mScene->update() ;
    //mPile->update();
    
}

void ScrapWorkApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    mScene->draw();
    
    
}

CINDER_APP( ScrapWorkApp, RendererGl )
