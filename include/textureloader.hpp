#include <fstream>
#include <iostream>
#include <cstdint>
#include <vector>

#define TEXTUREWIDTH 50
#define TEXTUREHEIGHT 50

#pragma pack(push,1)
struct texture{
    int width;
    int height;
    std::vector<uint32_t> buffer;
};

struct BMPFileHeader{
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t pixelOffset;
};

struct DIBInfoHeader{
    uint32_t size;
    int32_t  width;
    int32_t  height;
};
#pragma pack(pop)

struct texture readbmp(std::string img);