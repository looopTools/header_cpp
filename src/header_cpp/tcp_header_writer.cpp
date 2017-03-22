#include "tcp_header_writer.hpp"

#include <cassert>

namespace header_cpp
{
    tcp_header_writer::tcp_header_writer()
    {

    }

    tcp_header_writer::~tcp_header_writer()
    {

    }

    void tcp_header_writer::source_port(const uint16_t value)
    {
        m_first_row.field<0>(value);
    }

    void tcp_header_writer::destination_port(const uint16_t value)
    {
        m_first_row.field<1>(value);
    }

    void tcp_header_writer::sequence_number(const uint32_t value)
    {
        m_second_row = value;
    }

    void tcp_header_writer::acknowledgement_number(const uint32_t value)
    {
        m_third_row = value;
    }

    void tcp_header_writer::data_offset(const uint8_t value)
    {
        assert(value <= 15);
        m_fourth_row.field<0>(value);
    }

    void tcp_header_writer::reserved()
    {
        m_fourth_row.field<1>(0U);
    }

    void tcp_header_writer::urgent(const bool value)
    {
        m_fourth_row.field<2>(value);
    }

    void tcp_header_writer::acknowledgement(const bool value)
    {
        m_fourth_row.field<3>(value);
    }

    void tcp_header_writer::push(const bool value)
    {
        m_fourth_row.field<4>(value);
    }

    void tcp_header_writer::reset(const bool value)
    {
        m_fourth_row.field<5>(value);
    }

    void tcp_header_writer::synchronize(const bool value)
    {
        m_fourth_row.field<6>(value);
    }

    void tcp_header_writer::fin(const bool value)
    {
        m_fourth_row.field<7>(value);
    }

    void tcp_header_writer::window(const uint16_t value)
    {
        m_fourth_row.field<8>(value);
    }

    void tcp_header_writer::checksum(const uint16_t value)
    {
        m_fifth_row.field<0>(value);
    }

    void tcp_header_writer::urgent_pointer(const uint16_t value)
    {
        m_fifth_row.field<1>(value);
    }

    // TODO add check that value is <= to max value of 2^24!
    void tcp_header_writer::options(const uint32_t value)
    {
        m_sixth_row.field<0>(value);
    }

    void tcp_header_writer::padding(const uint8_t value)
    {
        m_sixth_row.field<1>(value);
    }

    std::vector<uint32_t> tcp_header_writer::data()
    {
        std::vector<uint32_t> temp;
        temp.reserve(6);
        temp[0] = m_first_row.data();
        temp[1] = m_second_row;
        temp[2] = m_third_row;
        temp[3] = m_fourth_row.data();
        temp[4] = m_fifth_row.data();
        temp[5] = m_sixth_row.data();
        return temp;

    }
}
