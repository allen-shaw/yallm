#pragma once

#include "json.hpp"

#include <array>
#include <cstddef>
#include <string>

enum class DType {
	F32,
	F16,
	BF16,
	F8E5M2,
	F8E4M3,
	I32,
	I16,
	I8,
	U8,
};

struct Tensor {
	std::string name;
	DType dtype;
	std::array<int, 4> shape = {0, 0, 0, 0};
	void* data = nullptr;
	size_t size;

	int from_json(
	    const std::string& name,
	    const json& json_obj,
	    void* bytes_ptr,
	    size_t bytes_size);
};