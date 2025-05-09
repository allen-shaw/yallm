#include "codec.h"
#include "model.h"
#include <cassert>

static void rmsnorm() {
}

void Model::_forward_cpu(InferenceState& s, int token) {
	const Config& c = *_config;

	for (auto b : _blocks) {
		b->block(s);
	}

	switch (c.norm_type) {
	case LayerNormType::RMSNorm: {
		rmsnorm();
		break;
	}
	}
}

void Model::_copy_embedding(InferenceState& s, int token) {
	const Config& c = *_config;
	switch (c.weight_dtype) {
	case DType::F32: {

		break;
	}
	case DType::F16: {

		break;
	}
	default: {
		assert(false && "unsupported weight dtype");
	}
	}
}
