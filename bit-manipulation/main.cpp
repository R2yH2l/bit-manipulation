#include <iostream>

#include "dump.h"

struct alignas(uint32_t) some_struct {
	uint32_t num_1{};
	uint32_t num_2{};
	char c{};
};

constexpr utl::field_description some_struct_fields[] = {
	{ "num_1", offsetof(some_struct, num_1), sizeof(uint32_t) },
	{ "num_1", offsetof(some_struct, num_2), sizeof(uint32_t) }
};

int main() {
	some_struct a{ 0x0F, 0xFF00 };

	std::cout << utl::dump_bin(a) << std::endl;

	return 0;
}