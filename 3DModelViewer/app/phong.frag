#version 330
uniform vec3 vBaseColor;
uniform vec3 vAmbientColor;
uniform vec3 vDiffuseColor;
uniform vec3 vSpecularColor;

uniform vec3 vLightColor;
uniform vec3 vLightPos;
uniform vec3 vViewPos;
uniform float shininess;

in highp vec3 vNormal;
in highp vec3 vFragPos;
out highp vec4 fColor;

void main()
{
    // ambient
    vec3 ambient = vAmbientColor;

    // diffuse
    vec3 norm = normalize(vNormal);
    vec3 lightDir = normalize(vLightPos - vFragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = vLightColor* (diff * vDiffuseColor);

    // specular
    vec3 viewDir = normalize(vViewPos - vFragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 specular = (spec * vSpecularColor);

    vec3 result = ambient + diffuse + specular;
    fColor = vec4(result, 1.0);
}
