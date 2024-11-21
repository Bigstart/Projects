#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);



const char* vertexShaderSource = "#version 330 core\n"
	"layout (location = 0) in vec3 aPos;\n"
	"void main()\n"
	"{\n"
	"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	"}\0";

int main()
{
	// glfw: 初始化定义
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	// glfw 窗口创建
	// --------------------
	GLFWwindow* window = glfwCreateWindow(300, 300, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}




	// 定点输入
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};


	// 生成一个顶点缓冲对象（VBO）和一个顶点数组对象（VAO）
	unsigned int VBO;
	unsigned int VAO;

	// 创建缓冲对象
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	// -------------------- 配置 VAO 和 VBO --------------------

	// 绑定 VAO：
    // 绑定顶点数组对象，后续所有与顶点相关的设置（如顶点属性配置）都会记录到这个 VAO 中
	glBindVertexArray(VAO);

	// 绑定 VBO：
    // 绑定顶点缓冲对象，将顶点数据传输到 GPU
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// 为 VBO 分配内存并传递顶点数据：
    // GL_ARRAY_BUFFER 表示缓冲类型是顶点缓冲，vertices 是顶点数据数组
    // GL_STATIC_DRAW 表示数据不会频繁修改，主要用于绘制操作
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// 配置顶点属性解析方式：
    // 告诉 OpenGL 如何解析缓冲中的顶点数据
	glVertexAttribPointer(
		0,                 // 顶点属性索引（location = 0）
		3,                 // 每个顶点包含 3 个值（x, y, z 坐标）
		GL_FLOAT,          // 数据类型为 float
		GL_FALSE,          // 不需要标准化
		3 * sizeof(float), // 每个顶点数据的步长（每个顶点包含 3 个 float）
		(void*)0           // 数据起始位置偏移量（从缓冲开头开始）
	);

	// 激活顶点属性：
    // 启用顶点属性索引 0，对应的解析方式为上面配置的 glVertexAttribPointer()
	glEnableVertexAttribArray(0);

	// -------------------- 配置完成后，解绑 VAO 和 VBO --------------------

	// 解绑 VAO：防止后续误操作
	glBindVertexArray(0);

	// 解绑 VBO：解绑当前缓冲对象，防止后续代码意外修改它
	glBindBuffer(GL_ARRAY_BUFFER, 0);




	// 创建顶点着色器对象
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// 着色器源码附加到着色器对象上，然后编译它
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	// 检查编译
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}



	// 创建片段着色器对象
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAG::COMPILATION_FAILED\n" << infoLog << std::endl;
	}


	// 着色器程序
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::shaderProgram\n" << infoLog << std::endl;
	}
	glUseProgram(shaderProgram);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);



	


	// 渲染循环
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		// input
		// -----
		processInput(window);


		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);



		// 在渲染循环中：
        // 只需要绑定 VAO，它会自动绑定 VBO 并恢复之前配置的顶点属性
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);  // 绘制三角形
		glBindVertexArray(0);              // 解绑 VAO

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}



	// glfw: 结束渲染释放资源
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}