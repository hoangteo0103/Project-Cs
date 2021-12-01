#include "WinState.h"
void WinState::initFonts()
{
    if(!this->font.loadFromFile("font/Contb.ttf"))
    {

    }
}
void WinState::initState(RenderWindow& app)
{
    this->initFonts() ;
    this->ok = false ;
    //Init background
    this->background.setSize(
        Vector2f(
            static_cast<float> (app.getSize().x),
            static_cast<float> (app.getSize().y)));
    this->background.setFillColor(Color(20,20,20,100));
    // Init container
    this->container.setSize(
        Vector2f(
            static_cast<float> (app.getSize().x)  - 50.f,
            static_cast<float> (app.getSize().y)/4.f));
    this->container.setFillColor(Color::Blue);
    this->container.setPosition(
        Vector2f(15.f , static_cast<float>(app.getSize().y) / 2.f - this->container.getSize().y/2.f));
    // Init buttons
    this->buttons["OK"] = new Button(500, 400, 200, 50,
            &this->font, "OK", Color(70,70,70,200)
            ,Color(150,150,150,255), Color(20,20,20,200) ) ;
    // Init Text
    this->menutext.setFont(font);
    this->menutext.setFillColor(Color(255,255,255,200));
    this->menutext.setCharacterSize(30);
    this->menutext.setString("WIN");
    this->menutext.setPosition(this->container.getPosition().x + this->container.getSize().x/2.f -  this->menutext.getGlobalBounds().width/2.f ,
        this->container.getPosition().y + 20.f);
}
WinState::WinState()
{
}

WinState::~WinState()
{

    auto it = this->buttons.begin();
    for(it = this->buttons.begin(); it!=this->buttons.end() ; ++it)
    {
        delete it->second;
    }
    this->ok = false ;
}
const bool& WinState::getOk() const
{
    return this->ok;
}
void WinState::updateMousePositions(Vector2f mousePosView)
{
    this->mousePosView = mousePosView ;
}
void WinState::updateButtons()
{
    for(auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }
}
void WinState::update()
{
    this->updateButtons() ;
    if(this->buttons["OK"]->isPressed())
    {
        this->ok = true ;
    }
}

void WinState::render(RenderTarget& target)
{
    target.draw(background);
    target.draw(container);
    target.draw(menutext);
    for(auto &i : this->buttons)
    {
        i.second->render(&target);
    }
}
