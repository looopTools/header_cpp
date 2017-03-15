#pragma once

#include <cstdint>
#include <cassert>
#include <vector>

#include <bitter/reader.hpp>

namespace header_cpp
{
class tcp_header_reader
{
public:
    tcp_header_reader(std::vector<uint32_t> data);
    ~tcp_header_reader();

    uint16_t source_port() const;
    uint16_t destination_port();
    uint32_t sequence_number();
    uint32_t acknowledgement_number();
    uint8_t data_offset();
    uint8_t reserved(); // Return 0;
    boolean urgent();
    boolean acknowledgement();
    boolean reset();
    boolean synchronize();
    boolean fin();
    uint16_t window();
    uint16_t checksum();
    uint16_t urgent_pointer();
    uint32_t options();
    uint8_t padding();

private:
    std::vector<uint32_t> m_data;
    bitter::reader<uint32_t, 16, 16> m_first_row;
    bitter::reader<uint32_t, 32> m_second_row; // redo to just uint32_t
    bitter::reader<uint32_t, 32> m_third_row; // redo to just uint32_t
    bitter::reader<uint32_t, 4, 6, 1, 1, 1 , 1 , 1, 1, 16> m_fourth_row;
    bitter::reader<uint32_t, 16, 16> m_fifth_row;
    bitter::reader<uint32_t, 24, 8> m_sixth_row;
};
}
