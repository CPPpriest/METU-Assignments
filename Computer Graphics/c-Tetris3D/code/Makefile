all:
	g++ -std=c++17 main.cpp -o tetrisGL -g -lglfw -lpng16 -lpthread -ldl -lGLEW \
	-framework OpenGL \
	-DGL_SILENCE_DEPRECATION -DGLM_ENABLE_EXPERIMENTAL \
	-I/opt/homebrew/opt/glew/include \
	-I/opt/homebrew/Cellar/glfw/3.4/include \
	-I/opt/homebrew/opt/glm/include \
	-I/opt/homebrew/opt/libpng/include \
	-L/opt/homebrew/opt/glew/lib \
	-L/opt/homebrew/Cellar/glfw/3.4/lib \
	-L/opt/homebrew/opt/libpng/lib `pkg-config --cflags --libs freetype2`