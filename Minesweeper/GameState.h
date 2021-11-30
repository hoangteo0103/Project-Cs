#ifndef GameState_H
#define GameState_H
#include "State.h"
#include "Button.h"
#include "PauseMenu.h"
#include "WinState.h"
namespace st {
        struct Timer {
                sf::Clock mC;
                float runTime;
                bool bPaused;

                Timer() {
                        bPaused = false;
                        runTime = 0;
                        mC.restart();
                }

                void Reset() {
                        mC.restart();
                        runTime = 0;
                        bPaused = false;
                }

                void Start() {
                        if (bPaused) {
                                mC.restart();
                        }
                        bPaused = false;
                }

                void Pause() {
                        if (!bPaused) {
                                runTime += mC.getElapsedTime().asSeconds();
                        }
                        bPaused = true;
                }

                float GetElapsedSeconds() {
                        if (!bPaused) {
                                return runTime + mC.getElapsedTime().asSeconds();
                        }
                        return runTime;
                }
        };
}

class GameState :
    public State
{
private:
    PauseMenu pmenu;
    WinState winState ;
    Board board ;
    st::Timer clock  ;
    Time t ;
    Text lblTime ;
    ostringstream ssTime ;
    map<string, Button* > buttons;
    Font font ;
    bool isUpdated  ;
    bool ok ;
    int sizeX , sizeY ;
    int numberOfBombs;
    void initFonts();
    void initButtons();

public:
    GameState(RenderWindow* app, stack<State*> *states ,int sizeX , int sizeY , int numberOfBombs);
    virtual ~GameState();
    // Functions
    void Reset() ;
    void updatePaused();
    void updateKeyBinds();
    void updateLeaderBoard() ;
    void updateButtons();
    void updateWinState() ;
    void updateLooseState() ;
    const bool& getLose() const ;
    const bool& getWin() const ;
    void endState() ;
    void update() ;
    void render(RenderTarget* target = NULL) ;
    void renderButtons(RenderTarget* target = NULL) ;

};
#endif


