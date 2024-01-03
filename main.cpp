#include <iostream>
#include <conio.h>
#include <windows.h>

const int width = 40;
const int height = 20;
int ballX, ballY, paddle1, paddle2;
int ballDirX, ballDirY;
bool gameRunning;
enum eDir { STOP = 0, LEFT, RIGHT, UPLEFT, UPRIGHT, DOWNLEFT, DOWNRIGHT };
eDir ballDir;

void Setup() {
    gameRunning = true;
    ballX = width / 2;
    ballY = height / 2;
    ballDir = STOP;
    ballDirX = -1;
    ballDirY = 0;
    paddle1 = height / 2 - 2;
    paddle2 = height / 2 - 2;
}

void Draw() {
    system("cls");

    for (int i = 0; i < width + 2; i++)
        std::cout << "#";
    std::cout << std::endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                std::cout << "#";
            if (i == ballY && j == ballX)
                std::cout << "O";
            else if (i >= paddle1 && i < paddle1 + 4 && j == 0)
                std::cout << "|";
            else if (i >= paddle2 && i < paddle2 + 4 && j == width - 1)
                std::cout << "|";
            else
                std::cout << " ";
            if (j == width - 1)
                std::cout << "#";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < width + 2; i++)
        std::cout << "#";
    std::cout << std::endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w':
                if (paddle1 > 0)
                    paddle1--;
                break;
            case 's':
                if (paddle1 < height - 4)
                    paddle1++;
                break;
            case 'i':
                if (paddle2 > 0)
                    paddle2--;
                break;
            case 'k':
                if (paddle2 < height - 4)
                    paddle2++;
                break;
            case 'p':
                gameRunning = false;
                break;
        }
    }
}


void Logic() {
    switch (ballDir) {
        case UPLEFT:
            ballDirX = -1;
            ballDirY = -1;
            break;
        case DOWNLEFT:
            ballDirX = -1;
            ballDirY = 1;
            break;
        case UPRIGHT:
            ballDirX = 1;
            ballDirY = -1;
            break;
        case DOWNRIGHT:
            ballDirX = 1;
            ballDirY = 1;
            break;
        default:
            break;
    }

    ballX += ballDirX;
    ballY += ballDirY;

    if (ballY <= 0 || ballY >= height - 1)
        ballDirY = -ballDirY;

    if (ballX <= 0)
        ballDirX = -ballDirX;

    if (ballX >= width - 1)
        ballDirX = -ballDirX;

    if (ballX == 1 && ballY >= paddle1 && ballY < paddle1 + 4)
        ballDir = UPRIGHT;

    if (ballX == width - 2 && ballY >= paddle2 && ballY < paddle2 + 4)
        ballDir = UPLEFT;

    if (ballX == 0 || ballX == width - 1)
        ballDir = STOP;

    if (ballY == 0 || ballY == height - 1)
        ballDir = STOP;
}

int main() {
    Setup();

    while (gameRunning) {
        Draw();
        Input();
        Logic();
        Sleep(150);
    }

    return 0;
}