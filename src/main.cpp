#include <SFML/Graphics.hpp>
#include <iostream>



// 1 = pawn
// 2 = rook
// 3 = knight

// 5 = bishop
// 6 = queen
// 7 = king


int main()
{   
    
    int TileSize = 100;
    int BoardSize = 8;
    sf::RenderWindow window(sf::VideoMode({static_cast<unsigned int>(TileSize*BoardSize),
                                           static_cast<unsigned int>(TileSize*BoardSize) }), "Chess");

    sf::RectangleShape square(sf::Vector2f(100.f,100.f));
    


    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        //Rendering the board
    bool odd;

    for (int x = 0; x < BoardSize; ++x)
    {
        odd = (x % 2 == 1);

        for (int y = 0; y < BoardSize; ++y)
        {
            square.setPosition(sf::Vector2f(x * TileSize, y * TileSize));

            if (odd)
            {
                square.setFillColor(sf::Color::White);
            }
            else
            {
                square.setFillColor(sf::Color::Black);
            }

            window.draw(square);

            odd = !odd;
            }
        }
            window.display();
    }

    return 0;
}
