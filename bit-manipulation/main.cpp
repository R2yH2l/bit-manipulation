#include <iostream>
#include <string>

struct alignas(uint32_t) some_struct {
	uint32_t num_1{};
	uint32_t num_2{};
};

template<typename T>
static inline std::string bits_to_string(const T& obj) {
	size_t size_in_bits{ sizeof(T) * 8 };
	size_t alignment_in_bits{ alignof(T) * 8 };

	std::string str{};

	for (size_t ind{}, grp{}, algn{}; ind < size_in_bits; ind++, grp++, algn++) {
		if (algn == alignment_in_bits) { algn = 0; str.push_back('\n'); }
		if (grp == 8) { grp = 0; str.push_back('-'); }
		str.push_back('0' + (obj >> ((size_in_bits - 1) - ind) & 0x1));
	}

	return str;
}

int main() {
	some_struct a{ 0xFF, 0xFF00 };

	std::cout << bits_to_string(a) << std::endl;

	return 0;
}