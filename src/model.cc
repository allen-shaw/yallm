#include "model.h"

void Model::forward(InferenceState& s, int token) {
	_forward_cpu(s, token);
}