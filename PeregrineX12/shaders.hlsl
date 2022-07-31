
float4x4 world_transform;

float4x4 view_transform;

float4x4 projection_transform;

float3 camera_location;


struct PSInput
{
    float4 pos : SV_POSITION;
	
	float3 norm : TEXCOORD0;
    
	float3 dir_view : TEXCOORD1;
		
	float4 dir_light : TEXCOORD2;
	
};


struct PointLight
{
	float3 light_location;
       
	float4 amb_color;
	float amb_intensity;
       
	float4 diff_color;
	float diff_intensity;
       
	float4 spec_color;
	float spec_intensity;
	   
};

PointLight oLight;


PSInput VSMain(float3 position : POSITION, float3 normal : NORMAL, float2 uv : TEXCOORD0)
{
    PSInput result;
	

    float4 world = mul(position, world_transform);
	
    float4 view = mul(world, view_transform);
	
    result.pos = mul(view, projection_transform);


    result.norm = mul(normalize(normal), world_transform);


    result.dir_light = -(float4(oLight.light_location, 1.0f) - world);


    result.dir_view = float4(camera_location, 1.0f) - world;


    return result;
	
}


float4 PSMain(PSInput input) : SV_TARGET
{
       float4 ps_normal = float4(normalize(input.norm), 1.0f);


       float3 ps_view_dir = normalize(input.dir_view);


       float3 ps_light_dir = normalize(input.dir_light);


       float ps_diff = saturate(dot(ps_normal, -ps_light_dir));


       float4 ps_reflect = normalize(2*ps_diff*ps_normal - float4(ps_light_dir, 1.0f));


       float4 ps_spec = pow(saturate(dot(ps_reflect, ps_view_dir)), 256);


       if (ps_diff <= 0.0f) ps_spec = 0.0f;


       float4 ps_amb_color = oLight.amb_color * oLight.amb_intensity;


       float4 ps_diff_color = oLight.diff_color * oLight.diff_intensity * ps_diff;


       float4 ps_spec_color = (oLight.spec_color * oLight.spec_intensity) * ps_spec;


       return ps_amb_color + ps_diff_color + ps_spec_color;
	
}