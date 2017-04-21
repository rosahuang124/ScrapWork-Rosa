#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ScrapWorkApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    
};

void ScrapWorkApp::setup()
{
     ci::app::setWindowSize(glm::vec2(1280.f, 800.f));
}

void ScrapWorkApp::mouseDown( MouseEvent event )
{
}

void ScrapWorkApp::update()
{
}

void ScrapWorkApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    
}

CINDER_APP( ScrapWorkApp, RendererGl )
