struct PSInput
{
    float4 pos : SV_POSITION;
	
    float4 color : COLOR;
	
};

PSInput VSMain(float3 position : POSITION, float3 normal : NORMAL, float2 uv : TEXCOORD0)
{
    PSInput result;

    result.pos = float4(position, 1.0f);
	
    result.color = float4(0.9F, 0.8F, 0.3F, 1.0F);

    return result;
	
}

float4 PSMain(PSInput input) : SV_TARGET
{
    return input.color;
	
}