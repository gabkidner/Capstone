#include <iostream>
#include "Completed/Die.h"
#include "Completed/TicTacToe.h"
#include "Completed/ChooseAdventure.h"
#include "Completed/GuessNumber.h"
#include "Completed/GuessYourNumber.h"
#include "Completed/Simon.h"
#include "Completed/TileGame.h"
using namespace std;

void die();
void tictac();
void complete();
void incomplete();
void adventure();
void playerguesses();
void compGuess();
void simon();
void tile();

int main() {
    int input;
    string temp;
    cout << "Welcome to my Capstone Project\n[Blank] games in one\nThere are games I have completed and games I haven't" << endl;
    do {
        cout << "\nWould you like to do complete or incomplete games?\n0 - Exit\n1 - Complete\n2 - Incomplete" << endl;
        cin >> input;
        switch (input) {
        case 0: break;
        case 1: complete(); break;
        case 2: incomplete(); break;
        //case 3: testing(); break;
        }
    } while (input != 0);
    system("cls");
    return 0;
}

void complete() {
    int input;
    string temp;
    do {
        system("cls");
        cout << "Select Game and Press Enter\n0 - Main Menu\n1 - Dice\n2 - Tic Tac Toe\n3 - Choose Your Own Adventure\n4 - Guess the Computer's Number\n5 - Computer Guesses\n6 - Simeon Says\n7 - Tile Game" << endl;
        cin >> input;
        switch (input) {
            case 0: break;
            case 1: die(); break;
            case 2: tictac(); break;
            case 3: adventure(); break;
            case 4: playerguesses(); break;
            case 5: compGuess(); break;
            case 6: simon(); break;
            case 7: tile(); break;
        }
    } while (input != 0);
    system("cls");
}

void incomplete() {
    cout << "Goodbye" << endl;
}

void die() {
    system("cls");
    int user = 99;
    do {
        int sides, rolls;
        cout << "How many sides should this die/coin have?\n";
        cin >> sides;
        cout << "\nHow many times should I roll this " << sides << " sided die?" << endl;
        cin >> rolls;
        Die die(sides, rolls);
        die.roll();
        system("cls");
        cout << die << "\nSelect an option and Press Enter\n0 - Main Menu\n1 - Roll Again" << endl;
        cin >> user;
    } while (user != 0);
    system("cls");
}

void tictac() {
    system("cls");
    int choiceInt;
    char choiceChar;
    TicTacToe tic;
    while (tic.won() == 0) {
        tic.switchPlayer();
        system("cls");
        cout << tic << "\n" << tic.get() << "'s turn\n";
        cin >> choiceInt;
        while (choiceInt > 9) {
            cout << "Please enter a valid number\n";
            cin >> choiceInt;
        }
        choiceChar = choiceInt + 48;
        tic.place(choiceChar);
    }
    cout << tic << endl;
    if (tic.won() == 1) {
        cout << tic.get() << "'s win";
    }
    else {
        cout << "Neither of you won, you are equals" << endl;
    }
}

void adventure() {
    system("cls");
    ChooseAdventure adv;
    char user;
    while (adv.stop() != true) {
        adv.printStory();
        do {
            cin >> user;
        } while (user != '1' && user != '2' && user != '3');
        adv.advancePhase(user);
    }
}

void playerguesses(){
    GuessNumber game;
    system("cls");
    int user, result;
    cout << "I have thought of a number and you must guess it by inputing a number and pressing enter.\nI will tell you if you are higher or lower and you will have 10 tries, what if your first guess.\n";
    do {
        cin >> user;
        system("cls");
        result = game.result(user);
        game.add(user);
        if (result == 3) {
            cout << "Lower" << endl;
        }
        else if (result == 2) {
            cout << "Higher" << endl;
        }
    } while (result != 0 && result != 1);
    if (result == 0) {
        cout << "Pitiful human you thought you could best me? press 1 if you want to be bested again or 0 if you want to leave" << endl;
    }
    else {
        cout << "How could this be!? how could I be bested by a feeble human. press 1 so I can best you in a rematch, or 0 to leave and try something else." << endl;
    }
    cout << endl;
    cin >> user;
    while (user != 1 && user != 0){
        cout << "1 - Rematch\n2 - Exit" << endl; 
    }
}

void compGuess() {
    GuessYourNumber game;
    string user;
    int input;
    int result;
    system("cls");
    cout << "Think of a number from 1 to 100 and I will try to guess it in 10 tries.\n";
    do {
        game.guessing();
        do {
            cout << game;
            cin >> user;
        } while (user != "low" && user != "high" && user != "correct");
        game.editGuess(user);
        result = game.complete(user);
    } while (result == 0);
    system("cls");
    switch (result) {
    case 1: cout << "I knew it! Humans are so predictable and it took me " << game.getTries() << " tries" << endl; break;
    case 2: cout << "How could you outsmart me! you must have cheated!" << endl; break;
    }
    do {
        cout << "1 - Rematch\n0 - Main Menu" << endl;
        cin >> input;
        system("cls");
    } while (input != 1 && input != 0);
    if (input == 1) {
        compGuess();
    }
}

void simon() {
    system("cls");
    int game = 0;
    int user = 0;
    int iterations = 0;
    string choice;
    Simon s;
    cout << "This is a simple game of simon, a series of the letters 'g', 'r', 'y', and 'b' while flash on screen. After they flash you will need to type the letters in the same order as you saw them and keep going until you mess up.\nType '1' and press Enter to start" << endl;
    do {
        int loop = 50;
        if (game != 0) {
            s.newPattern();
        }
        while (loop != 0) {
            system("cls");
            cout << s;
            loop--;
        }
        system("cls");
        cout << "Input Letters:" << endl;
        cin >> choice;
        game++;
        iterations++;
    } while (!s.done(choice));
    iterations--;
    do {
        cout << "Good Job you got through " << iterations << " rounds\n1-Try Again\n0-Main Menu" << endl;
        cin >> user;
        system("cls");
    } while (user != 1 && user != 0);
    if (user == 1) {
        simon();
    }
}

void tile() {
    TileGame game;
    int choice = 0, chances = 0;
    do {
        if (choice != 4) {
            system("cls");
        }
        cout << game << "\n0 - Quit\n1 - Shift Right\n2 - Shift Left\n3 - Swap\n4 - Rules\nChoose one: ";
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1: game.moveRight(); break;
        case 2: game.moveLeft(); break;
        case 3: game.swap(); break;
        case 4: cout << "In this game the goal is to get all of the numbers in order with the blank space acting as zero. You can move the blank space left and right and switch the numbers either side of the space. You will have a total of 50 moves to complete the puzzle, good luck.\n"; break;
        }
        if (choice != 4) {
            system("cls");
            chances++;
        }
    } while (!game.inOrder() && choice > 0 && chances < 50);
    if (chances == 30) {
        cout << "You ran out of chances\n" << endl;
    }
    if (game.inOrder() && chances < 50) {
        system("cls");
        cout << game << "\nCongrats You Won!!!!!" << endl;
    }
    do {
        cout << "1-Try Again\n0-Main Menu" << endl;
        cin >> choice;
        system("cls");
    } while (choice != 1 && choice != 0);
    if (choice == 1) {
        tile();
    }
}