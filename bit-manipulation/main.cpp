#include <iostream>

#include "dump.h"

struct some_struct {
	uint8_t num_1{};
	uint8_t num_2{};
	uint8_t num_3{};
	uint8_t num_4{};
	uint8_t num_5{};
	uint8_t num_6{};
};

//constexpr utl::field_description some_struct_fields[] = {
//	{ "num_1", offsetof(some_struct, num_1), sizeof(uint32_t) },
//	{ "num_1", offsetof(some_struct, num_2), sizeof(uint32_t) }
//};

int main() {
	some_struct a{ 0x0F, 0x00, 0xFF, 0x00, 0xF0 };

	std::cout << utl::dump_bin(a) << std::endl;

	return 0;
}