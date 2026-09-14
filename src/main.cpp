#include "logic.hpp"
int main(){
    std::vector<struct card> dealer;
    std::vector<struct card> player;
    //Dealer Move1:
    std::cout << "Dealer Deals himself: ";
    dealer.push_back(generatelog());
    std::cout<< cardvalue(dealer.back()) << std::endl;

    //Player Move1:
    std::cout << "Dealer Deals player: ";
    player.push_back(generatelog());
    std::cout<< cardvalue(player.back());
    player.push_back(generatelog());
    std::cout<< " and " <<cardvalue(player.back()) << std::endl;
    std::cout << "Dealer: " << handvalue(dealer) << " Player: " << handvalue(player) << std::endl;

    //Player Choice: 
    std::string choice;
    while(choice!="stand"){

        std::cout << "Enter Choice: ";
        std::cin >> choice;
        if(choice == "hit"){
            player.push_back(generatelog());
            std::cout << "Dealer deals player: " << cardvalue(player.back()) << std::endl;
            std::cout << "Player: " << handvalue(player) << std::endl;
        }

        if(handvalue(player)>21){
            std::cout << "Player Loses!!" << std::endl;
            return 0;
        }
        if(handvalue(player)==21){
            std::cout << "Jackpot!!" << std::endl;
            return 0;
        }
    }

    //Dealer Choice:
    while(true){
        std::cout << "Dealer: " << handvalue(dealer) << std::endl;

        std::cout << "Dealer Deals himself: ";
        dealer.push_back(generatelog());
        std::cout<< cardvalue(dealer.back()) << std::endl;
        std::cout << "Dealer: " << handvalue(dealer) << std::endl;

        while(handvalue(dealer)<16){
            std::cout << "Dealer Deals himself: ";
            dealer.push_back(generatelog());
            std::cout<< cardvalue(dealer.back()) << std::endl;
            std::cout << "Dealer: " << handvalue(dealer) << std::endl;

            if(handvalue(dealer)>21){
                std::cout << "Dealer Bust!!";
                return 0;
            }
        }
        if(handvalue(dealer)==16){
            std::cout << "Dealer Deals himself: ";
            dealer.push_back(generatelog());
            std::cout<< cardvalue(dealer.back()) << std::endl;
            std::cout << "Dealer: " << handvalue(dealer) << std::endl;

            if(handvalue(dealer)==21){
                std::cout << "Dealer Jackpot";
                return 0;
            }
            if(handvalue(dealer)>21){
                std::cout << "Dealer Bust!!";
                return 0;
            }
        }

        if(handvalue(dealer)>handvalue(player)){
            std::cout << "Dealer WINS" << std::endl;
            return 0;
        }
        else if(handvalue(dealer)<handvalue(player)){
            std::cout << "You WIN" << std::endl;
            return 0;
        }
        else{
            std::cout << "Tie!!" << std::endl;
            return 0;
        }
    }
    return 0;
}