#include "cbuffer.h"
#include "vsoutput.h.hlsl"

////////////////////////////////////////////////////////////////////////////////
// Vertex Shader
////////////////////////////////////////////////////////////////////////////////
pos_only_vert_output debug_vert_main(a2v_pos_only a)
{
    pos_only_vert_output o;
	// Calculate the position of the vertex against the world, view, and projection matrices.
	float4 v = float4(a.inputPosition, 1.0f);
	v = mul(v, viewMatrix);
	o.pos = mul(v, projectionMatrix);

    return o;
}
