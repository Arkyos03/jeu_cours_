#include <iostream>
#include <string>

int main() {
    char start;
    std::cout << "          {--------------}" << std::endl;
    std::cout << "          {---Bienvenue--}" << std::endl;
    std::cout << "          {--------------}" << std::endl;

    bool validResponse = false;

    while (!validResponse) {
        std::cout << "Voulez-vous jouer ? Tapez 'y' pour jouer, sinon 'n' : ";
        std::cin >> start;

        if (start == 'y' || start == 'Y' || start == 'n' || start == 'N') {
            validResponse = true;
        } else {
            std::cout << "Merci de taper 'y' ou 'n'." << std::endl;
        }
    }

    if (start == 'y' || start == 'Y') {
        std::cout << "Jouons alors !!" << std::endl;
    } else {
        std::cout << "Dommage;)." << std::endl;
    }

    return 0;
}


