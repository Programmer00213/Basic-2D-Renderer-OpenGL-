#version 330 core

uniform sampler2D texture1;
uniform sampler2D texture2;
out vec4 FragColor;

in vec3 Color;
in vec2 TextCoor;

void main()
{
FragColor = mix(texture(texture1, TextCoor) * vec4(Color,1), texture(texture2, TextCoor), 0.1);
}