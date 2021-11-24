#include "Button.h"

Button::Button(float x , float y , float width , float height , Font* font ,
           string text ,Color idleColor,Color hoverColor , Color activeColor)
{
    this->buttonState = BTN_IDLE ;
    this->shape.setPosition(Vector2f(x,y)) ;
    this->shape.setSize(Vector2f(width , height));
    this->font = font ;
    this->text.setFont(*this->font) ;
    this->text.setString(text) ;
    this->text.setFillColor(Color :: White);
    this->text.setCharacterSize(12);
    this->text.setPosition(
        this->shape.getPosition().x/2.f - this->text.getGlobalBounds().width/2,
        this->shape.getPosition().y/2.f - this->text.getGlobalBounds().height/2
    );

    this->idleColor = idleColor ;
    this->hoverColor = hoverColor ;
    this->activeColor = activeColor ;
    this->shape.setFillColor(this->idleColor) ;
}
Button::~Button()
{

}
void Button::update(const Vector2f mousePos)
{
    //IDLE
    this->buttonState = BTN_IDLE;
    if(this->shape.getGlobalBounds().contains(mousePos))
    {
        //HOVER
        this->buttonState = BTN_HOVER;
        if(Mouse::isButtonPressed(Mouse::Left))
        {
            //PRESSED
            this->buttonState = BTN_ACTIVE ;
        }
    }
    switch(this->buttonState)
    {
    case BTN_IDLE:
        break;
    case BTN_HOVER:
        break;
    case BTN_ACTIVE:
        break;
    default :
        break;
    }
}
void Button::render(RenderTarget* target)
{
    target->draw(this->shape) ;
}

