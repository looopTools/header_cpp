#include <header_cpp/tcp_header_writer.hpp>

#include <cassert>
#include <cstdint>


int main()
{

    // Define the tcp_writer
    auto tcp_writer = header_cpp::tcp_header_writer();

    // Define the source port and write it to its correct
    // place in the header
    // 128 in 16bit: 0000 0000 1000 0000
    uint16_t source_port = 128U;
    tcp_writer.source_port(source_port);
    assert(tcp_writer.data()[0] == 128);

    // 234 in 16bit: 0000 0000 1110 1110
    uint16_t destination_port = 234U;
    tcp_writer.destination_port(destination_port);

    // Due to underlying implementation the source and destination port
    // are written in the same unit32_t value in tcp_writers data
    // We therefore expect the following result:
    // result in 32bit: 0000 0000 1110 1110 0000 0000 1000 0000
    assert(tcp_writer.data()[0] == 15597696U);




    return 0;
}
