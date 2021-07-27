#version 330
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;

out vec3 vNormal;
out vec3 vFragPos;

uniform mat4 mvp;
uniform mat4 model;

void main()
{
  vFragPos = vec3(model * vec4(position, 1.0));
  vNormal = mat3(transpose(inverse(model))) * normal;

  gl_Position = mvp * vec4(vFragPos, 1.0);
}
