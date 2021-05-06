uniform sampler2D texture;

void main()
{
	vec2 uv = gl_TexCoord[0].xy;	
	vec4 col;
	float abbr = 0.0002;
	
	col.r = texture2D(texture, uv + abbr).r;
	col.g = texture2D(texture, uv).g;
	col.b = texture2D(texture, uv - abbr).b;
	col.a = texture2D(texture, uv).a;
	
	gl_FragColor = col;
}



