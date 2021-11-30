#ifndef GameState_H
#define GameState_H
#include "State.h"
#include "Button.h"
#include "PauseMenu.h"
#include "WinState.h"
#include "LoseState.h"
#include "PlayAgainState.h"
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
    LoseState loseState ;
    PlayAgainState againState ;
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
<<<<<<< HEAD
    void saveBoard() ;
=======
>>>>>>> 438868f17b30c84ee8f10811305f447eb85a5ee1
    void updatePaused();
    void updateKeyBinds();
    void updateLeaderBoard() ;
    void updateButtons();
    void updateWinState() ;
    void updateLoseState() ;
    const bool& getLose() const ;
    const bool& getWin() const ;
    void endState() ;
    void update() ;
    void render(RenderTarget* target = NULL) ;
    void renderButtons(RenderTarget* target = NULL) ;

};
#endif


