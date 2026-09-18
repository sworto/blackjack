#include "textureloader.hpp"

struct texture readbmp(std::string img){

    BMPFileHeader header;
    DIBInfoHeader info;

    std::ifstream file(img,std::ios::binary);
    if(!file){
        std::cout << "No File Present!!" << std::endl;
        return {};
    }

    file.read(reinterpret_cast<char*>(&header),sizeof(header));

    std::cout<< "Loaded Filetype: " << (char)header.type << std::endl;
    std::cout << "Size: " << (int) header.size << std::endl;
    std::cout << "Res1 and 2: " << (int) header.reserved1 <<" " << (int) header.reserved2 << std::endl;
    std::cout << "Offset: " <<  (int) header.pixelOffset << std::endl;

    std::cout << std::endl;

    file.read(reinterpret_cast<char*>(&info),sizeof(info));
    std::cout << "Size: " << (int)info.size << std::endl;
    std::cout << "Width: " << (int) info.width << std::endl;
    std::cout << "Height: " << (int) info.height << std::endl;

    texture t1;
    uint32_t val;
    t1.height=info.height;
    t1.width = info.width;

    file.seekg(header.pixelOffset,std::ios::beg);
    while(file.read(reinterpret_cast<char*>(&val),sizeof(val))){
        t1.buffer.push_back(val);
    }

    /*for(int i=0;i<t1.height;i++){
        for(int j=0;j<t1.width;j++){
            std::cout << std::hex << t1.buffer[i * t1.width + j] << " ";
        }
        std::cout << std::endl;
    }*/

    return t1;
}