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
    uint16_t destination_port() const;
    uint32_t sequence_number() const;
    uint32_t acknowledgement_number() const;
    uint8_t data_offset() const;
    uint8_t reserved() const; // Return 0;
    bool urgent() const;
    bool acknowledgement() const;
    bool push() const;
    bool reset() const;
    bool synchronize() const;
    bool fin() const;
    uint16_t window() const;
    uint16_t checksum() const;
    uint16_t urgent_pointer() const;
    uint32_t options() const;
    uint8_t padding() const;

private:
    std::vector<uint32_t> m_data;
    bitter::reader<uint32_t, 16, 16> m_first_row;
    uint32_t m_second_row;
    uint32_t m_third_row;
    bitter::reader<uint32_t, 4, 6, 1, 1, 1, 1, 1, 1, 16> m_fourth_row;
    bitter::reader<uint32_t, 16, 16> m_fifth_row;
    bitter::reader<uint32_t, 24, 8> m_sixth_row;
};
}
