#include <iostream>
using namespace std;
enum class Suits
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
};

enum class CardNames
{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
};

class Card
{
    public:
    CardNames name;
    Suits suit;
    int value;

    void PrintCard()
    {
        PrintValue();
        cout << " of ";
        PrintSuit();
        cout << endl;
    }

    void PrintValue()
    {
        if (name == CardNames::JACK)
        {
            cout << "jack";
        }
        else if (name == CardNames::QUEEN)
        {
            cout << "queen";
        }
        else if (name == CardNames::KING)
        {
            cout << "king";
        }
        else if (name == CardNames::ACE)
        {
            cout << "ace";
        }
        else
        {
            cout << value;
        }
    }

    void PrintSuit()
    {
        if (suit == Suits::CLUBS)
        {
            cout << "clubs";
        }
        else if (suit == Suits::DIAMONDS)
        {
            cout << "diamonds";
        }
        else if (suit == Suits::HEARTS)
        {
            cout << "hearts";
        }
        else if (suit == Suits::SPADES)
        {
            cout << "spades";
        }
    }
};

class Deck
{
    public:
    Card arrCards[52];

    void PrintAll()
    {
        for (int col = (int)Suits::CLUBS; col <= (int)Suits::SPADES; col++)
        {
            for (int row = (int)CardNames::ACE; row <= (int)CardNames::KING; row++)
            {
                int index = (13 * col) + row - 1;

                arrCards[index].PrintCard();
            }

            std::cout << std::endl;
        }
    }

    void SetupCards()
    {
        for (int col = (int)Suits::CLUBS; col <= (int)Suits::SPADES; col++)
        {
            for (int row = (int)CardNames::ACE; row <= (int)CardNames::KING; row++)
            {
                Card c;
                c.suit = (Suits)col;
                c.name = (CardNames)row;

                if (c.name == CardNames::JACK)
                {
                    c.value = 10;
                }
                else if (c.name == CardNames::QUEEN)
                {
                    c.value = 10;
                }
                else if (c.name == CardNames::KING)
                {
                    c.value = 10;
                }
                else
                {
                    c.value = (int)c.name;
                }
                int index = (13 * col) + row - 1;
                
                arrCards[index] = c;
            }
        }
    }
};

int main()
{
    Deck deck;
    deck.SetupCards();

    deck.PrintAll();
}