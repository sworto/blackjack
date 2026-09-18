#include <iostream>
#include <string>
#include <random>

struct card{
    int type;
    int weight;
};

struct card generatelog();

std::string cardvalue(struct card);

int handvalue(std::vector<struct card>);