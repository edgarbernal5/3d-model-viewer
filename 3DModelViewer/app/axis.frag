#version 330

in highp vec3 vColor;
out highp vec4 fColor;

void main(void)
{
    fColor = vec4(vColor, 1.0);
}
