#include "poNodeContainer.h"
#include "poShape.h"
#include "poImage.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class activePageButton;
typedef  std::shared_ptr<activePageButton> activePageButtonRef;

class activePageButton
:public po::scene::NodeContainer
{
public:
    static activePageButtonRef  create();
    
private:
    activePageButton();
    void setup();
    void mousedown( po::scene::MouseEvent &event );
    
    gl::TextureRef btnFastFashionTex;
    gl::TextureRef btnBiotextileTex;
    gl::TextureRef btnTextileTex;
    gl::TextureRef btnDyeTex;
    
    gl::TextureRef btnFastFashionActiveTex;
    gl::TextureRef btnBiotextileActiveTex;
    gl::TextureRef btnTextileActiveTex;
    gl::TextureRef btnDyeActiveTex;
    
    po::scene::ImageRef btnFastFashion;
    po::scene::ImageRef btnBiotextile;
    po::scene::ImageRef btnTextile;
    po::scene::ImageRef btnDye;
    
    po::scene::ImageRef btnFastFashionActive;
    po::scene::ImageRef btnBiotextileActive;
    po::scene::ImageRef btnTextileActive;
    po::scene::ImageRef btnDyeActive;
    
    bool btnFastFashionIsActive;
    bool btnBiotextileIsActive;
    bool btnTextileIsActive;
    bool btnDyeIsActive;
    
    po::scene::ShapeRef rect;
    

    
};
