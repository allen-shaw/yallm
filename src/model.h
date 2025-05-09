#pragma once

#include "codec.h"

#include <memory>
#include <vector>

enum class LayerNormType {
	RMSNorm,
};

struct Config {
	int dim;

	LayerNormType norm_type;
	DType weight_dtype;
};

class InferenceState {
public:
	InferenceState(const std::shared_ptr<Config> config);
	~InferenceState();
};

class Block {
public:
	Block(
	    int layer_i,
	    const std::shared_ptr<Config> config);
	~Block();

	void block(InferenceState& s) const;
};

class Model {
public:
	void forward(InferenceState& s, int token);

private:
	void _forward_cpu(InferenceState& s, int token);
	void _copy_embedding(InferenceState& s, int token);

private:
	std::shared_ptr<Config> _config;
	std::vector<std::shared_ptr<Block>> _blocks;
};
