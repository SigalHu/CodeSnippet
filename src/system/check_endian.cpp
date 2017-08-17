union Endian{
    short data;
    char byte[2];
};

bool is_little_endian(){
    Endian endian;
    endian.data = 1;
    return endian.byte[0] == 1;
}