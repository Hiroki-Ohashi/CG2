#include "object3d.hlsli"

struct Material {
	float32_t4 color;
	int32_t enableLighting;
	float32_t4x4 uvTransform;
	float32_t shininess;
};
struct DirectionalLight {
	float32_t4 color;
	float32_t3 direction;
	float intensity;
};

struct Camera
{
	float32_t3 worldPosition;
};

ConstantBuffer<Material> gMaterial : register(b0);
ConstantBuffer<DirectionalLight> gDirectionalLight : register(b1);
ConstantBuffer<Camera> gCamera : register(b2);
Texture2D<float32_t4> gTexture : register(t0);
SamplerState gSampler : register(s0);

struct PixelShaderOutput {
	float32_t4 color : SV_TARGET0;
};

PixelShaderOutput main(VertexShaderOutput input) {
	PixelShaderOutput output;
	/*float32_t4 textureColor = gTexture.Sample(gSampler, input.texcoord);*/
	
	float4 transformeduv = mul(float32_t4(input.texcoord, 0.0f, 1.0f), gMaterial.uvTransform);
	float32_t4 textureColor = gTexture.Sample(gSampler, transformeduv.xy);

	if (gMaterial.enableLighting != 0) {
		// half lambert
		float NdotL =dot(normalize(input.normal), -gDirectionalLight.direction);
		//float NdotL = saturate(dot(normalize(input.normal), -gDirectionalLight.direction));
		float cos = pow(NdotL * 0.5f + 0.5f, 2.0f);

		float32_t3 toEye = normalize(gCamera.worldPosition - input.worldPosition);
		float32_t3 reflectLight = reflect(gDirectionalLight.direction, normalize(input.normal));
		
		float RDotE = dot(reflectLight, toEye);
		float specularPow = pow(saturate(RDotE), gMaterial.shininess); // 反射強度

		// 拡散反射
		float32_t3 diffuse = gMaterial.color.rgb * textureColor.rgb * gDirectionalLight.color.rgb * cos * gDirectionalLight.intensity;
		// 鏡面反射
		float32_t3 specular = gDirectionalLight.color.rgb * gDirectionalLight.intensity * specularPow * float32_t3(1.0f, 1.0f, 1.0f);

		output.color.rgb = diffuse + specular;
		output.color.a = gMaterial.color.a * textureColor.a;
	}
	else {
		output.color = gMaterial.color * textureColor;
	}

	return output;
}