#include "logic.hpp"

int handvalue(std::vector<struct card> hand){
    int aces = 0;
    int value = 0;
    for(auto a: hand){
        if(a.weight == 1){
            aces++;
            value+=11;
        }
        if(a.weight == 11 || a.weight == 12 || a.weight == 13){
            value+=10;
        }
        else{
            value+=a.weight;
        }
    }
    while(value>21&&aces>0){
        value-=10;
        aces--;
    }
    return value;
}

struct card generatelog(){
    struct card c;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1,4);
    //Class <Spade: 1, Club: 2, Diamond 3, Heart 4>
    c.type = dist(gen);
    //Name: 
    dist = std::uniform_int_distribution<int>(1,13);
    c.weight = dist(gen);
    return c;
}

std::string cardvalue(struct card c){
    std::string ret;
    switch(c.weight){
        case 1:
            ret+="Ace ";
            break;
        case 2:
            ret+="Two ";
            break;
        case 3:
            ret+="Three ";
            break;
        case 4:
            ret+="Four ";
            break;
        case 5:
            ret+="Five ";
            break;
        case 6:
            ret+="Six ";
            break;
        case 7:
            ret+="Seven ";
            break;
        case 8:
            ret+="Eight ";
            break;
        case 9:
            ret+="Nine ";
            break;
        case 10:
            ret+="Ten ";
            break;
        case 11:
            ret+="Jack ";
            break;
        case 12:
            ret+="Queen ";
            break;
        case 13:
            ret+="King ";
            break;
        
    }

    ret+="of";

    switch(c.type){
        case 1:
            ret+=" Spades";
            break;
        case 2:
            ret+=" Clubs";
            break;
        case 3:
            ret+=" Diamonds";
            break;
        case 4:
            ret+=" Hearts";
            break;
    }

    return ret;
}