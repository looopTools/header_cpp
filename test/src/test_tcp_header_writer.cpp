#include <header_cpp/protocols/tcp_header_writer.hpp>

#include <cstdint>

#include <gtest/gtest.h>

TEST(test_tcp_writer, tcp_writer_1)
{
    auto writer = header_cpp::protocols::tcp_header_writer();
    EXPECT_EQ(writer.data()[0], 0U);
    // Decimal value: 1347
    // Binary value: 0000 0101 0100 0011
    auto value = static_cast<uint16_t>(0x543);
    writer.source_port(value);
    EXPECT_EQ(writer.data()[0], value);

    value = static_cast<uint16_t>(0xFFFF);
    writer.destination_port(value);
    EXPECT_EQ(writer.data()[0], static_cast<uint32_t>(0xFFFF0543));

    auto value_2 = static_cast<uint32_t>(0x66366890);
    writer.sequence_number(value_2);
    EXPECT_EQ(writer.data()[1], value_2);

    assert(true);
}
