#include <SFML/Graphics.hpp>
#include "include/game.h"

int main()
{

    Game game{};
    game.show_splash_screen();
    game.setup();


    while (game.window.isOpen())
    {
        while (const std::optional event = game.window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                game.window.close();
        }

        game.update();
        game.draw();
    }


}
